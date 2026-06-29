use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut it = input.split_whitespace();

    let n: usize = it.next().unwrap().parse().unwrap();
    let mut v = Vec::with_capacity(n);

    for _ in 0..n {
        let x: i64 = it.next().unwrap().parse().unwrap();
        v.push(x);a
    }

    v.sort();
    v.dedup();

    if v.len() <= 2 {
        println!("YES");
    } else if v.len() >= 4 {
        println!("NO");
    } else {
        if 2 * v[1] == v[0] + v[2] {
            println!("YES");
        } else {
            println!("NO");
        }
    }
}