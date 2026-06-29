use std::collections::HashMap;
use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut it = input.split_whitespace();
    let t: usize = it.next().unwrap().parse().unwrap();

    for _ in 0..t {
        let n: usize = it.next().unwrap().parse().unwrap();
        let mut freq: HashMap<i32, usize> = HashMap::new();

        for _ in 0..n {
            let x: i32 = it.next().unwrap().parse().unwrap();
            *freq.entry(x).or_insert(0) += 1;
        }

        let mut ones = 0usize;
        let mut mores = 0usize;

        for &f in freq.values() {
            if f == 1 {
                ones += 1;
            } else {
                mores += 1;
            }
        }

        let ans = mores + (ones + 1) / 2;
        println!("{ans}");
    }
}