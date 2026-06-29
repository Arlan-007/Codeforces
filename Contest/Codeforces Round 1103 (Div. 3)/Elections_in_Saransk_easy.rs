use std::io::{self, Read};

const MOD: i64 = 1_000_000_007;
const MAX: usize = 500_000;

fn main() {
    let mut spf = vec![0usize; MAX + 1];
    for i in 2..=MAX {
        if spf[i] == 0 {
            let mut j = i;
            while j <= MAX {
                if spf[j] == 0 {
                    spf[j] = i;
                }
                j += i;
            }
        }
    }

    let mut s = String::new();
    io::stdin().read_to_string(&mut s).unwrap();
    let mut it = s.split_whitespace();

    let t: usize = it.next().unwrap().parse().unwrap();

    let mut cnt = vec![0i64; MAX + 1];

    for _ in 0..t {
        let n: usize = it.next().unwrap().parse().unwrap();
        let _: usize = it.next().unwrap().parse().unwrap(); // x = 1

        let mut used = Vec::new();

        for _ in 0..n {
            let mut x: usize = it.next().unwrap().parse().unwrap();

            while x > 1 {
                let p = spf[x];
                let mut c = 0;

                while x % p == 0 {
                    x /= p;
                    c += 1;
                }

                if cnt[p] == 0 {
                    used.push(p);
                }
                cnt[p] += c;
            }
        }

        let mut ans = 1i64;

        for p in used {
            ans = ans * (cnt[p] + 1) % MOD;
            cnt[p] = 0;
        }

        println!("{}", ans);
    }
}