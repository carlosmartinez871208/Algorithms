// Multiuser chat server using Tokio
use tokio::{
    io::{AsyncBufReadExt, AsyncReadExt, AsyncWriteExt, ReadHalf, WriteHalf}, 
    net::{TcpListener, TcpStream},
};
use std::{net::SocketAddr};

#[tokio::main]
async fn main(){
    let listener: TcpListener = TcpListener::bind("localhost:8080").await.unwrap();
    let (tx, _rx) = tokio::sync::broadcast::channel::<String>(10);
    loop{
        let (socket, _addr): (TcpStream, SocketAddr) = listener.accept().await.unwrap();
        let tx = tx.clone();
        let mut rx = tx.subscribe();
        tokio::spawn(async move {
            let (reader, mut writer): (ReadHalf<TcpStream>, WriteHalf<TcpStream>) = tokio::io::split(socket);
            let mut reader = tokio::io::BufReader::new(reader);
            let mut line: String = String::new();
            loop{
                tokio::select!{
                    _ = reader.read_line(&mut line) => { /* handle read */
                        tx.send(line.clone()).unwrap();
                        line.clear();
                    }
                    result = rx.recv() => { /* handle received message */
                        let msg = result.unwrap();
                        writer.write_all(msg.as_bytes()).await.unwrap();
                    }
                }
            }
        });
    }
}