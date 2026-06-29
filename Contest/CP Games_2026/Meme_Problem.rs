use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut it = input.split_whitespace();

    let t: usize = it.next().unwrap().parse().unwrap();
    let mut out = String::new();

    for _ in 0..t {
        let d: f64 = it.next().unwrap().parse::<f64>().unwrap();

        if d == 1.0 || d == 2.0 || d == 3.0 {
            out.push_str("N\n");
        } else {
            let disc = d * d - 4.0 * d;
            let s = if disc < 0.0 { 0.0 } else { disc.sqrt() };
            let a = (d + s) / 2.0;
            let b = (d - s) / 2.0;
            out.push_str(&format!("Y {:.10} {:.10}\n", a, b));
        }
    }

    print!("{out}");
}