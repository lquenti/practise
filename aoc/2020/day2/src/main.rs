use std::fs;
use std::vec::Vec;

const FILENAME: &str = "input";

struct InputLine {
    min: u32,
    max: u32,
    c: char,
    pw: String,
}

impl InputLine {
    fn from_input(input: &str) -> InputLine {
        let v: Vec<&str> = input.split("-").collect();
        let min: u32 = String::from(v[0]).parse().expect("oopsie");
        let v: Vec<&str> = v[1].split(" ").collect();
        let max: u32 = String::from(v[0]).parse().expect("oopsie");
        let c: char = v[1].chars().next().unwrap();
        let pw: String = v[2].trim().to_string();
        InputLine {
            min,
            max,
            c,
            pw,
        }
    }
}

// fuck me I wish I knew how to haskelly oneline this map reduce
fn solve1(v: Vec<InputLine>) -> i32 {
    let mut valid_pws = 0;
    for line in v {
        let InputLine {min, max, c, pw} = line;
        let mut i = 0;
        for ch in pw.chars() {
            if ch == c {
                i += 1;
            }
        }
        if i <= max && i >= min {
            valid_pws += 1;
        }
    }
   valid_pws
}


fn main() {
    let s = fs::read_to_string(FILENAME).expect("Something went wrong reading the file");
    let arr = s.split("\n");

    let mut v = Vec::new();

    for s in arr {
        if s.trim().is_empty() {
            continue;
        }
        v.push(InputLine::from_input(s));
    }

    println!("res1: {}", solve1(v));
}
