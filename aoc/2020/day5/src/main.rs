use std::cmp::max;
use std::fs;
use std::vec::Vec;

const FILENAME: &str = "input";

struct Seat {
    row: usize,
    col: usize,
}



impl Seat {
    fn solve(c: char, minx: usize, maxx: usize, s: &[char]) -> usize {
        if s.len() == 0 {
            return minx;
        }
        let dxhalf = (maxx - minx) / 2;
        return match s[0] {
            c => Seat::solve(c, minx, minx+dxhalf, &s[1..]),
            _ => Seat::solve(c, maxx-dxhalf, maxx, &s[1..]),
        }
    }

    fn calc_row(s: &[char]) -> usize {
        Seat::solve('F', 0, 127, s)
    }

    fn calc_col(s: &[char]) -> usize {
        Seat::solve('L', 0, 7, s)
    }

    fn from_str(s: &str) -> Seat {
        let v: Vec<char> = s.chars().collect();
        Seat {
            row: Seat::calc_row(&v[..8]),
            col: Seat::calc_col(&v[7..]),
        }
    }

    fn seat_id(&self) -> usize {
        self.row * 8 + self.col
    }
}

fn main() {
    let res1:usize = fs::read_to_string(FILENAME)
        .expect("Something went wrong reading the file")
        .split("\n")
        .map(|x| x.trim())
        .filter(|x| *x != "")
        .map(|x| Seat::from_str(x))
        .fold(0, |xs, x| max(xs, x.seat_id()));
    println!("res1: {}", res1);
}
