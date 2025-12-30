//Library for main

use std::fs;

pub struct Config {
    pub query: String,
    pub filename: String,
}

impl Config {
    pub fn new(args: &[String]) -> Config {
        if args.len() < 3 {
            panic!("Not enough arguments");
        }
        let filename = args[1].clone();
        let query = args[2].clone();
        Config { query, filename }
    }
}

pub fn run (config: Config) {
    let content = fs::read_to_string(config.filename).expect("Something went wrong reading the file");
    let found = search(&config.query, &content);
    for line in found {
        println!("{}", line);
    }
}

pub fn search<'a>(query: &str, content: &'a str) -> Vec<&'a str> { //'a is the lifetime annotation
    let mut results = Vec::new();
    for line in content.lines() {
        if line.contains(query) {
            results.push(line);
        }
    }
    results
}