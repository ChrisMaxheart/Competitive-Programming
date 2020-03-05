use std::fs::File;
use std::io::{self, BufRead};
use std::path::Path;


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

fn read_lines<P>(filename: P) -> io::Result<io::Lines<io::BufReader<File>>>
    where P: AsRef<Path>, {
    let file = File::open(filename)?;
    Ok(io::BufReader::new(file).lines())
}

struct Solver {
    passwords: Vec<String>
}

impl Solver {
    fn solve(&self) -> i32 {
        (&self.passwords).into_iter().filter(|password| self.is_strong_password(&password.parse::<i32>().unwrap())).collect::<Vec<&String>>().len() as i32
    }

    fn is_strong_password(&self, num: &i32) -> bool {
       self.is_six_digits(&num) && self.is_within_range(&num) && self.has_two_adjacent_same_digit(&num) && self.has_increasing_trend_digit(&num)
    }

    fn is_six_digits(&self, num: &i32) -> bool {
        num.to_string().len() == 6
    }

    fn is_within_range(&self, num: &i32) -> bool {
        &156218 < num && num < &652527
    }

    fn has_two_adjacent_same_digit(&self, num: &i32) -> bool {
        let mut prev_char = '.';
        for char in num.to_string().chars() {
            if char == prev_char {
                return true
            }
            prev_char = char;
        }
        false
    }

    fn has_increasing_trend_digit(&self, num: &i32) -> bool {
        let mut current_num = num.clone();
        let mut prev_number = 9;
        while current_num > 0 {
            let last_digit = current_num % 10;
            if last_digit > prev_number {
                return false
            }
            prev_number = last_digit;
            current_num /= 10;
        }
        true
    }
}

fn main() {
//    let inp = InputReader { filename: String::from("./test.txt") }.read();
    let inp: Vec<String> = (156218..652528).map(|x| x.to_string()).collect();
    println!("{}", Solver { passwords: inp }.solve());
}

