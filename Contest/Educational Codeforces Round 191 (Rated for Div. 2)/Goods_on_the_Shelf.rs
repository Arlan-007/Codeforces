use std::collections::HashSet;
use std::io::{self, Read};

fn check(a: &[usize], m: usize) -> bool {
    let mut vis = vec![false; m];
    for i in 0..a.len() {
        if i > 0 && a[i] == a[i - 1] {
            continue;
        }
        let x = a[i];
        if vis[x] {
            return false;
        }
        vis[x] = true;
    }
    true
}

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut it = input.split_whitespace();
    let t: usize = it.next().unwrap().parse().unwrap();

    for _ in 0..t {
        let n: usize = it.next().unwrap().parse().unwrap();
        let orig: Vec<i64> = (0..n)
            .map(|_| it.next().unwrap().parse().unwrap())
            .collect();

        let mut vals = orig.clone();
        vals.sort();
        vals.dedup();
        let m = vals.len();

        let a: Vec<usize> = orig
            .iter()
            .map(|x| vals.binary_search(x).unwrap())
            .collect();

        if check(&a,m) {
            println!("YES");
            continue;
        }

        let mut seen = HashSet::new();
        let mut bad = Vec::new();

        for i in 0..n {
            if i > 0 && a[i] != a[i - 1] && seen.contains(&a[i]) {
                bad.push(i);
            }
            seen.insert(a[i]);
        }

        if bad.len() > 4 {
            println!("NO");
            continue;
        }

        let mut cand = Vec::new();
        for &i in &bad {
            cand.push(i);
            if i > 0 {
                cand.push(i - 1);
            }
            if i + 1 < n {
                cand.push(i + 1);
            }

            let mut pos = vec![Vec::<usize>::new(); m];
            for i in 0..n {
                if i == 0 || a[i] != a[i - 1] {
                    pos[a[i]].push(i);
                }
                if i + 1 == n || a[i] != a[i + 1] {
                    pos[a[i]].push(i);
                }
            }

            let x = a[i];
            for &j in &pos[x] {
                cand.push(j);
                if j > 0 {
                    cand.push(j - 1);
                }
                if j + 1 < n {
                    cand.push(j + 1);
                }
            }
        }

        cand.sort();
        cand.dedup();

        let mut ok = false;
        for i in 0..cand.len() {
            for j in i + 1..cand.len() {
                let mut b = a.clone();
                b.swap(cand[i], cand[j]);
                if check(&b,m) {
                    ok = true;
                    break;
                }
            }
        }

        println!("{}", if ok { "YES" } else { "NO" });
    }
}