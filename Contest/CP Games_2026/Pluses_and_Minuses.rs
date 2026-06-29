use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();

    let mut it = input.split_whitespace();

    let t: usize = it.next().unwrap().parse().unwrap();

    for _ in 0..t {
        let s = it.next().unwrap();

        let mut bal = 0i64;
        let mut low = 0i64;
        let mut ans = s.len() as i64;

        for (i, ch) in s.chars().enumerate() {
            if ch == '+' {
                bal += 1;
            } else {
                bal -= 1;
            }

            if bal < low {
                low = bal;
                ans += (i + 1) as i64;
            }
        }

        println!("{}", ans);
    }
}