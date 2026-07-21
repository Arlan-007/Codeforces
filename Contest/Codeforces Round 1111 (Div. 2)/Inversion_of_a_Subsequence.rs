use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut it = input.split_whitespace();
    let t: usize = it.next().unwrap().parse().unwrap();

    for _ in 0..t {
        let n: usize = it.next().unwrap().parse().unwrap();

        let mut a = vec![0u8; n];
        let mut b = vec![0u8; n];
        let mut ones_a = 0;
        let mut ones_b = 0;

        for i in 0..n {
            a[i] = it.next().unwrap().parse::<u8>().unwrap();
            ones_a += a[i] as usize;
        }
        for i in 0..n {
            b[i] = it.next().unwrap().parse::<u8>().unwrap();
            ones_b += b[i] as usize;
        }

        if a == b {
            println!("0");
            continue;
        }
        if ones_a == 0 || ones_b == n {
            println!("-1");
            continue;
        }
        let mut parity = 0u8;
        for i in 0..n {
            if a[i] != b[i] {
                parity ^= a[i];
            }
        }
        if parity == 1 {
            println!("1");
        } else {
            println!("2");
        }
    }
}