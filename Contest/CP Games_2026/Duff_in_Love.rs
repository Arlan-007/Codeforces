use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();

    let mut n: i64 = input.trim().parse().unwrap();

    let mut ans: i64 = 1;
    let mut d: i64 = 2;

    while d * d <= n {
        if n % d == 0 {
            ans *= d;

            while n % d == 0 {
                n /= d;
            }
        }
        d += 1;
    }

    if n > 1 {
        ans *= n;
    }

    println!("{}", ans);
}