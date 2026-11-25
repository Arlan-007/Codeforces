use std::io::{self, Read};

fn main() {
    let mut s = String::new();
    io::stdin().read_to_string(&mut s).unwrap();
    let mut it = s.split_whitespace();

    let t: usize = it.next().unwrap().parse().unwrap();

    for _ in 0..t {
        let n: usize = it.next().unwrap().parse().unwrap();
        let mut a = vec![0i32; n + 1];
        let mut b = vec![0i32; n];
        for i in 1..=n {
            a[i] = it.next().unwrap().parse().unwrap();
            b[i - 1] = a[i];
        }
        b.sort();
        let mid = b[(n - 1) / 2];

        for i in 1..=n {
            if a[i] == mid {
                a[i] = 0;
            } else if a[i] > mid {
                a[i] = 1;
            } else {
                a[i] = -1;
            }
        }

        let mut dp = vec![0i32; n + 1];
        for i in 1..=n {
            let mut flg = if a[i] == 0 { 1 } else { 0 };
            if flg > 0 && (i == 1 || dp[i - 1] > 0) {
                dp[i] = dp[i - 1] + 1;
            }
            let mut sm = a[i];
            let mut j = i as i32 - 3;
            while j >= 0 {
                let jj = j as usize;
                if a[jj + 1] == 0 {
                    flg += 1;
                }
                if a[jj + 2] == 0 {
                    flg += 1;
                }
                sm += a[jj + 1] + a[jj + 2];
                if sm.abs() < flg && (jj == 0 || dp[jj] > 0) {
                    dp[i] = dp[i].max(dp[jj] + 1);
                }
                j -= 2;
            }
        }
        println!("{}", dp[n]);
    }
}