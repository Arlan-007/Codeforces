use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut it = input.split_whitespace();
    let t: usize = it.next().unwrap().parse().unwrap();
    let mut out = String::new();

    for _ in 0..t {
        let n: usize = it.next().unwrap().parse().unwrap();
        let k: usize = it.next().unwrap().parse().unwrap();
        let mut cnt = vec![0usize; n + 1];

        for _ in 0..n {
            let x: usize = it.next().unwrap().parse().unwrap();
            cnt[x] += 1;
        }

        let mut pair = false;
        let mut evenfreq = false;
        let mut prev: Option<usize> = None;

        for v in 1..=n {
            if cnt[v] == 0 {
                continue;
            }
            if let Some(p) = prev {
                if v - p <= k {
                    pair = true;
                }
            }
            if cnt[v] % 2 == 0 {
                evenfreq = true;
            }
            prev = Some(v);
        }

        if pair || evenfreq {
            out.push_str("YES\n");
        } else {
            out.push_str("NO\n");
        }
    }

    print!("{}", out);
}