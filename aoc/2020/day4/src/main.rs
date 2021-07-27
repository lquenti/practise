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

const ALLOWED_ECLS: [&str; 7] = [
    "amb",
    "blu",
    "brn",
    "gry",
    "grn",
    "hzl",
    "oth",
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
            // TODO: Refactor me w/ unwrap_or once I know how to implement
            // fmap on results
            return match v.parse::<i32>() {
                Ok(v) => 1920 <= v && v <= 2002,
                Err(_) => false,
            }
        },
        "iyr" => {
            return match v.parse::<i32>() {
                Ok(v) => 2010 <= v && v <= 2020,
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
            let head = v[..v.len()-2].into_iter().collect::<String>()
                .parse::<i32>().unwrap_or(0);
            let tail = &v[v.len()-2..].into_iter().collect::<String>()[..];

            return match tail {
                "in" => return 59 <= head && head <= 76,
                "cm" => return 150 <= head && head <= 193,
                _ => false,
            }
        },
        "hcl" => {
            let v: Vec<char> = v.chars().collect();
            if v.len() != 7 {
                return false;
            }
            if *v.first().unwrap() != '#' {
                return false;
            }
            for c in &v[1..] {
                let i = *c as u32;
                if !(
                    (48 <= i && i <= 57) ||
                    (97 <= i && i <= 102)
                    ) {
                    return false;
                }
            }
            return true;
        },
        "ecl" => {
            return ALLOWED_ECLS.contains(&v);
        },
        "pid" => {
            let v: Vec<char> = v.chars().collect();
            if v.len() != 9 {
                return false;
            }
            for c in v{
                let i = c as i32;
                if !(48 <= i && i <= 57) {
                    return false;
                }
            }
            return true;
        },
        "cid" => {return true;}
        _ => {panic!("{}:{}", k,v);}
    }
}

fn eval2(v: &Vec<String>) -> bool{
    for kv in v {
        let kv: Vec<&str> = kv.split(':').collect();
        let k = kv[0];
        let v = kv[1];
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
