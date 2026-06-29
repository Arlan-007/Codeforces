use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut it = input.split_whitespace();

    let t: usize = it.next().unwrap().parse().unwrap();

    for _ in 0..t {
        let n: usize = it.next().unwrap().parse().unwrap();

        let mut mn = i64::MAX;
        let mut mx = i64::MIN;

        for _ in 0..n {
            let x: i64 = it.next().unwrap().parse().unwrap();
            mn = mn.min(x);
            mx = mx.max(x);
        }

        println!("{}", mx - mn + 1);
    }
}