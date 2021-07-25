use std::fs;
use std::vec::Vec;

const FILENAME: &str = "input";

const LIST_OF_PATTERNS: [&str; 7] = [
    " byr:",
    " iyr:",
    " eyr:",
    " hgt:",
    " hcl:",
    " ecl:",
    " pid:",
];


fn eval1(s: &String) -> bool {
    for p in LIST_OF_PATTERNS {
        if !s.contains(p) {
            return false;
        }
    }
    true
}

fn solve1(vec: &Vec<String>) -> i32 {
    let mut res = 0;
    for v in vec {
        if eval1(&v) {
            res += 1;
        }
    }
    res
}


fn main() {
    let s = fs::read_to_string(FILENAME).expect("Something went wrong reading the file");
    let arr: Vec<&str> = s.split("\n").collect();

    let mut string = String::from("");
    let mut vec: Vec<String> = Vec::new();

    for s in arr {
        if s.trim() == "" {
            vec.push(string);
            string = String::from("");
            continue;
        }
        string = format!(" {} {} ", string.trim(), s.trim());
    }
    println!("res1: {}",  solve1(&vec));
}
