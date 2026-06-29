use std::io::{self, Read};

fn main() {
    let mut s = String::new();
    io::stdin().read_to_string(&mut s).unwrap();
    let mut it = s.split_whitespace();

    let n: u128 = it.next().unwrap().parse().unwrap();
    let m: u128 = it.next().unwrap().parse().unwrap();
    let k: u128 = it.next().unwrap().parse().unwrap();
    let l: u128 = it.next().unwrap().parse().unwrap();

    if k + l > n {
        println!("-1");
        return;
    }

    let x = (k + l + m - 1) / m;

    if x * m > n {
        println!("-1");
    } else {
        println!("{}", x);
    }
}