use std::io::{self, Read};

fn is_square(x: u128) -> bool {
    let r = (x as f64).sqrt() as u128;
    r * r == x
}

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let s = input.trim().as_bytes();
    let n = s.len();

    let mut best = 0usize;

    for mask in 1usize..(1usize << n) {
        let mut t = String::new();

        for i in 0..n {
            if (mask >> i) & 1 == 1 {
                t.push(s[i] as char);
            }
        }

        if t.starts_with('0') {
            continue;
        }

        let val: u128 = t.parse().unwrap();
        if is_square(val) {
            best = best.max(t.len());
        }
    }

    if best == 0 {
        println!("-1");
    } else {
        println!("{}", n - best);
    }
}