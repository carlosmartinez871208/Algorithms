#Build Java language projects
PROJECT = HelloWorld

SRC_PATH   = src

.PHONY: all clean run

all:
	@javac $(SRC_PATH)/$(PROJECT).java
	@echo "Main-class: $(PROJECT)" > $(SRC_PATH)/MANIFEST.MF
	@jar cvfm $(SRC_PATH)/$(PROJECT).jar $(SRC_PATH)/MANIFEST.MF $(SRC_PATH)/$(PROJECT).class

clean:
	@rm -f $(SRC_PATH)/*.class $(SRC_PATH)/*.jar $(SRC_PATH)/*.MF

run:
	@java -jar $(SRC_PATH)/$(PROJECT).jar

#javac HelloWorld.java 
#jar cfe HelloWorld.jar HelloWorld *.class
#java -jar HelloWorld.jar   
