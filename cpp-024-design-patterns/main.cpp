/*

*/

#include <iostream>
#include <vector>

#ifndef EXIT_SUCCESS
 #define EXIT_SUCCESS 0u
#endif

/*
Design patterns in C++ are reusable solutions to common problems in software design. 
They provide best practices for object-oriented design and help make code more flexible, 
reusable, and maintainable. Below is an overview of key design patterns categorized into 
Creational, Structural, and Behavioral patterns, with C++ examples.
*/
/*
1. Creational Patterns
These deal with object creation mechanisms.
*/
/*
(a) Singleton
Ensures a class has only one instance and provides a global point of access.
*/
class Singleton 
{
public:
    static Singleton& getInstance() {
        static Singleton instance; // Guaranteed to be destroyed.
                                   // Instantiated on first use.
        return instance;
    }
private:
    Singleton() {} // Constructor? (the {} brackets) are needed here.
    // C++ 11
    // We can use the better technique of deleting the methods
    // we don't want.
    Singleton(Singleton const&) = delete;
    void operator=(Singleton const&) = delete;
};

/*
(b) Factory Method
Defines an interface for creating objects but lets subclasses decide which class to instantiate.
*/
class Product {
public:
    virtual void use() = 0;
    virtual ~Product() {}
};

class ConcreteProductA : public Product {
public:
    void use() override {
        std::cout << "Using ConcreteProductA" << std::endl;
    }
};

class ConcreteProductB : public Product {
public:
    void use() override {
        std::cout << "Using ConcreteProductB" << std::endl;
    }
};

class Creator {
public:
    virtual Product* factoryMethod() = 0;
    virtual ~Creator() {}
};

class ConcreteCreatorA : public Creator {
public:
    Product* factoryMethod() override {
        return new ConcreteProductA();
    }
};

class ConcreteCreatorB : public Creator {
public:
    Product* factoryMethod() override {
        return new ConcreteProductB();
    }
};

/*
(c) Abstract Factory
Provides an interface for creating families of related objects without specifying concrete classes.
*/
class AbstractProductA {
public:
    virtual void use() = 0;
    virtual ~AbstractProductA() {} 
};

class AbstractProductB {
public:
    virtual void use() = 0;
    virtual ~AbstractProductB() {}
};

class ConcreteProductA1 : public AbstractProductA {
public:
    void use() override {
        std::cout << "Using ConcreteProductA1" << std::endl;
    }
};

class ConcreteProductA2 : public AbstractProductA {
public:
    void use() override {
        std::cout << "Using ConcreteProductA2" << std::endl;
    }
};

class ConcreteProductB1 : public AbstractProductB {
public:
    void use() override {
        std::cout << "Using ConcreteProductB1" << std::endl;
    }
};

class ConcreteProductB2 : public AbstractProductB {
public:
    void use() override {
        std::cout << "Using ConcreteProductB2" << std::endl;
    }
};

class AbstractFactory {
public:
    virtual AbstractProductA* createProductA() = 0;
    virtual AbstractProductB* createProductB() = 0;
    virtual ~AbstractFactory() {}
};

class ConcreteFactory1 : public AbstractFactory {
public:
    AbstractProductA* createProductA() override {
        return new ConcreteProductA1();
    }
    AbstractProductB* createProductB() override {
        return new ConcreteProductB1();
    }
};

class ConcreteFactory2 : public AbstractFactory {
public:
    AbstractProductA* createProductA() override {
        return new ConcreteProductA2();
    }
    AbstractProductB* createProductB() override {
        return new ConcreteProductB2();
    }
};

/*
e) Prototype
Creates new objects by copying an existing object (cloning).
*/
class Prototype {
public:
    virtual Prototype* clone() const = 0;
    virtual void use() = 0;
    virtual ~Prototype() {}
};

class ConcretePrototype : public Prototype {
public:
    ConcretePrototype(int value) : value(value) {}
    Prototype* clone() const override {
        return new ConcretePrototype(*this);
    }
    void use() override {
        std::cout << "Using ConcretePrototype with value: " << value << std::endl;
    }
private:
    int value;
}; 

/*
2. Structural Patterns
These deal with object composition and relationships.
*/
/*
(a) Adapter
Allows incompatible interfaces to work together.
*/
// Legacy Rectangle (incompatible)
class LegacyRectangle {
public:
    void draw(int x1, int y1, int x2, int y2) {
        std::cout << "Drawing rectangle from (" << x1 << "," << y1 << ") to (" << x2 << "," << y2 << ")" << std::endl;
    }
};

class Shape {
public:
    virtual void draw() = 0;
    virtual ~Shape() {}
};

