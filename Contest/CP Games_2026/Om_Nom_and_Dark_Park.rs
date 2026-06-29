use std::io::{self, Read};

fn dfs(v: usize, n: usize, c: &[i64], ans: &mut i64) -> i64 {
    if v > (1 << n) - 1 {
        return c[v];
    }

    let left = dfs(v * 2, n, c, ans);
    let right = dfs(v * 2 + 1, n, c, ans);

    *ans += (left - right).abs();

    c[v] + left.max(right)
}

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut it = input.split_whitespace();
    let n: usize = it.next().unwrap().parse().unwrap();

    let size = 1 << (n + 1);
    let mut c = vec![0i64; size];

    for i in 2..size {
        c[i] = it.next().unwrap().parse().unwrap();
    }

    let mut ans = 0;
    dfs(1, n, &c, &mut ans);

    println!("{}", ans);
}