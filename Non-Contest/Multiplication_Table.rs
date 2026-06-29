use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut it = input.split_whitespace();
    let n: usize = it.next().unwrap().parse().unwrap();

    let mut a = vec![vec![0u64; n]; n];
    for i in 0..n {
        for j in 0..n {
            a[i][j] = it.next().unwrap().parse().unwrap();
        }
    }

    let x1 = (((a[0][1] * a[0][2]) / a[1][2]) as f64).sqrt() as u64;
    print!("{}", x1);
    for i in 1..n {
        print!(" {}", a[0][i] / x1);
    }
    println!();
}