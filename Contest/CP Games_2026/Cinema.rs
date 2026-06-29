use std::io::{self, Read};
use std::collections::HashMap;

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut it = input.split_whitespace();

    let n: usize = it.next().unwrap().parse().unwrap();
    let mut cnt: HashMap<i64, usize> = HashMap::new();
    for _ in 0..n {
        let x: i64 = it.next().unwrap().parse().unwrap();
        *cnt.entry(x).or_insert(0) += 1;
    }

    let m: usize = it.next().unwrap().parse().unwrap();

    let mut b = vec![0i64; m];
    for i in 0..m {
        b[i] = it.next().unwrap().parse().unwrap();
    }

    let mut c = vec![0i64; m];
    for i in 0..m {
        c[i] = it.next().unwrap().parse().unwrap();
    }

    let mut ans = 0usize;
    let mut best_a = 0usize;
    let mut best_b = 0usize;

    for i in 0..m {
        let x = *cnt.get(&b[i]).unwrap_or(&0);
        let y = *cnt.get(&c[i]).unwrap_or(&0);

        if x > best_a || (x == best_a && y > best_b) {
            best_a = x;
            best_b = y;
            ans = i;
        }
    }

    println!("{}", ans + 1);
}