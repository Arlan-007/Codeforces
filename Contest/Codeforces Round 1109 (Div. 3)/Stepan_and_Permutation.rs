use std::io::{self, Read};

fn gcd(mut a: usize, mut b: usize) -> usize {
    while b != 0 {
        let t = a % b;
        a = b;
        b = t;
    }
    a
}

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut it = input.split_whitespace();
    let t: usize = it.next().unwrap().parse().unwrap();

    for _ in 0..t {
        let n: usize = it.next().unwrap().parse().unwrap();
        let x: usize = it.next().unwrap().parse().unwrap();
        let y: usize = it.next().unwrap().parse().unwrap();
        let g = gcd(x, y);

        let mut ok = true;
        for i in 1..=n {
            let p: usize = it.next().unwrap().parse().unwrap();
            if i % g != p % g {
                ok = false;
            }
        }
        println!("{}", if ok { "YES" } else { "NO" });
    }
}