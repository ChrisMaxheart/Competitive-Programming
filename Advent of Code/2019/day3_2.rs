use std::fs::File;
use std::io::{self, BufRead};
use std::path::Path;
use std::collections::HashMap;

#[derive(PartialEq, Eq, Hash, Copy, Clone)]
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
    fn solve(&self) -> i32 {
        let intersections = self.get_intersections();
        intersections.values().min().unwrap().clone()
    }

    fn get_intersections(&self) -> HashMap<Coordinate, i32> {
        let coordinates_from_commands_1 = self.get_coordinates_passed(&self.commands_1);
        let coordinates_from_commands_2 = self.get_coordinates_passed(&self.commands_2);
        let mut commands_1_steps: HashMap<Coordinate, i32> = HashMap::new();

        for (step, coordinate) in coordinates_from_commands_1.into_iter().enumerate() {
            commands_1_steps.entry(coordinate).or_insert(step as i32);
        }
        let mut intersections: HashMap<Coordinate, i32> = HashMap::new();
        for (step, coordinate) in coordinates_from_commands_2.into_iter().enumerate() {
            if !commands_1_steps.contains_key(&coordinate){
                continue;
            }
            intersections.entry(coordinate).or_insert((step as i32) + commands_1_steps[&coordinate]);
        }
        intersections
    }

    fn get_coordinates_passed(&self, commands: &Vec<String>) -> Vec<Coordinate> {
        let mut coordinate_passed = Vec::new();
        let mut current_coordinate = Coordinate { x: 0, y: 0 };
        for command in commands {
            let (coordinate, coordinate_from_command) = self.get_coordinates_from_command(current_coordinate, &command);
            current_coordinate = coordinate;
            coordinate_passed.extend(&coordinate_from_command)
        }
        coordinate_passed
    }

    fn get_coordinates_from_command(&self, mut current_coordinate: Coordinate, command: &String) -> (Coordinate, Vec<Coordinate>) {
        let (dir, amt) = command.split_at(1);
        let amt: i32 = amt.parse().unwrap();
        let mut coordinates = Vec::new();
        for _i in 0..amt {
            current_coordinate = self.get_next_coordinate(current_coordinate, dir);
            coordinates.push(current_coordinate);
        }
        (current_coordinate, coordinates)
    }

    fn get_next_coordinate(&self, current_coordinate: Coordinate, direction: &str) -> Coordinate {
        match direction {
            "R" => Coordinate { x: current_coordinate.x + 1, y: current_coordinate.y },
            "L" => Coordinate { x: current_coordinate.x - 1, y: current_coordinate.y },
            "U" => Coordinate { x: current_coordinate.x, y: current_coordinate.y + 1 },
            "D" => Coordinate { x: current_coordinate.x, y: current_coordinate.y - 1 },
            _ => current_coordinate
        }
    }
}


fn read_lines<P>(filename: P) -> io::Result<io::Lines<io::BufReader<File>>>
    where P: AsRef<Path>, {
    let file = File::open(filename)?;
    Ok(io::BufReader::new(file).lines())
}

fn main() {
    let inp = InputReader { filename: String::from("./test.txt") }.read();
    let solver = Solver { commands_1: inp[0].split(",").map(|x| String::from(x)).collect(), commands_2: inp[1].split(",").map(|x| String::from(x)).collect() };
    println!("{}", solver.solve());
}

