use std::fs::File;
use std::io::{self, BufRead};
use std::path::Path;
use std::collections::HashSet;

#[derive(PartialEq, Eq, Hash)]
struct Coordinate {
    x: i32,
    y: i32,
}

struct InputReader {
    filename: String,
}

impl InputReader {
    fn read(&self) -> Vec<String> {
        if let Ok(lines) = read_lines(&self.filename) {
            return lines.map(|x| x.unwrap()).collect();
        }
        return Vec::new();
    }
}

struct Solver {
    commands_1: Vec<String>,
    commands_2: Vec<String>,
}

impl Solver {
    fn solve(&self) {}

    fn get_intersection(&self) {
        let mut coordinate_passed: HashSet<Coordinate> = HashSet::new();
        let mut intersections = Vec::new();

        for command in self.commands_1 {}
    }

    fn get_coordinates_passed(&self, commands: Vec<String>) -> HashSet<Coordinate> {
        let mut coordinate_passed = HashSet::new();
        for command in commands {}
        coordinate_passed
    }

    fn get_coordinates_from_command(&self, current_coordinate: Coordinate, command: String) -> HashSet<Coordinate> {
        let (dir, amt) = command.split_at(1);
        let amt: i32 = amt.parse().unwrap();
        let coordinates = HashSet::new();
        coordinates
    }

    fn manhattan_distance(&self, coordinate: Coordinate) -> i32 {
        coordinate.x + coordinate.y
    }
}


fn read_lines<P>(filename: P) -> io::Result<io::Lines<io::BufReader<File>>>
    where P: AsRef<Path>, {
    let file = File::open(filename)?;
    Ok(io::BufReader::new(file).lines())
}

fn main() {
    let inp = InputReader { filename: String::from("./test.txt") }.read();
}

