use std::fs;
use std::vec::Vec;

const FILENAME: &str = "input";

fn count_chars(x: &String) -> i32 {
    let mut x: Vec<char> = x.chars().collect();
    x.sort();
    x.dedup();
    x.len() as i32
}

fn main() {
    let i: i32 = fs::read_to_string(FILENAME)
        .expect("Something went wrong reading the file")
        .split("\n\n")
        .map(|x| x.replace('\n', ""))
        .map(|x| count_chars(&x))
        .sum();
    println!("{}", i);
}
