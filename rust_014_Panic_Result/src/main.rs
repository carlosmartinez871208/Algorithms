/*
** Panic:
** THIS IS A PANIC TEST
** This program will intentionally panic when run.
** Use this to test panic handling in your environment.
**
** Result <T, E> is not used here because we want to demonstrate a panic scenario.
*/

use std::fs::File;

fn main() {
    let archivo = File::open("archivo_inexistente.txt");
    match archivo {
        Ok(_) => println!("Archivo abierto exitosamente."),
        Err(e) => println!("Error al abrir el archivo: {:?}", e.kind()),
    }
    // Resulting code before the panic
    println!("Starting the panic test...");
    // This line will cause a panic
    panic!("This is a panic!"); //Errores no recuperables.
    // This line will not be reached
}
