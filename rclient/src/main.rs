use std::net::TcpStream;
use std::io::{Result, Write};
use std::{mem, slice};

include!(concat!(env!("OUT_DIR"), "/bindings.rs"));

impl packet {
    fn serialize(&self) -> &[u8] {
        let p: *const packet = self;     // the same operator is used as with references
        let p: *const u8 = p as *const u8;  // convert between pointer types
        unsafe { 
            slice::from_raw_parts(p, mem::size_of::<packet>())
        }
    }
}

fn main() -> Result<()> {
    let mut stream = TcpStream::connect("127.0.0.1:8080")?;

    for i in 0..1000 {
        let p: packet = unsafe { packet_generate(i) };
        unsafe { packet_print(&p as *const packet) };
        stream.write(p.serialize())?;
    }

    Ok(())
}
