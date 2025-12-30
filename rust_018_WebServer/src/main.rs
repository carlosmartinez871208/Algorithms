use std::net::{TcpListener, TcpStream};
use std::io::{Read, Write};

fn main() {
    // iniciar el servidor
    let address = "127.0.0.1:8080";
    let listener = TcpListener::bind(address).unwrap();
    println!("Servidor escuchando en {}", address);
    // escuchar por conexiones
    for stream in listener.incoming() {
        let stream = stream.unwrap();
        println!("Nueva conexión establecida");
        handle_connection(stream);
    }
    // manejar solicitudes
    // enviar respuestas
}

fn handle_connection(mut stream: TcpStream) {
    let mut buffer = [0; 1024];
    stream.read(&mut buffer).unwrap();
    println!("Solicitud recibida: {}", String::from_utf8_lossy(&buffer[..]));
    let get = "GET / HTTP/1.1\r\n";
    if buffer.starts_with(get.as_bytes()) {
        send_response(&mut stream, "HTTP/1.1 200 OK\r\n\r\nHello World!!");
    } else {
        send_response(&mut stream, "HTTP/1.1 404 NOT FOUND\r\n\r\n");
    }
}

fn send_response(stream: &mut TcpStream, response: &str) {
    stream.write(response.as_bytes()).unwrap();
    stream.flush().unwrap();
}