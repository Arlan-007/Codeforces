use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut it = input.split_whitespace();

    let n: usize = it.next().unwrap().parse().unwrap();

    let mut b = vec![0i64; n / 2];
    for i in 0..n / 2 {
        b[i] = it.next().unwrap().parse().unwrap();
    }

    let mut a = vec![0i64; n];
    let mut l: i64 = 0;
    let mut r: i64 = 1_000_000_000_000_000_000;

    for i in 0..n / 2 {
        a[i] = std::cmp::max(l, b[i] - r);
        a[n - 1 - i] = b[i] - a[i];
        l = a[i];
        r = a[n - 1 - i];
    }

    for i in 0..n {
        if i > 0 {
            print!(" ");
        }
        print!("{}", a[i]);
    }
    println!();
}