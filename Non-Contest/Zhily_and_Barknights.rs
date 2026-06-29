use std::io::{self, Read};

const MOD: i64 = 998244353;

fn pw(mut a: i64, mut e: i64) -> i64 {
    let mut r = 1i64;
    while e > 0 {
        if e & 1 == 1 { r = r * a % MOD; }
        a = a * a % MOD;
        e >>= 1;
    }
    r
}

fn main() {
    let mut s = String::new();
    io::stdin().read_to_string(&mut s).unwrap();
    let mut it = s.split_whitespace();
    let t: usize = it.next().unwrap().parse().unwrap();
    let mut out = String::new();

    for _ in 0..t {
        let n: usize = it.next().unwrap().parse().unwrap();

        let mut a = vec![0i64; n];
        let mut b = vec![0i64; n];

        for x in &mut a { *x = it.next().unwrap().parse().unwrap(); }
        for x in &mut b { *x = it.next().unwrap().parse().unwrap(); }

        if n == 1 {
            out.push_str("0\n");
            continue;
        }

        let mut u = Vec::<(i64, i64)>::new();
        let mut v = Vec::<(i64, i64)>::new();

        for i in 0..n {
            for j in i + 1..n {
                u.push((a[i], a[j]));
            }
        }

        for i in 0..n {
            for j in 0..n {
                if i != j {
                    v.push((b[i], b[j]));
                }
            }
        }

        u.sort_unstable_by(|x, y| (x.0 as i128 * y.1 as i128).cmp(&(y.0 as i128 * x.1 as i128)));
        v.sort_unstable_by(|x, y| (x.0 as i128 * y.1 as i128).cmp(&(y.0 as i128 * x.1 as i128)));

        let mut j = 0usize;
        let mut sum = 0i128;

        for &(x, y) in &u {
            while j < v.len() && (v[j].0 as i128 * y as i128) < (x as i128 * v[j].1 as i128) {
                j += 1;
            }
            sum += j as i128;
        }

        let den = (n as i64) * ((n - 1) as i64) % MOD;
        let ans = (sum % MOD as i128) as i64 * pw(den, MOD - 2) % MOD;
        out.push_str(&format!("{}\n", ans));
    }
    print!("{}", out);
}