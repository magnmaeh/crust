use std::net::TcpStream;
use std::io::{stdin, Result, Write};

fn main() -> Result<()> {
    let mut stream = TcpStream::connect("127.0.0.1:8080")?;

    loop {
        let mut input = String::new();
        stdin().read_line(&mut input)?;
        stream.write(input.as_bytes())?;        
    }
}
