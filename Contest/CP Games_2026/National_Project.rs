use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut it = input.split_whitespace();

    let t: usize = it.next().unwrap().parse().unwrap();

    let mut out = String::new();

    for _ in 0..t {
        let n: i64 = it.next().unwrap().parse().unwrap();
        let g: i64 = it.next().unwrap().parse().unwrap();
        let b: i64 = it.next().unwrap().parse().unwrap();

        let need = (n + 1) / 2;

        let full = need / g;
        let rem = need % g;

        let days = if rem == 0 {
            full * (g + b) - b
        } else {
            full * (g + b) + rem
        };

        out.push_str(&format!("{}\n", days.max(n)));
    }

    print!("{out}");
}