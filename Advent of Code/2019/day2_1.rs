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

struct Solver {
    data: Vec<i32>,
}

impl Solver {
    fn solve(&mut self) -> i32 {
        let mut pointer: usize = 0;
        loop {
            let command = self.data[pointer];
            if command == 99 {
                break;
            }

            let first_elem = self.data[self.data[pointer + 1] as usize];
            let second_elem = self.data[self.data[pointer + 2] as usize];
            let op = self.get_op(command);

            let result_location: usize = self.data[pointer + 3] as usize;
            self.data[result_location] = op(first_elem, second_elem);
            pointer += 4;
        }
        self.data[0]
    }

    fn get_op(&self, code: i32) -> fn(i32, i32) -> i32 {
        match code {
            1 => |x, y| x + y,
            _ => |x, y| x * y
        }
    }
}

fn read_lines<P>(filename: P) -> io::Result<io::Lines<io::BufReader<File>>>
    where P: AsRef<Path>, {
    let file = File::open(filename)?;
    Ok(io::BufReader::new(file).lines())
}

fn main() {
    let inp = InputReader{ filename:String::from("./test.txt") }.read();
    let mut solver = Solver{ data:inp[0].split(",").map(|x| x.parse::<i32>().unwrap()).collect() };
    println!("{}", solver.solve());
}

