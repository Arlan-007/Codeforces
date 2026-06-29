use std::io::{self, Read};

fn main() {
    let mut s = String::new();
    io::stdin().read_to_string(&mut s).unwrap();
    let mut it = s.split_whitespace();

    let h1: i64 = it.next().unwrap().parse().unwrap();
    let h2: i64 = it.next().unwrap().parse().unwrap();
    let a: i64 = it.next().unwrap().parse().unwrap();
    let b: i64 = it.next().unwrap().parse().unwrap();

    if h1 + 8 * a >= h2 {
        println!("0");
    } else if a <= b {
        println!("-1");
    } else {
        let need = h2 - (h1 + 8 * a);
        let gain = 12 * (a - b);
        println!("{}", (need + gain - 1) / gain);
    }
}