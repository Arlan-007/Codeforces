use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut it = input.split_whitespace();

    let t: usize = it.next().unwrap().parse().unwrap();
    let mut out = String::new();

    for _ in 0..t {
        let n: usize = it.next().unwrap().parse().unwrap();
        let mut x: usize = it.next().unwrap().parse().unwrap();
        let mut y: usize = it.next().unwrap().parse().unwrap();

        if x > y {
            std::mem::swap(&mut x, &mut y);
        }

        let mut p = vec![0i64; n];
        for i in 0..n {
            p[i] = it.next().unwrap().parse().unwrap();
        }

        let a = &p[x..y];
        let mut mn_pos = 0;
        for i in 1..a.len() {
            if a[i] < a[mn_pos] {
                mn_pos = i;
            }
        }

        let mn = a[mn_pos];

        let mut b = Vec::with_capacity(n - a.len());
        b.extend_from_slice(&p[..x]);
        b.extend_from_slice(&p[y..]);

        let mut k = 0;
        while k < b.len() && b[k] < mn {
            k += 1;
        }

        for v in &b[..k] {
            out.push_str(&format!("{} ", v));
        }
        for i in mn_pos..a.len() {
            out.push_str(&format!("{} ", a[i]));
        }
        for i in 0..mn_pos {
            out.push_str(&format!("{} ", a[i]));
        }
        for v in &b[k..] {
            out.push_str(&format!("{} ", v));
        }
        out.pop();
        out.push('\n');
    }

    print!("{}", out);
}