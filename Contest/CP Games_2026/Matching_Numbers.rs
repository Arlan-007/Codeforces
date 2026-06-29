use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut it = input.split_whitespace();

    let t: usize = it.next().unwrap().parse().unwrap();

    let mut out = String::new();

    for _ in 0..t {
        let n: i32 = it.next().unwrap().parse().unwrap();

        if n % 2 == 0 {
            out.push_str("No\n");
            continue;
        }

        out.push_str("Yes\n");

        let mut cur = (3 * (n + 1)) / 2;

        for i in 1..=n {
            out.push_str(&format!("{} {}\n", i, cur));

            cur += 1;
            if cur > 2 * n {
                cur = n + 1;
            }
        }
    }

    print!("{}", out);
}