class RectangleAdapter : public Shape {
public:
    RectangleAdapter(LegacyRectangle* rectangle, int x1, int y1, int x2, int y2)
        : rectangle(rectangle), x1(x1), y1(y1), x2(x2), y2(y2) {}
    void draw() override {
        rectangle->draw(x1, y1, x2, y2);
    }
private:
    LegacyRectangle* rectangle;
    int x1, y1, x2, y2;
};
/*
(b) Composite
Composes objects into tree structures to represent part-whole hierarchies.
*/
class Component {
public:
    virtual void operation() = 0;
    virtual ~Component() {}
};

class Leaf : public Component {
public:
    void operation() override {
        std::cout << "Leaf operation" << std::endl;
    }
};

class Composite : public Component {
public:
    void add(Component* component) {
        children.push_back(component);
    }
    void operation() override {
        std::cout << "Composite operation" << std::endl;
        for (Component* child : children) {
            child->operation();
        }
    }
    ~Composite() {
        for (Component* child : children) {
            delete child;
        }
    }
private:
    std::vector<Component*> children;
};

/*
(c) Decorator
Adds responsibilities dynamically to objects without subclassing.
*/
struct Decorator {
    virtual void operation() = 0;
    virtual ~Decorator() {}
};

struct ConcreteComponent : public Decorator {
    void operation() override {
        std::cout << "ConcreteComponent operation" << std::endl;
    }
};

struct ConcreteDecorator : public Decorator {
    ConcreteDecorator(Decorator* component) : component(component) {}
    void operation() override {
        std::cout << "ConcreteDecorator operation before" << std::endl;
        component->operation();
        std::cout << "ConcreteDecorator operation after" << std::endl;
    }
    ~ConcreteDecorator() {
        delete component;
    }
private:
    Decorator* component;
};

/*
3. Behavioral Patterns
These deal with communication between objects.
*/
/*
(a) Observer (Publish-Subscribe Pattern)
Notifies dependent objects when state changes.
*/
struct Observer{  
	virtual ~Observer(){}
	virtual	void update(float temp)=0;  
};  

// Subject (Observable)
struct WeatherStation{  
	private:  
		std::vector<Observer*> observers;  
		float temperature=25.f;  

	public:  
		void addObserver(Observer *o){observers.push_back(o);}  

		void setTemperature(float temp){  
			temperature=temp;  
			for(auto o:observers){
				o->update(temp); 
			} 
		} 
};  

struct PhoneDisplay: Observer{  
	void update(float temp){std::cout<<"Phone updated! Temp="<<temp<<"\n";}  
}; 

int main (int argc, char** argv)
{
    Singleton& s1 = Singleton::getInstance();
    Singleton& s2 = Singleton::getInstance();
    if (&s1 == &s2) {
        std::cout << "Singleton works, both contain the same instance." << std::endl;
    } else {
        std::cout << "Singleton failed, variables contain different instances." << std::endl;
    }
    Creator* creatorA = new ConcreteCreatorA();
    Product* productA = creatorA->factoryMethod();
    productA->use();
    delete productA;
    delete creatorA;
    Creator* creatorB = new ConcreteCreatorB();
    Product* productB = creatorB->factoryMethod();
    productB->use();
    delete productB;
    delete creatorB;
    AbstractFactory* factory1 = new ConcreteFactory1();
    AbstractProductA* prodA1 = factory1->createProductA();
    AbstractProductB* prodB1 = factory1->createProductB();
    prodA1->use();
    prodB1->use();
    delete prodA1;
    delete prodB1;
    delete factory1;
    AbstractFactory* factory2 = new ConcreteFactory2();
    AbstractProductA* prodA2 = factory2->createProductA();
    AbstractProductB* prodB2 = factory2->createProductB();
    prodA2->use();
    prodB2->use();
    delete prodA2;
    delete prodB2;
    delete factory2;
    Prototype* prototype = new ConcretePrototype(42);
    Prototype* clonedPrototype = prototype->clone();
    prototype->use();
    clonedPrototype->use();
    delete prototype;
    delete clonedPrototype;
    LegacyRectangle* legacyRect = new LegacyRectangle();
    Shape* rectangle = new RectangleAdapter(legacyRect, 10, 20, 30, 40);
    rectangle->draw();
    delete rectangle;
    delete legacyRect;
    Composite* root = new Composite();
    Leaf* leaf1 = new Leaf();
    Leaf* leaf2 = new Leaf();
    root->add(leaf1);
    root->add(leaf2);
    root->operation();
    delete root;
    Decorator* component = new ConcreteComponent();
    Decorator* decoratedComponent = new ConcreteDecorator(component);
    decoratedComponent->operation();
    delete decoratedComponent;
    Observer* phoneDisplay = new PhoneDisplay();
    WeatherStation* weatherStation = new WeatherStation();
    weatherStation->addObserver(phoneDisplay);
    weatherStation->setTemperature(30.5f);
    weatherStation->setTemperature(28.0f);
    delete phoneDisplay;
    delete weatherStation;
    return EXIT_SUCCESS;
}