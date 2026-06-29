use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut it = input.split_whitespace();

    let t: usize = it.next().unwrap().parse().unwrap();
    let mut out = String::new();

    for _ in 0..t {
        let a: i64 = it.next().unwrap().parse().unwrap();
        let b: i64 = it.next().unwrap().parse().unwrap();
        let x: i64 = it.next().unwrap().parse().unwrap();

        if x == 1 {
            out.push_str(&(a - b).abs().to_string());
            out.push('\n');
            continue;
        }

        let mut da = Vec::new();
        let mut cur = a;
        let mut ops = 0i64;
        loop {
            da.push((cur, ops));
            if cur == 0 {
                break;
            }
            cur /= x;
            ops += 1;
        }

        let mut db = Vec::new();
        cur = b;
        ops = 0;
        loop {
            db.push((cur, ops));
            if cur == 0 {
                break;
            }
            cur /= x;
            ops += 1;
        }

        let mut ans = i64::MAX;
        for &(va, ca) in &da {
            for &(vb, cb) in &db {
                let cost = ca + cb + (va - vb).abs();
                if cost < ans {
                    ans = cost;
                }
            }
        }

        out.push_str(&ans.to_string());
        out.push('\n');
    }

    print!("{out}");
}