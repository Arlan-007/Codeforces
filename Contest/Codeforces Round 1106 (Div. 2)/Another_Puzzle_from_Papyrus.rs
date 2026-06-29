use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut it = input.split_whitespace();
    let t: usize = it.next().unwrap().parse().unwrap();

    for _ in 0..t {
        let n: usize = it.next().unwrap().parse().unwrap();
        let c: i64 = it.next().unwrap().parse().unwrap();

        let mut a = vec![0i64; n];
        let mut b = vec![0i64; n];
        for x in &mut a {
            *x = it.next().unwrap().parse().unwrap();
        }
        for x in &mut b {
            *x = it.next().unwrap().parse().unwrap();
        }

        let sum_a: i64 = a.iter().sum();
        let sum_b: i64 = b.iter().sum();
        if sum_a < sum_b {
            println!("-1");
            continue;
        }

        let diff = sum_a - sum_b;
        let ok = a.iter().zip(&b).all(|(x, y)| x >= y);
        if ok {
            println!("{}", diff);
            continue;
        }

        a.sort();
        b.sort();

        let okok = a.iter().zip(&b).all(|(x, y)| x >= y);
        if okok {
            println!("{}", diff + c);
        } else {
            println!("-1");
        }
    }
}