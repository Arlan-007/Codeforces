use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut it = input.split_whitespace();
    let t: usize = it.next().unwrap().parse().unwrap();

    for _ in 0..t {
        let n: usize = it.next().unwrap().parse().unwrap();
        let mut a = Vec::new();

        for _ in 0..n {
            let a1: i64 = it.next().unwrap().parse().unwrap();
            let a2: i64 = it.next().unwrap().parse().unwrap();
            a.push((a1, a2));
        }

        a.sort_by_key(|&(a, b)| a + b);

        for (a, b) in a {
            print!("{} {} ", a, b);
        }
        println!();
    }
}