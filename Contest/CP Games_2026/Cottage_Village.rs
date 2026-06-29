use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut it = input.split_whitespace();

    let n: usize = it.next().unwrap().parse().unwrap();
    let t: f64 = it.next().unwrap().parse().unwrap();

    let mut houses: Vec<(f64, f64)> = Vec::new();

    for _ in 0..n {
        let x: f64 = it.next().unwrap().parse().unwrap();
        let a: f64 = it.next().unwrap().parse().unwrap();
        houses.push((x, a));
    }

    houses.sort_by(|a, b| a.0.partial_cmp(&b.0).unwrap());

    let mut ans = 2;

    for i in 0..n - 1 {
        let (x1, a1) = houses[i];
        let (x2, a2) = houses[i + 1];

        let gap = (x2 - a2 / 2.0) - (x1 + a1 / 2.0);

        if (gap - t).abs() < 1e-9 {
            ans += 1;
        } else if gap > t {
            ans += 2;
        }
    }

    println!("{}", ans);
}