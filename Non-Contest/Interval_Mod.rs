use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut it = input.split_whitespace();

    let t: usize = it.next().unwrap().parse().unwrap();

    for _ in 0..t {
        let n: usize = it.next().unwrap().parse().unwrap();
        let k: usize = it.next().unwrap().parse().unwrap();
        let p: i64 = it.next().unwrap().parse().unwrap();
        let q: i64 = it.next().unwrap().parse().unwrap();

        let mut pref_b = vec![0i64; n + 1];
        let mut pref_c = vec![0i64; n + 1];
        let mut pref_mn = vec![0i64; n + 1];

        for i in 0..n {
            let x: i64 = it.next().unwrap().parse().unwrap();

            let b = x % p;
            let c = (x % q) % p;
            let mn = b.min(c);

            pref_b[i + 1] = pref_b[i] + b;
            pref_c[i + 1] = pref_c[i] + c;
            pref_mn[i + 1] = pref_mn[i] + mn;
        }

        let base = pref_mn[n];
        let mut ans = i64::MAX;

        for r in k..=n {
            let l = r - k;

            let seg_b = pref_b[r] - pref_b[l];
            let seg_c = pref_c[r] - pref_c[l];
            let seg_mn = pref_mn[r] - pref_mn[l];

            ans = ans.min(base - seg_mn + seg_b);
            ans = ans.min(base - seg_mn + seg_c);
        }

        println!("{}", ans);
    }
}