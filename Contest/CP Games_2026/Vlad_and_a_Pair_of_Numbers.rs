use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut it = input.split_whitespace();

    let t: usize = it.next().unwrap().parse().unwrap();

    for _ in 0..t {
        let x: u64 = it.next().unwrap().parse().unwrap();

        if x & 1 == 1 {
            println!("-1");
            continue;
        }

        let c = x / 2;

        if (c & x) != 0 {
            println!("-1");
            continue;
        }

        println!("{} {}", c, c + x);
    }
}