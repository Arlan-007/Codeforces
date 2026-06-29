use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();

    let mut it = input.split_whitespace();

    let n: usize = it.next().unwrap().parse().unwrap();

    let mut cnt = vec![0i64; 100001];
    let mut mx = 0usize;

    for _ in 0..n {
        let x: usize = it.next().unwrap().parse().unwrap();
        cnt[x] += 1;
        mx = mx.max(x);
    }

    let mut dp = vec![0i64; mx + 1];

    if mx >= 1 {
        dp[1] = cnt[1];
    }

    for i in 2..=mx {
        dp[i] = dp[i - 1].max(dp[i - 2] + (i as i64) * cnt[i]);
    }

    println!("{}", dp[mx]);
}