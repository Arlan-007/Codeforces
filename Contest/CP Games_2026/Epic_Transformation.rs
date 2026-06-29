use std::collections::HashMap;
use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut it = input.split_whitespace();

    let t: usize = it.next().unwrap().parse().unwrap();

    for _ in 0..t {
        let n: i32 = it.next().unwrap().parse().unwrap();

        let mut freq = HashMap::<i32, i32>::new();
        let mut mx = 0;

        for _ in 0..n {
            let x: i32 = it.next().unwrap().parse().unwrap();
            let c = freq.entry(x).or_insert(0);
            *c += 1;
            mx = mx.max(*c);
        }

        let ans = if n % 2 == 0 {
            (2 * mx - n).max(0)
        } else {
            (2 * mx - n).max(1)
        };

        println!("{}", ans);
    }
}