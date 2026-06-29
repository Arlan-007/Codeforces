use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut it = input.split_whitespace();

    let n: usize = it.next().unwrap().parse().unwrap();

    let mut pos = vec![0usize; n + 1];

    for sector in 1..=n {
        let f: usize = it.next().unwrap().parse().unwrap();
        pos[f] = sector;
    }

    let mut ans: i64 = 0;
    for i in 1..n {
        ans += (pos[i] as i64 - pos[i + 1] as i64).abs();
    }

    println!("{ans}");
}