/* Estructuras:
** Son tipos de datos definidos por el usuario que agrupan múltiples valores.
** Se definen usando la palabra clave `struct`.
** Permiten organizar datos relacionados bajo un mismo nombre.
** Pueden tener campos con diferentes tipos de datos.
** Sisntaxis básica:
** struct NombreEstructura {
**     campo1: Tipo1,
**     campo2: Tipo2,
**     ...
** }
** Ejemplo:
** struct Persona {
**     nombre: String,
**     edad: u32,
** }
** let p = Persona { nombre: String::from("Alice"), edad: 30 };
** Acceso a campos:
** let nombre = p.nombre;
** let edad = p.edad;
** Las estructuras son útiles para modelar entidades del mundo real y organizar datos complejos.
*/

struct User {
    username: String,
    email: String,
    sign_in_count: u64,
    active: bool,
}

/* Metodos en las struct */
impl User {
    fn display_info(&self) {
        println!("Username: {}", self.username);
        println!("Email: {}", self.email);
        println!("Sign in count: {}", self.sign_in_count);
        println!("Active: {}", self.active);
    }
}

/* Tuple struct */
struct Color(i32, i32, i32);

fn main() {
    let usr = User {
        username: String::from("Ninmah"),
        email: String::from("nmr0902@example.com"),
        sign_in_count: 1,
        active: true,
    };
    println!("Username: {}", usr.username);
    println!("Email: {}", usr.email);
    println!("Sign in count: {}", usr.sign_in_count);
    println!("Active: {}", usr.active);
    let usr1 = build_user(String::from("Carlos"), String::from("carlos@example.com"));
    println!("Username: {}", usr1.username);
    println!("Email: {}", usr1.email);
    println!("Sign in count: {}", usr1.sign_in_count);
    println!("Active: {}", usr1.active);
    let black = Color(0, 0, 0);
    println!("Color - R: {}, G: {}, B: {}", black.0, black.1, black.2);
    usr.display_info();
}

/* Short hand initialization */
fn build_user(username: String, email: String) -> User {
    User {
        username,
        email,
        sign_in_count: 1,
        active: true,
    }
}