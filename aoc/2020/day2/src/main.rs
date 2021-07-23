use std::fs;
use std::vec::Vec;

const FILENAME: &str = "input";

struct InputLine {
    min: usize,
    max: usize,
    c: char,
    pw: String,
}

impl InputLine {
    fn from_input(input: &str) -> InputLine {
        let v: Vec<&str> = input.split("-").collect();
        let min: usize = String::from(v[0]).parse().expect("oopsie");
        let v: Vec<&str> = v[1].split(" ").collect();
        let max: usize = String::from(v[0]).parse().expect("oopsie");
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
fn solve1(v: &Vec<InputLine>) -> i32 {
    let mut valid_pws = 0;
    for line in v {
        let mut i = 0;
        for ch in line.pw.chars() {
            if ch == line.c {
                i += 1;
            }
        }
        if i <= line.max && i >= line.min {
            valid_pws += 1;
        }
    }
   valid_pws
}

// This would be so nice with a Predicate Argument but fuck me I need to learn more
// Then one could outsource the function and just do partial application
//
// The faster I do this stuff the more time I have for reading the book
fn solve2(v: &Vec<InputLine>) -> i32 {
    let mut valid_pws = 0;
    for line in v {
        let fst = (line.pw.chars().nth(line.min-1).unwrap() == line.c) as i32;
        let snd = (line.pw.chars().nth(line.max-1).unwrap() == line.c) as i32;
        if fst + snd == 1 {
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

    let v = v;

    println!("res1: {}", solve1(&v));
    println!("res2: {}", solve2(&v));
}
