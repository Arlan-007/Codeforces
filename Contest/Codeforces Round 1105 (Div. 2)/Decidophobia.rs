use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut it = input.split_whitespace();
    let t: usize = it.next().unwrap().parse().unwrap();
    let mut out = String::new();

    for _ in 0..t {
        let n: usize = it.next().unwrap().parse().unwrap();
        let d: usize = it.next().unwrap().parse().unwrap();

        let mut a = vec![0i64; n];
        let mut b = vec![0i64; 2 * n];
        for i in 0..n {
            a[i] = it.next().unwrap().parse().unwrap();
        }
        for i in 0..2 * n {
            b[i] = a[i % n];
        }

        let mut pref = vec![0_i64; 2 * n + 1];
        for i in 0..2 * n {
            pref[i + 1] = pref[i] + b[i];
        }

        let mut ans = 0_i64;
        for i in 0..n {
            let c = i;
            let left = pref[c + n] - pref[c + n - d];
            let right = pref[c + d + 1] - pref[c + 1];

            let s = left + right;
            let gain = 2 * d as i64 * a[i] - s;
            if gain > 0 {
                ans += gain;
            }
        }
        out.push_str(&format!("{}\n", ans));
    }
    print!("{}", out);
}