use std::collections::HashMap;
use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();

    let mut it = input.split_whitespace();

    let n: usize = it.next().unwrap().parse().unwrap();

    let mut freq: HashMap<u32, i64> = HashMap::new();

    for _ in 0..n {
        let x: u32 = it.next().unwrap().parse().unwrap();
        *freq.entry(x.count_ones()).or_insert(0) += 1;
    }

    let mut ans: i64 = 0;

    for &cnt in freq.values() {
        ans += cnt * (cnt - 1) / 2;
    }

    println!("{}", ans);
}