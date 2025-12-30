use std::env;

use::rust_projetc_minigrep::Config;

fn main() {
    let args = env::args().collect::<Vec<String>>();
    let config = Config::new(&args);
    println!("Searching for '{}' in file '{}'", config.query, config.filename);
    rust_projetc_minigrep::run(config);
}