use std::collections::HashMap;
use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut it = input.split_whitespace();

    let t: usize = it.next().unwrap().parse().unwrap();

    for _ in 0..t {
        let n: usize = it.next().unwrap().parse().unwrap();
        let k: i64 = it.next().unwrap().parse().unwrap();

        let mut freq = HashMap::new();

        for _ in 0..n {
            let x: i64 = it.next().unwrap().parse().unwrap();
            *freq.entry(x).or_insert(0) += 1;
        }

        let mut v: Vec<i64> = freq
            .into_iter()
            .filter(|(_, c)| *c >= k)
            .map(|(x, _)| x)
            .collect();

        if v.is_empty() {
            println!("-1");
            continue;
        }

        v.sort_unstable();

        let mut best_l = v[0];
        let mut best_r = v[0];

        let mut l = v[0];
        let mut r = v[0];

        for &x in v.iter().skip(1) {
            if x == r + 1 {
                r = x;
            } else {
                if r - l > best_r - best_l {
                    best_l = l;
                    best_r = r;
                }
                l = x;
                r = x;
            }
        }

        if r - l > best_r - best_l {
            best_l = l;
            best_r = r;
        }

        println!("{} {}", best_l, best_r);
    }
}