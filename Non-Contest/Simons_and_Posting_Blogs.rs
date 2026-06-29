use std::collections::HashSet;
use std::io::{self, Read};

fn less(a: &[i64], b: &[i64], rem: &HashSet<i64>) -> bool {
    let (mut i, mut j) = (0, 0);
    loop {
        while i < a.len() && rem.contains(&a[i]) { i += 1; }
        while j < b.len() && rem.contains(&b[j]) { j += 1; }
        if i == a.len() || j == b.len() {
            return i == a.len() && j != b.len();
        }
        if a[i] != b[j] {
            return a[i] < b[j];
        }
        i += 1;
        j += 1;
    }
}

fn main() {
    let mut s = String::new();
    io::stdin().read_to_string(&mut s).unwrap();
    let mut it = s.split_whitespace();
    let t: usize = it.next().unwrap().parse().unwrap();
    let mut out = String::new();

    for _ in 0..t {
        let n: usize = it.next().unwrap().parse().unwrap();

        let mut blogs = Vec::with_capacity(n);
        for _ in 0..n {
            let l: usize = it.next().unwrap().parse().unwrap();
            let mut a = Vec::with_capacity(l);
            for _ in 0..l {
                a.push(it.next().unwrap().parse::<i64>().unwrap());
            }
            let mut seen = HashSet::new();
            let mut b = Vec::new();
            for &x in a.iter().rev() {
                if seen.insert(x) {
                    b.push(x);
                }
            }
            blogs.push(b);
        }

        let mut done = vec![false; n];
        let mut rem = HashSet::new();
        let mut ans = Vec::new();
        for _ in 0..n {
            let mut best = usize::MAX;
            for i in 0..n {
                if done[i] { continue; }
                if best == usize::MAX || less(&blogs[i], &blogs[best], &rem) {
                    best = i;
                }
            }
            done[best] = true;
            for &x in &blogs[best] {
                if rem.insert(x) {
                    ans.push(x);
                }
            }
        }
        for (i, x) in ans.iter().enumerate() {
            if i > 0 { out.push(' '); }
            out.push_str(&x.to_string());
        }
        out.push('\n');
    }
    print!("{}", out);
}