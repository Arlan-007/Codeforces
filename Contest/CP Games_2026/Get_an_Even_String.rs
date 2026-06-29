use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut it = input.split_whitespace();

    let t: usize = it.next().unwrap().parse().unwrap();

    for _ in 0..t {
        let s = it.next().unwrap().as_bytes();

        let mut seen = [false; 26];
        let mut pairs = 0;

        for &c in s {
            let idx = (c - b'a') as usize;

            if seen[idx] {
                pairs += 1;
                seen = [false; 26];
            } else {
                seen[idx] = true;
            }
        }

        println!("{}", s.len() - 2 * pairs);
    }
}