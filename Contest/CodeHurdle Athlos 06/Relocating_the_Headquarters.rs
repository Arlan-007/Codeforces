use std::io::{self, Read};

fn dfs1(
    u: usize,
    p: usize,
    d: i64,
    g: &Vec<Vec<usize>>,
    sub: &mut Vec<i64>,
    root: &mut i64,
) {
    *root += d;
    sub[u] = 1;
    for &v in &g[u] {
        if v == p {
            continue;
        }
        dfs1(v, u, d + 1, g, sub, root);
        sub[u] += sub[v];
    }
}

fn dfs2(
    u: usize,
    p: usize,
    n: i64,
    g: &Vec<Vec<usize>>,
    sub: &Vec<i64>,
    ans: &mut Vec<i64>,
) {
    for &v in &g[u] {
        if v == p {
            continue;
        }
        ans[v] = ans[u] + n - 2 * sub[v];
        dfs2(v, u, n, g, sub, ans);
    }
}

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut it = input.split_whitespace();
    let t: usize = it.next().unwrap().parse().unwrap();

    for _ in 0..t {
        let n: usize = it.next().unwrap().parse().unwrap();
        let mut g = vec![vec![]; n];

        for _ in 0..n - 1 {
            let u: usize = it.next().unwrap().parse().unwrap();
            let v: usize = it.next().unwrap().parse().unwrap();

            g[u].push(v);
            g[v].push(u);
        }

        let mut sub = vec![0i64; n];
        let mut root = 0i64;
        dfs1(0, n, 0, &g, &mut sub, &mut root);

        let mut ans = vec![0i64; n];
        ans[0] = root;
        dfs2(0, n, n as i64, &g, &sub, &mut ans);

        for x in ans {
            print!("{} ", x);
        }
        println!();
    }
}