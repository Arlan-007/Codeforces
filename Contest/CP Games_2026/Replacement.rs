use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut it = input.split_whitespace();

    let n: usize = it.next().unwrap().parse().unwrap();
    let mut v = vec![0; n];

    for i in 0..n {
        v[i] = it.next().unwrap().parse().unwrap();
    }

    v.sort();

    if n == 1 {
        println!("{}", if v[0] == 1 { 2 } else { 1 });
        return;
    }

    print!("1");
    for i in 0..n - 2 {
        print!(" {}", v[i]);
    }

    if v[n - 1] == 1 {
        println!(" 2");
    } else {
        println!(" {}", v[n - 2]);
    }
}