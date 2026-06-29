use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut it = input.split_whitespace();

    let t: usize = it.next().unwrap().parse().unwrap();
    let mut out = String::new();

    for _ in 0..t {
        let n: usize = it.next().unwrap().parse().unwrap();
        let _k: i64 = it.next().unwrap().parse().unwrap();

        let mut a = vec![0i64; n];
        for i in 0..n {
            a[i] = it.next().unwrap().parse().unwrap();
        }

        let mut segs = Vec::with_capacity(n);
        let mut base = 0i64;

        for i in 0..n {
            let mut b: i64 = it.next().unwrap().parse().unwrap();
            if a[i] > b {
                std::mem::swap(&mut a[i], &mut b);
            }
            base += b - a[i];
            segs.push((a[i], b));
        }

        segs.sort_unstable();
        let mut overlap = false;

        for i in 1..n {
            if segs[i].0 <= segs[i - 1].1 {
                overlap = true;
                break;
            }
        }
        if overlap {
            out.push_str(&format!("{}\n", base));
            continue;
        }
        let mut min_gap = i64::MAX;
        for i in 1..n {
            min_gap = min_gap.min(segs[i].0 - segs[i - 1].1);
        }
        out.push_str(&format!("{}\n", base + 2 * min_gap));
    }
    print!("{}", out);
}