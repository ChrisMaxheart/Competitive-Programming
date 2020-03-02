use std::fs::File;
use std::io::{self, BufRead};
use std::path::Path;


struct InputReader {
    filename: String,
}

impl InputReader {
    fn read(&self) -> Vec<String> {
        if let Ok(lines) = read_lines(&self.filename) {
            return lines.map(|x| x.unwrap()).collect()
        }
        return Vec::new()
    }
}

fn read_lines<P>(filename: P) -> io::Result<io::Lines<io::BufReader<File>>>
    where P: AsRef<Path>, {
    let file = File::open(filename)?;
    Ok(io::BufReader::new(file).lines())
}

fn main() {
    let inp = InputReader{ filename:String::from("./test.txt") }.read();
}

