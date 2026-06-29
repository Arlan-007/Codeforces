use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut it = input.split_whitespace();

    let t: usize = it.next().unwrap().parse().unwrap();

    for _ in 0..t {
        let n: usize = it.next().unwrap().parse().unwrap();
        let k: usize = it.next().unwrap().parse().unwrap();
        let s = it.next().unwrap().as_bytes();

        let mut ok = true;

        for r in 0..k {
            let mut even = 0u8;

            let mut pos = r;
            while pos < n {
                even ^= s[pos] - b'0';
                pos += k;
            }

            if even != 0 {
                ok = false;
                break;
            }
        }

        println!("{}", if ok { "YES" } else { "NO" });
    }
}