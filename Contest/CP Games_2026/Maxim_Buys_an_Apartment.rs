use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut it = input.split_whitespace();

    let n: usize = it.next().unwrap().parse().unwrap();
    let k: usize = it.next().unwrap().parse().unwrap();

    if k == 0 || k == n {
        println!("0");
    } else {
        println!("1");
    }

    let maxx = std::cmp::min(n - k, 2 * k);
    println!("{}", std::cmp::min(maxx,n));

}