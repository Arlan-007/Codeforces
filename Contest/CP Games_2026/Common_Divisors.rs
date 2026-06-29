use std::io::{self, Read};

fn gcd(mut a: u64, mut b: u64) -> u64 {
    while b != 0 {
        let t = b;
        b = a % b;
        a = t;
    }
    a
}

fn divisor_count(x: u64) -> u64 {
    let mut cnt = 0;
    let mut i = 1;
    while i * i <= x {
        if x % i == 0 {
            cnt += 1;
            if i * i != x {
                cnt += 1;
            }
        }
        i += 1;
    }
    cnt
}

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut it = input.split_whitespace();

    let n: usize = it.next().unwrap().parse().unwrap();

    let mut answer: u64 = it.next().unwrap().parse().unwrap();
    for _ in 1..n {
        let x: u64 = it.next().unwrap().parse().unwrap();
        answer = gcd(answer, x);
    }

    println!("{}", divisor_count(answer));
}