use std::io::{self, Read};

fn main() {
    let mut s = String::new();
    io::stdin().read_to_string(&mut s).unwrap();
    let mut it = s.split_whitespace();
    let t: usize = it.next().unwrap().parse().unwrap();
    let mut out = String::new();

    for _ in 0..t {
        let n: usize = it.next().unwrap().parse().unwrap();
        let k: usize = it.next().unwrap().parse().unwrap();

        let mut runs = Vec::new();
        let mut cap = 0;

        for _ in 0..n {
            let a: usize = it.next().unwrap().parse().unwrap();
            cap = cap.max(a);

            if let Some((last, len)) = runs.last_mut() {
                if *last == cap {
                    *len += 1;
                    continue;
                }
            }
            runs.push((cap, 1usize));
        }

        let mut dp = vec![vec![-1i64; k + 1]; k + 1]; dp[0][0] = 0;
        let mut pre = 0;
        for (cap, len) in runs {
            let mut nex = vec![vec![-1i64; k + 1]; k + 1];

            for used in 0..=k {
                for hi in 0..=k {
                    let value = dp[used][hi];
                    if value < 0 {
                        continue;
                    }

                    nex[used][hi] = nex[used][hi].max(value + len as i64 * hi as i64);

                    for x in (pre + 1).max(hi + 1)..=cap.min(k - used) {
                        nex[used + x][x] = nex[used + x][x].max(value + len as i64 * x as i64);
                    }
                }
            }
            dp = nex;
            pre = cap;
        }
        let ans = dp.into_iter().flatten().max().unwrap();
        out.push_str(&format!("{ans}\n"));
    }
    print!("{out}");
}