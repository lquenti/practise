use std::fs;
use std::vec::Vec;

const FILENAME: &str = "input";

fn solve1(v: Vec<String>) -> i32 {
    let mut res = 0;
    let mut x = 0;
    let length = v[0].chars().count();
    for line in v {
        if line.chars().nth(x).unwrap() == '#' {
            res+=1;
        }
        x = (x+3)%length;
    }
    res
}

fn main() {
    let s = fs::read_to_string(FILENAME).expect("Something went wrong reading the file");
    let arr = s.split("\n");

    let mut v = Vec::new();

    for s in arr {
        if s.trim().is_empty() {
            continue;
        }
        v.push(String::from(s));
    }
    println!("res1: {}", solve1(v));
}
