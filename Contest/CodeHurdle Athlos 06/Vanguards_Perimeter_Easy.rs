use std::io::{self, Read};

fn cross(ax: i64, ay: i64, bx: i64, by: i64) -> i128 {
    ax as i128 * by as i128 - ay as i128 * bx as i128
}

fn main() {
    let mut s = String::new();
    io::stdin().read_to_string(&mut s).unwrap();
    let mut it = s.split_whitespace();
    let t: usize = it.next().unwrap().parse().unwrap();
    let mut out = String::new();

    for _ in 0..t {
        let xa: i64 = it.next().unwrap().parse().unwrap();
        let ya: i64 = it.next().unwrap().parse().unwrap();
        let xb: i64 = it.next().unwrap().parse().unwrap();
        let yb: i64 = it.next().unwrap().parse().unwrap();
        let xc: i64 = it.next().unwrap().parse().unwrap();
        let yc: i64 = it.next().unwrap().parse().unwrap();

        let n: usize = it.next().unwrap().parse().unwrap();
        let mut ans = 0;

        for _ in 0..n {
            let x: i64 = it.next().unwrap().parse().unwrap();
            let y: i64 = it.next().unwrap().parse().unwrap();

            let c1 = cross(xb - xa, yb - ya, x - xa, y - ya);
            let c2 = cross(xc - xb, yc - yb, x - xb, y - yb);
            let c3 = cross(xa - xc, ya - yc, x - xc, y - yc);

            if c1 > 0 && c2 > 0 && c3 > 0 {
                ans += 1;
            }
        }
        out.push_str(&format!("{ans}\n"));
    }
    print!("{out}");
}