use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut it = input.split_whitespace();

    let t: usize = it.next().unwrap().parse().unwrap();
    let mut out = String::new();

    for _ in 0..t {
        let n: usize = it.next().unwrap().parse().unwrap();

        let mut g0: Vec<String> = Vec::new();
        let mut g1: Vec<String> = Vec::new();
        let mut g2: Vec<String> = Vec::new();
        let mut g3: Vec<String> = Vec::new();

        for _ in 0..n {
            let x: i64 = it.next().unwrap().parse().unwrap();
            if x % 6 == 0 {
                g3.push(x.to_string());
            } else if x % 3 == 0 {
                g1.push(x.to_string());
            } else if x % 2 == 0 {
                g2.push(x.to_string());
            } else {
                g0.push(x.to_string());
            }
        }

        let ans = g3
            .into_iter()
            .chain(g2.into_iter())
            .chain(g0.into_iter())
            .chain(g1.into_iter())
            .collect::<Vec<_>>();

        out.push_str(&ans.join(" "));
        out.push('\n');
    }

    print!("{}", out);
}