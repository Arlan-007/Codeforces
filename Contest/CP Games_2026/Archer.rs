use std::io;

fn main() {
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();

    let v: Vec<f64> = input
        .split_whitespace()
        .map(|x| x.parse::<f64>().unwrap())
        .collect();

    let (a, b, c, d) = (v[0], v[1], v[2], v[3]);

    let ans = (a * d) / (a * d + b * c - a * c);

    println!("{:.12}", ans);
}