/*
** cargo command is used to build and run Rust projects.
** The command 'cargo run' compiles the code and runs the resulting executable.
** In this case, it will print "Hello, world!" to the console.
** cargo new hello --bin
** The above command creates a new Rust binary project named "hello".
** cargo run
** The above command builds and runs the project.
** cargo new rust_hello --lib
** The above command creates a new Rust library project named "rust_hello".
** cargo build
** The above command compiles the project without running it.
** cargo test
** The above command runs the tests for the project.
** cargo check
** The above command checks the code for errors without producing an executable.
** cargo fmt
** The above command formats the code according to Rust's style guidelines.
** cargo clippy
** The above command runs the Clippy linter to catch common mistakes and improve the code.
** cargo doc --open
** The above command generates documentation for the project and opens it in a web browser.
** cargo publish
** The above command publishes the package to crates.io, the Rust package registry.
** cargo update
** The above command updates dependencies listed in Cargo.toml to the latest versions allowed by the version constraints.
** cargo clean
** The above command removes the target directory, which contains the compiled artifacts.
** cargo install <crate>
** The above command installs a Rust binary crate from crates.io.
** cargo uninstall <crate>
** The above command uninstalls a Rust binary crate that was previously installed.
** cargo debug
** The above command builds the project in debug mode, which is the default mode for development.
** cargo release
** The above command builds the project in release mode, which optimizes the code for performance.
** cargo tree
** The above command displays a tree of dependencies for the project.
** cargo search <keyword>
** The above command searches for crates on crates.io that match the given keyword.
** cargo login <token>
** The above command logs in to crates.io using the provided API token.
** cargo logout
** The above command logs out from crates.io.
** cargo yank <version>
** The above command yanks a specific version of a crate from crates.io, preventing new projects from using it.
** cargo unyank <version>
** The above command unyanks a specific version of a crate on crates.io, allowing new projects to use it again.
*/

fn main() {
    println!("Hello, world!");
}
