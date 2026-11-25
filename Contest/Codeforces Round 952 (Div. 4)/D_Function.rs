use std::io::{self, Read};

const MOD: u64 = 1_000_000_007;

fn mod_pow(mut base: u64, mut exp: u64, m: u64) -> u64 {
    let mut result = 1 % m;
    base %= m;
    while exp > 0 {
        if exp & 1 == 1 {
            result = result * base % m;
        }
        base = base * base % m;
        exp >>= 1;
    }
    result
}

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut it = input.split_whitespace();
    let t: usize = it.next().unwrap().parse().unwrap();

    for _ in 0..t {
        let l: u64 = it.next().unwrap().parse().unwrap();
        let r: u64 = it.next().unwrap().parse().unwrap();
        let k: u64 = it.next().unwrap().parse().unwrap();

        let base = 9 / k + 1;
        let ans = (mod_pow(base, r, MOD) + MOD - mod_pow(base, l, MOD)) % MOD;
        println!("{}", ans);

    }
}