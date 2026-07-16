use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut it = input.split_whitespace();
    let t: usize = it.next().unwrap().parse().unwrap();

    for _ in 0..t {
        let _n: usize = it.next().unwrap().parse().unwrap();
        let s = it.next().unwrap();
        let mut cur = 0;
        let mut longest = 0;
        for ch in s.chars() {
            if ch == '#' {
                cur += 1;
                if cur > longest {
                    longest = cur;
                }
            } else {
                cur = 0;
            }
        }
        println!("{}", (longest + 1) / 2);
    }
}