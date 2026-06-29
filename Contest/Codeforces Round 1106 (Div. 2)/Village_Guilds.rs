use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut it = input.split_whitespace();
    let t: usize = it.next().unwrap().parse().unwrap();

    for _ in 0..t {
        let n: usize = it.next().unwrap().parse().unwrap();

        let mut g = vec![Vec::new(); n];
        for v in 1..n {
            let p: usize = it.next().unwrap().parse::<usize>().unwrap() - 1;
            g[p].push(v);
        }

        let mut height = vec![0usize; n];
        let mut ans = n as u64;

        for v in (0..n).rev() {
            let mut a = 0;
            let mut b = 0;

            for &u in &g[v] {
                let h = height[u];
                if h > a {
                    b = a;
                    a = h;
                } else if h > b {
                    b = h;
                }
            }

            if !g[v].is_empty() {
                height[v] = a + 1;
            }
            if g[v].len() >= 2 {
                ans += (b + 1) as u64;
            }
        }
        println!("{}", ans);
    }
}