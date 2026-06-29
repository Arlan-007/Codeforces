use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut it = input.split_whitespace();
    let t: usize = it.next().unwrap().parse().unwrap();

    for _ in 0..t {
        let n: usize = it.next().unwrap().parse().unwrap();
        let s: Vec<u8> = it.next().unwrap().bytes().collect();

        let mut pos = Vec::new();
        let mut base = 0;

        for i in 0..n {
            if s[i] == b'F' {
                base += 1;
            } else if s[i] == b'N' {
                pos.push(i);
            }
        }

        let k = pos.len();
        let neg = -1_000_000_000;
        let mut dp = vec![vec![neg; n + 2]; n + 2];
        dp[0][0] = 0;

        for i in 0..n {
            let mut ndp = vec![vec![neg; n + 2]; n + 2];

            for h in 0..=n {
                for g in h..=n {
                    if dp[h][g] == neg {
                        continue;
                    }

                    if s[i] == b'T' {
                        let nh = h.saturating_sub(1);
                        let ng = g.max(nh);
                        ndp[nh][ng] = ndp[nh][ng].max(dp[h][g]);
                    } else if s[i] == b'F' {
                        let nh = h + 1;
                        let ng = g.max(nh);
                        ndp[nh][ng] = ndp[nh][ng].max(dp[h][g]);
                    } else {
                        let nh = h + 1;
                        let ng = g.max(nh);
                        ndp[nh][ng] = ndp[nh][ng].max(dp[h][g] + 1);

                        let nh = h.saturating_sub(1);
                        let ng = g.max(nh);
                        ndp[nh][ng] = ndp[nh][ng].max(dp[h][g]);
                    }
                }
            }

            dp = ndp;
        }

        let mut best = 0;

        for h in 0..=n {
            for g in h..=n {
                if dp[h][g] != neg {
                    best = best.max(base + dp[h][g] - g as i32);
                }
            }
        }
        println!("{}", ans);
    }
}