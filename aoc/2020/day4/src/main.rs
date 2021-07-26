use std::fs;
use std::vec::Vec;
use regex::Regex;

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

fn eval2_kv(k: &str, v: &str) -> bool {
    match k {
        "byr" => {
            return match v.parse::<i32>() {
                Ok(v) => v >= 1920 && v <= 2002,
                Err(_) => false,
            }
        },
        "iyr" => {
            return match v.parse::<i32>() {
                Ok(v) => v >= 2010 && v <= 2020,
                Err(_) => false,
            }
        },
        "eyr" => {
            return match v.parse::<i32>() {
                Ok(v) => v >= 2020 && v <= 2030,
                Err(_) => false,
            }
        },
        "hgt" => {
            // TODO: Refactor me
            let v = v.chars().collect::<Vec<char>>();
            return match &v[v.len()-2..].into_iter().collect::<String>()[..] {
                "in" => {
                    // TODO: Next: unwrap_or or sth for all matches
                    v[..v.len()-2]
                        .into_iter()
                        .collect::<String>()
                        .parse::<i32>
                }
                "cm" => false,
                _ => false,
            }
        },
        "hcl" => {return false;},
        "ecl" => {return false;},
        "pid" => {return false;},
        // cid
        _ => {return true;}
    }
}

fn eval2(v: &Vec<String>) -> bool{
    for kv in v {
        let kv: Vec<&str> = kv.split(':').collect();
        let k = kv[0];
        let v = kv[1];
        println!("{} {}", k, v);
        if !eval2_kv(k,v) {
            return false;
        }
    }
    true
}

fn solve2(vec: &Vec<String>) -> i32 {
    vec.iter()
        .filter(
            |x| eval1(x)
        )
        .map(
            |x| x.split(" ").filter(
                |y| y.trim() != ""
            )
            .map(
                |y| String::from(y.trim())
            )
            .collect::<Vec<String>>()
        )
        .filter(
            |x| eval2(x)
        )
        .count()
        as i32
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
    println!("res2: {}",  solve2(&vec));
}
