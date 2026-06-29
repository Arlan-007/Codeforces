use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut it = input.split_whitespace();

    let t: usize = it.next().unwrap().parse().unwrap();
    let mut out = String::new();

    for _ in 0..t {
        let n: usize = it.next().unwrap().parse().unwrap();
        let mut h = vec![0i64; n];
        for i in 0..n {
            h[i] = it.next().unwrap().parse().unwrap();
        }

        let mut ans = vec![0i64; n];

        for s in 0..n {
            let mut e = vec![0i64; n];
            for k in 0..n {
                e[k] = h[(s + k) % n];
            }

            let mut suf = vec![0i64; n + 1];
            for k in (0..n).rev() {
                suf[k] = suf[k + 1].max(e[k]);
            }

            let mut pref = 0i64;
            let mut sum = 0i64;
            for k in 1..n {
                pref = pref.max(e[k - 1]);
                sum += pref.min(suf[k]);
            }
            ans[s] = sum;
        }

        for i in 0..n {
            if i > 0 {
                out.push(' ');
            }
            out.push_str(&ans[i].to_string());
        }
        out.push('\n');
    }

    print!("{out}");
}