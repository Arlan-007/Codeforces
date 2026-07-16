use std::io::{self, Read};

fn main() {
    let mut s = String::new();
    io::stdin().read_to_string(&mut s).unwrap();
    let mut it = s.split_whitespace();
    let t: usize = it.next().unwrap().parse().unwrap();

    for _ in 0..t {
        let n: usize = it.next().unwrap().parse().unwrap();
        let m: usize = it.next().unwrap().parse().unwrap();

        let mut mat = vec![vec![0; n + 1]; n + 1];
        let mut c1 = vec![0; n + 1];
        let mut c2 = vec![0; n + 1];
        let mut ans = vec![0; n + 1];
        let mut vis = vec![false; n + 1];

        for _ in 0..m {
            let o: i32 = it.next().unwrap().parse().unwrap();
            let u: usize = it.next().unwrap().parse().unwrap();
            let v: usize = it.next().unwrap().parse().unwrap();

            mat[u][v] = o;
            mat[v][u] = o;

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

        let mut ok = true;
        for mag in (1..=n).rev() {
            let mut v = 0;
            for i in 1..=n {
                if !vis[i] && (c1[i] == 0 || c2[i] == 0) {
                    v = i;
                    break;
                }
            }
            if v == 0 {
                ok = false;
                break;
            }

            vis[v] = true;
            ans[v] = if c2[v] > 0 { -(mag as i32) } else { mag as i32 };
            for u in 1..=n {
                if !vis[u] && mat[v][u] != 0 {
                    if mat[v][u] == 1 {
                        c1[u] -= 1;
                    } else {
                        c2[u] -= 1;
                    }
                }
            }
        }
        if !ok {
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