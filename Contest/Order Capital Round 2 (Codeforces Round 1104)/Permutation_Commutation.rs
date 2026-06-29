use std::io::{self, Read};
use std::collections::BTreeSet;

fn main() {
    let mut inp = String::new();
    io::stdin().read_to_string(&mut inp).unwrap();
    let mut it = inp.split_whitespace();

    let t: usize = it.next().unwrap().parse().unwrap();
    for _ in 0..t {
        let n: usize = it.next().unwrap().parse().unwrap();

        let mut a = vec![0usize; n + 1];
        let mut b = vec![0i64; n + 1];
        for i in 1..=n {
            a[i] = it.next().unwrap().parse().unwrap();
        }
        for i in 1..=n {
            b[i] = it.next().unwrap().parse().unwrap();
        }

        let mut cid = vec![0usize; n + 1];
        let mut seen = vec![false; n + 1];
        let mut clen: Vec<usize> = vec![];
        for i in 1..=n {
            if seen[i] {
                continue;
            }

            let id = clen.len();
            let mut j = i;
            let mut l = 0;

            while !seen[j] {
                seen[j] = true;
                cid[j] = id;
                j = a[j];
                l += 1;
            }
            clen.push(l);
        }

        let nc = clen.len();
        let mut used = vec![false; n + 1];
        let mut done = vec![false; nc];
        let mut bad = false;

        for i in 1..=n {
            if b[i] != -1 {
                used[b[i] as usize] = true;
            }
        }

        for i in 1..=n {
            if bad {
                break;
            }
            if b[i] == -1 || done[cid[i]] {
                continue;
            }

            let mut j = i;
            loop {
                let aj = a[j];
                let bj = a[b[j] as usize];

                if b[aj] != -1 {
                    if b[aj] as usize != bj {
                        bad = true;
                        break;
                    }
                } else {
                    if used[bj] {
                        bad = true;
                        break;
                    }
                    b[aj] = bj as i64;
                    used[bj] = true;
                }

                if aj == i {
                    break;
                }
                j = aj;
            }
            done[cid[i]] = true;
        }

        if bad {
            println!("NO");
            continue;
        }

        let mut free: Vec<BTreeSet<usize>> = vec![BTreeSet::new(); n + 1];
        for v in 1..=n {
            if !used[v] {
                free[clen[cid[v]]].insert(v);
            }
        }

        for i in 1..=n {
            if b[i] != -1 || done[cid[i]] {
                continue;
            }
            let l = clen[cid[i]];
            let v = *free[l].iter().next().unwrap();
            free[l].remove(&v);
            b[i] = v as i64;
            let mut j = i;
            loop {
                let aj = a[j];
                if aj == i {
                    break;
                }
                let bj = a[b[j] as usize];
                b[aj] = bj as i64;
                free[l].remove(&bj);
                j = aj;
            }
            done[cid[i]] = true;
        }

        println!("YES");
        let ans: Vec<String> = (1..=n).map(|i| b[i].to_string()).collect();
        println!("{}", ans.join(" "));
    }
}