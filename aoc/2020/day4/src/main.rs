use std::fs;
use std::vec::Vec;

const FILENAME: &str = "input";


// TODO: Refactor
fn eval(s: &String) -> bool {
    let list_of_patterns = [
    " byr:",
    " iyr:",
    " eyr:",
    " hgt:",
    " hcl:",
    " ecl:",
    " pid:",
    ];
    for p in list_of_patterns {
        if !s.contains(p) {
            println!("{}\t{}", p, s);
            return false;
        }
    }
    true
}

fn main() {
    let s = fs::read_to_string(FILENAME).expect("Something went wrong reading the file");
    let arr: Vec<&str> = s.split("\n").collect();

    let mut string = String::from("");
    let mut res1 = 0;

    for s in arr {
        if s.trim() == "" {
            if eval(&string) {
                res1 += 1;
            }
            string = String::from("");
            continue;
        }
        string = format!(" {} {} ", string.trim(), s.trim());
    }

    println!("res1: {}",  res1);
}
