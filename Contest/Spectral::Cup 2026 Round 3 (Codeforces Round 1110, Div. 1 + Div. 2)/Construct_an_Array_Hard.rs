use std::collections::VecDeque;
use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut it = input.split_whitespace();
    let t: usize = it.next().unwrap().parse().unwrap();

    for _ in 0..t {
        let n: usize = it.next().unwrap().parse().unwrap();
        let m: usize = it.next().unwrap().parse().unwrap();

        let mut adj = vec![Vec::<(usize, i32)>::new(); n + 1];
        let mut c1 = vec![0i32; n + 1];
        let mut c2 = vec![0i32; n + 1];

        for _ in 0..m {
            let o: i32 = it.next().unwrap().parse().unwrap();
            let u: usize = it.next().unwrap().parse().unwrap();
            let v: usize = it.next().unwrap().parse().unwrap();

            adj[u].push((v, o));
            if u != v {
                adj[v].push((u, o));
            }

            if o == 1 {
                c1[u] += 1;
                if u != v {
                    c1[v] += 1;
                }
            } else {
                c2[u] += 1;
                if u != v {
                    c2[v] += 1;
                }
            }
        }

        let mut done = vec![false; n + 1];
        let mut ans = vec![0i32; n + 1];
        let mut q = VecDeque::new();

        for i in 1..=n {
            if c1[i] == 0 || c2[i] == 0 {
                q.push_back(i);
            }
        }

        let mut mag = n as i32;
        let mut cnt = 0;

        while let Some(v) = q.pop_front() {
            if done[v] {
                continue;
            }

            done[v] = true;
            cnt += 1;

            if c2[v] > 0 {
                ans[v] = -mag;
            } else {
                ans[v] = mag;
            }
            mag -= 1;

            for &(to, typ) in &adj[v] {
                if done[to] {
                    continue;
                }

                if typ == 1 {
                    c1[to] -= 1;
                } else {
                    c2[to] -= 1;
                }

                if c1[to] == 0 || c2[to] == 0 {
                    q.push_back(to);
                }
            }
        }

        if cnt < n {
            println!("NO");
        } else {
            println!("YES");
            for i in 1..=n {
                print!("{} ", ans[i]);
            }
            println!();
        }
    }
}