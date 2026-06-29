use std::io::{self, Read};

fn main() {
    const MOD: i64 = 998244353;

    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut it = input.split_whitespace();
    let t: usize = it.next().unwrap().parse().unwrap();

    for _ in 0..t {
        let n: i64 = it.next().unwrap().parse().unwrap();
        let m: i64 = it.next().unwrap().parse().unwrap();
        let r: i64 = it.next().unwrap().parse().unwrap();
        let c: i64 = it.next().unwrap().parse().unwrap();

        let free = (r - 1) * m + (n - r + 1) * (c - 1);

        let mut ans = 1i64;
        let mut base = 2i64;
        let mut exp = free;

        while exp > 0 {
            if exp % 2 == 1 {
                ans = ans * base % MOD;
            }
            base = base * base % MOD;
            exp /= 2;
        }
        println!("{}", ans);
    }
}