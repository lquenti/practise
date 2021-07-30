use std::cmp::max;
use std::fs;
use std::vec::Vec;

const FILENAME: &str = "input";

#[derive(Clone)]
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
        if s[0] == c {
            return Seat::solve(c, minx, minx+dxhalf, &s[1..]);
        }
        Seat::solve(c, maxx-dxhalf, maxx, &s[1..])
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

fn find_my_seat(v: &Vec<Seat>) -> usize {
    let mut v: Vec<Seat> = v.to_vec();
    v.sort_by(|a,b| a.seat_id().cmp(&b.seat_id()));
    let mut i = 0;
    while i < v.len()-1 {
        if v[i+1].seat_id() - v[i].seat_id() == 2 {
            return v[i].seat_id() + 1;
        }
        i+=1;
    }
    0
}

fn main() {
    let v: Vec<Seat> = fs::read_to_string(FILENAME)
        .expect("Something went wrong reading the file")
        .split("\n")
        .map(|x| x.trim())
        .filter(|x| *x != "")
        .map(|x| Seat::from_str(x))
        .collect();
    let res1: usize = v.iter().fold(0, |xs, x| max(xs, x.seat_id()));
    println!("res1: {}", res1);
    let res2: usize = find_my_seat(&v);
    println!("res2: {}", res2);
}
