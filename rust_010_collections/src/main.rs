fn main() {
    // Vector:
    // Vectors are resizable arrays that can hold multiple values of the same type.
    let numbers = vec![10, 20, 30, 40, 50];
    println!("Vector: {:?}", numbers);
    // Pushed vector
    let vec: Vec<u32> = Vec::new();
    let mut v = vec;
    v.push(1);
    v.push(2);
    v.push(3);
    println!("Pushed Vector: {:?}", v);
    let third: &u32 = &v[2];
    println!("The third element is: {}", third);
    let outvalue = v.get(100);
    match outvalue {
        Some(value) => println!("The value at index 100 is: {}", value),
        None => println!("There is no value at index 100."),
    }
    for i in &v {
        println!("Value: {}", i);
    }
    for i in &mut v {
        *i += 50;
    }
    println!("Modified Vector: {:?}", v);
    enum Mensaje{
        TEXT(String),
        Error(u32)
    }
    let mensajes = vec![
        Mensaje::TEXT(String::from("Hola")),
        Mensaje::Error(404),
        Mensaje::TEXT(String::from("Adiós")),
    ];
    for mensaje in mensajes {
        match mensaje {
            Mensaje::TEXT(text) => println!("Texto: {}", text),
            Mensaje::Error(code) => println!("Error con código: {}", code),
        }
    }

    // Strings: 
    // Strings are growable, UTF-8 encoded text buffers.
    let mut saludo = String::from("Hola");
    saludo.push_str(", mundo!");
    println!("String: {}", saludo);
    // String Slices:
    let saludo_slice = &saludo[0..4];
    println!("String Slice: {}", saludo_slice);

    // HashSet:
    // HashSets are collections of unique values.
    use std::collections::HashSet;
    let mut conjunto = HashSet::new();
    conjunto.insert("manzana");
    conjunto.insert("banana");
    conjunto.insert("naranja");
    println!("HashSet: {:?}", conjunto);

    // HashMap:
    // HashMaps are collections of key-value pairs.
    use std::collections::HashMap;
    let mut mapa = HashMap::new();
    mapa.insert("clave1", 10);
    mapa.insert("clave2", 20);
    println!("HashMap: {:?}", mapa);
}
