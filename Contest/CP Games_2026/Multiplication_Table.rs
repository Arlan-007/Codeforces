use std::io::{self, Read};

fn gcd(mut a: i64, mut b: i64) -> i64 {
    while b != 0 {
        let t = b;
        b = a % b;
        a = t;
    }
    a.abs()
}

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut it = input.split_whitespace();

    let n: usize = it.next().unwrap().parse().unwrap();

    let mut vec = vec![vec![0i64; n]; n];
    for i in 0..n {
        for j in 0..n {
            vec[i][j] = it.next().unwrap().parse().unwrap();
        }
    }

    let mut ans = vec![0i64; n];

    for i in 0..n {
        let mut x = vec[i][0];
        for j in 1..n {
            x = gcd(x, vec[i][j]);
        }
        ans[i] = x;
    }

    for i in 0..n {
        print!("{} ", ans[i]);
    }
    println!();
}