use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut it = input.split_whitespace();

    let t: usize = it.next().unwrap().parse().unwrap();

    for _ in 0..t {
        let n: usize = it.next().unwrap().parse().unwrap();
        let mut p = vec![0i64; n];

        for i in 0..n {
            p[i] = it.next().unwrap().parse().unwrap();
        }

        let mut ans = 0;

        for i in 0..n - 1 {
            let a = p[i];
            let b = p[i + 1];

            if a %(a-b) == 0 {
                ans += 1;
            }
        }

        println!("{}", ans);
    }
}