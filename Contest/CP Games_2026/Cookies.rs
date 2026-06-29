use std::io::{self, Read};

fn mod_pow(mut a: i64, mut e: i64, m: i64) -> i64 {
    let mut r = 1;
    while e > 0 {
        if e & 1 == 1 {
            r = r * a % m;
        }
        a = a * a % m;
        e >>= 1;
    }
    r
}

fn main() {
    let mut s = String::new();
    io::stdin().read_to_string(&mut s).unwrap();
    let n: i64 = s.trim().parse().unwrap();

    const MOD: i64 = 1_000_003;

    if n == 0 {
        println!("1");
    } else {
        println!("{}", mod_pow(3, n - 1, MOD));
    }
}