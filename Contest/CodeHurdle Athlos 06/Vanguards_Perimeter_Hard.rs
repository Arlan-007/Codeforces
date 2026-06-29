use std::io::{self, Read};

type P = (i64, i64);

fn cross(a: P, b: P, c: P) -> i128 {
    let (ax, ay) = (b.0 - a.0, b.1 - a.1);
    let (bx, by) = (c.0 - a.0, c.1 - a.1);
    ax as i128 * by as i128 - ay as i128 * bx as i128
}

fn inside(poly: &[P], p: P) -> bool {
    let k = poly.len();
    if cross(poly[0],poly[1],p) <= 0 || cross(poly[0],poly[k-1],p) >= 0 {
        return false;
    }

    let mut l = 1usize;
    let mut r = k - 1;

    while r - l > 1 {
        let m = (l + r) / 2;
        if cross(poly[0], poly[m], p) > 0 {
            l = m;
        } else {
            r = m;
        }
    }

    cross(poly[l], poly[l + 1], p) > 0
}

fn main() {
    let mut s = String::new();
    io::stdin().read_to_string(&mut s).unwrap();
    let mut it = s.split_whitespace();

    let t: usize = it.next().unwrap().parse().unwrap();
    let mut out = String::new();

    for _ in 0..t {
        let k: usize = it.next().unwrap().parse().unwrap();

        let mut poly = Vec::with_capacity(k);
        for _ in 0..k {
            let x: i64 = it.next().unwrap().parse().unwrap();
            let y: i64 = it.next().unwrap().parse().unwrap();
            poly.push((x, y));
        }

        let n: usize = it.next().unwrap().parse().unwrap();
        let mut ans = 0usize;

        for i in 1..=n {
            let x: i64 = it.next().unwrap().parse().unwrap();
            let y: i64 = it.next().unwrap().parse().unwrap();

            if inside(&poly, (x, y)) {
                ans ^= i;
            }
        }

        out.push_str(&format!("{ans}\n"));
    }

    print!("{out}");
}