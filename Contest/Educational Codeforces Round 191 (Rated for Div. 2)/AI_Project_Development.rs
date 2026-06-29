use std::io::{self, Read};

fn ceil_div(a: i64, b: i64) -> i64 {
    (a + b - 1) / b
}

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut it = input.split_whitespace();

    let t: usize = it.next().unwrap().parse().unwrap();
    let mut out = String::new();

    for _ in 0..t {
        let n: i64 = it.next().unwrap().parse().unwrap();
        let x: i64 = it.next().unwrap().parse().unwrap();
        let y: i64 = it.next().unwrap().parse().unwrap();
        let z: i64 = it.next().unwrap().parse().unwrap();

        let no_ai = ceil_div(n, x + y);

        let ai = if z * x >= n {
            ceil_div(n, x)
        } else {
            z + ceil_div(n - z * x, x + 10 * y)
        };

        let ans = no_ai.min(ai);
        out.push_str(&format!("{}\n", ans));
    }

    print!("{}", out);
}