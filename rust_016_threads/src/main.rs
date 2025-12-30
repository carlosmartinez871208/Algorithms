use std::thread;
use std::time::Duration;
use std::sync::mpsc;
use std::sync::Mutex;

fn main() {
    /*
    // Thread creation and joining example
    let joinhandle = thread::spawn(|| {
        for i in 1..=5 {
            println!("Thread is running: {}", i);
            thread::sleep(Duration::from_secs(1));
        }
    });
    println!("Main thread is doing something else...");
    thread::sleep(Duration::from_secs(3));
    println!("Main thread is waiting for the spawned thread to finish...");
    joinhandle.join().unwrap();
    */
    /*
    // Inter-thread communication example
    let (tx,rx) = mpsc::channel(); //Inter thread communication channel
    thread::spawn(move || {
        thread::sleep(Duration::from_secs(2));
        let val = String::from("Hello from the spawned thread!");
        tx.send(val).unwrap();
    });
    let received = rx.recv().unwrap();
    println!("Main thread received: {}", received);
    */
    // Multiple producers example
    let id = Mutex::new(99);
    let handle1 = std::thread::spawn (move|| {
        let mut num = id.lock().unwrap();
        *num += 1;
        println!("Thread 1 incremented id to: {}", *num);
    });
    let id = Mutex::new(99);
    let handle2 = std::thread::spawn (move|| {
        let mut num = id.lock().unwrap();
        *num += 1;
        println!("Thread 2 incremented id to: {}", *num);
    });
    handle1.join().unwrap();
    handle2.join().unwrap();
}