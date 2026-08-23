use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut it = input.split_whitespace();
    let t: usize = it.next().unwrap().parse().unwrap();

    for _ in 0..t {
        let n: usize = it.next().unwrap().parse().unwrap();
        let s = it.next().unwrap().as_bytes();
        let mut dp = vec![(0i32, 0i32, 0i32)];

        for i in 0..n {
            let mut next = Vec::new();
            for &(a, b, c) in &dp {
                if s[i] == b'T' || s[i] == b'N' {
                    next.push((
                        a,
                        a.min(b) + 1,
                        b.min(c),
                    ));
                }
                if s[i] == b'F' || s[i] == b'N' {
                    next.push((
                        a + 1,
                        a.min(b),
                        b.min(c) + 1,
                    ));
                }
            }

            next.sort();
            next.dedup();

            let mut good = Vec::new();
            for j in 0..next.len() {
                let mut dominated = false;
                for k in 0..next.len() {
                    if j == k {
                        continue;
                    }
                    if next[k].0 >= next[j].0 && next[k].1 >= next[j].1 && next[k].2 >= next[j].2 {
                        dominated = true;
                        break;
                    }
                }
                if !dominated {
                    good.push(next[j]);
                }
            }
            dp = good;
        }
        let mut ans = 0;
        for &(a, b, c) in &dp {
            ans = ans.max(a.min(b).min(c));
        }
        println!("{}", ans);
    }
}