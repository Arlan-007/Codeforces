use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut it = input.split_whitespace();
    let t: usize = it.next().unwrap().parse().unwrap();
    let r#mod : i64 = 1000000007;

    for _ in 0..t {
        let n: usize = it.next().unwrap().parse().unwrap();
        let k: usize = it.next().unwrap().parse().unwrap();
        let mut fill : i64 = 0;

        for _ in 0..k {
            let r: i64 = it.next().unwrap().parse().unwrap();
            let c: i64 = it.next().unwrap().parse().unwrap();
            fill += 2;
            if c == r {
                fill -= 1;
            }
        }

        let sz : i64 = n as i64 - fill;
        let mut dp: Vec<i64> = vec![0; (sz + 1) as usize];
        dp[0] = 1;
        if sz >= 1 {
            dp[1] = 1;
        }
        for i in 2..=sz {
            let idx = i as usize;
            dp[idx] = (dp[idx - 1] + 2 * (i - 1) * dp[idx - 2] % r#mod) % r#mod;
        }
        println!("{}", dp[sz as usize]);
    }
}