use std::fs::File;
use std::io::{self, BufRead};
use std::path::Path;

// The output is wrapped in a Result to allow matching on errors
// Returns an Iterator to the Reader of the lines of the file.
fn read_lines<P>(filename: P) -> io::Result<io::Lines<io::BufReader<File>>>
    where P: AsRef<Path>, {
    let file = File::open(filename)?;
    Ok(io::BufReader::new(file).lines())
}

fn read_from_file(filename: String) -> Vec<String> {
    if let Ok(lines) = read_lines(filename) {
        return lines.map(|x| x.unwrap()).collect()
    }
    Vec::new()
}

fn main() {
    let inp = read_from_file(String::from("./test.txt"));
}

