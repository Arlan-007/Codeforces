use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut iter = input.split_whitespace();
    let t: usize = iter.next().unwrap().parse().unwrap();

    for _ in 0..t {
        let n: usize = iter.next().unwrap().parse().unwrap();

        let mut ans: i64 = 0;
        for b in 1..=n {
            let x = (n / b) as i64;
            ans += x * x;
        }
        println!("{}", ans);
    }
}