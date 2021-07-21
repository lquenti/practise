use std::fs;
use std::vec::Vec;

const FILENAME: &str = "input";

// O(n^2) fuck it I'm not here for the complexity
fn solve1(v: &Vec<i32>) -> i32 {
    let mut res = -1; // ik, ik result optional maybe etc
    'outer: for i in v {
        for j in v {
            if i+j == 2020 {
                res = i*j;
                break 'outer;
            }
        }
    }
    res
}

// I guess for O(N log N) if implemented best lets look it up
// Probably some sorting and line sweeping
// Fuck it, I wanna write some rust for now
//
// Also, I should really use an Optional here
fn solve2(v: &Vec<i32>) -> i32 {
    for a in v {
        for b in v {
            for c in v {
                if a+b+c == 2020 {
                    return a*b*c;
                }
            }
        }
    }
    -1
}

fn main() {
    let s = fs::read_to_string(FILENAME).expect("Something went wrong reading the file");
    let arr = s.split("\n");

    let mut vec = Vec::new();


    for s in arr {
        if s.trim().is_empty() {
            continue;
        }
        let i: i32 = s.parse().expect("oh no");
        vec.push(i);
    }
    println!("res1: {}", solve1(&vec));
    println!("res2: {}", solve2(&vec));
}
