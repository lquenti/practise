use std::fs;
use std::vec::Vec;

const FILENAME: &str = "input";

fn main() {
    let s = fs::read_to_string(FILENAME).expect("Something went wrong reading the file");
    let arr = s.split("\n");

    let mut valid_pws = 0;

    for s in arr {
        if s.trim().is_empty() {
            continue;
        }
        // TODO: DO I need all these operators and parantheses?
        let v: Vec<&str> = s.split("-").collect::<Vec<&str>>();
        let min: u32 = String::from(v[0]).parse().expect("oopsie");
        let v: Vec<&str> = v[1].split(" ").collect::<Vec<&str>>();
        let max: u32 = String::from(v[0]).parse().expect("oopsie");
        let c: char = v[1].chars().next().unwrap();
        let pw: String = v[2].trim().to_string();
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

    println!("res1: {}", valid_pws);
}
