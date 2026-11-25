use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut it = input.split_whitespace();

    let t: usize = it.next().unwrap().parse().unwrap();
    let mut out = String::new();

    for _ in 0..t {
        let n: usize = it.next().unwrap().parse().unwrap();
        if n % 2 == 0 {
            out.push_str("No\n");
            continue;
        }
        out.push_str("Yes\n");

        let k = (n - 1) / 2;
        let base = 2 * n + 1 - k;

        for i in 1..=k + 1 {
            let a = 2 * i - 1;
            let b = base - i;
            out.push_str(&format!("{} {}\n", a, b));
        }

        for i in 1..=k {
            let a = 2 * i;
            let b = 2 * n - i + 1;
            out.push_str(&format!("{} {}\n", a, b));
        }
    }
    print!("{}", out);
}