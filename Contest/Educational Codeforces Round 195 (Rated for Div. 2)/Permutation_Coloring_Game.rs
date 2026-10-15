use std::io::{self, Read};
const INF: i32 = 1_000_000_000;

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut it = input.split_whitespace();
    let t: usize = it.next().unwrap().parse().unwrap();
    let mut out = String::new();

    for _ in 0..t {
        let n: usize = it.next().unwrap().parse().unwrap();
        let k: usize = it.next().unwrap().parse().unwrap();
        let p: Vec<usize> = (0..n)
            .map(|_| it.next().unwrap().parse::<usize>().unwrap() - 1)
            .collect();

        let mut vis = vec![false; n];
        let mut len = Vec::new();
        for i in 0..n {
            if vis[i] {
                continue;
            }

            let mut cur = i;
            let mut cnt = 0;
            while !vis[cur] {
                vis[cur] = true;
                cnt += 1;
                cur = p[cur];
            }
            len.push(cnt);
        }

        len.sort_unstable_by(|a, b| b.cmp(a));
        let ans;
        if k == 1 {
            if len[0] >= 3 {
                ans = "Bob";
            } else if len[0] == 1 || n % 2 == 1 {
                ans = "Alice";
            } else {
                ans = "Bob";
            }
        } else if len[0] > k + 1 {
            ans = "Bob";
        } else if len[0] == k + 1 {
            if len.len() > 1 && len[1] == k + 1 {
                ans = "Bob";
            } else {
                let mut non_singleton = 0;
                let mut singleton = 0;

                for &x in len.iter().skip(1) {
                    if x > 1 {
                        non_singleton += x;
                    } else {
                        singleton += 1;
                    }
                }

                let alice = non_singleton + singleton % (k + 1);
                if alice == 0 || alice > k {
                    ans = "Bob";
                } else {
                    ans = "Alice";
                }
            }
        } else {
            let m = len.len().min(2 * k);
            let mut dp = vec![vec![INF; k + 1]; k + 1];
            dp[0][0] = 0;

            for i in 0..m {
                let mut ndp = vec![vec![INF; k + 1]; k + 1];
                let s = len[i];

                for j in 0..=k {
                    for c in 0..=k {
                        let cur = dp[j][c];
                        if cur == INF {
                            continue;
                        }

                        if j + s <= k {
                            ndp[j + s][c + 1] = ndp[j + s][c + 1].min(cur);
                        }

                        let extra = if i - c < k { s - 1 } else { 0 };
                        ndp[j][c] = ndp[j][c].min(cur + extra as i32);
                    }
                }
                dp = ndp;
            }
            ans = if dp.iter().any(|row| row.iter().any(|&x| x <= k as i32)) {
                "Alice"
            } else {
                "Bob"
            };
        }
        out.push_str(ans);
        out.push('\n');
    }
    print!("{out}");
}
