use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut it = input.split_whitespace();

    let t: usize = it.next().unwrap().parse().unwrap();
    let mut out = String::new();

    for _ in 0..t {
        let n: usize = it.next().unwrap().parse().unwrap();

        let mut mn: i64 = 0;
        let mut mx: i64 = 0;

        for _ in 0..n {
            let a: i64 = it.next().unwrap().parse().unwrap();

            let x1 = mn + a;
            let x2 = mx + a;
            let x3 = x1.abs();
            let x4 = x2.abs();

            mn = x1.min(x2).min(x3).min(x4);
            mx = x1.max(x2).max(x3).max(x4);
        }

        out.push_str(&format!("{}\n", mx));
    }

    print!("{}", out);
}