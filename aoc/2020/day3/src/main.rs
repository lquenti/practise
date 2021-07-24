use std::fs;
use std::vec::Vec;

const FILENAME: &str = "input";

fn solve1(v: &Vec<String>, dx: usize, dy: usize) -> u64 {
    let mut res = 0;
    let mut x = 0;
    let mut y = 0;
    let xlen = v[0].chars().count();
    let ylen = v.len();
    loop {
        if y >= ylen {
            break;
        }
        if v[y].chars().nth(x).unwrap() == '#' {
            res+=1;
        }
        x = (x+dx)%xlen;
        y+=dy;
    }
    res
}

fn solve2(v: &Vec<String>) -> u64 {
    solve1(v,1,1) * solve1(v,3,1) * solve1(v,5,1) * solve1(v,7,1) * solve1(v,1,2)
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
    println!("res1: {}", solve1(&v, 3,1));
    println!("res2: {}", solve2(&v));
}
