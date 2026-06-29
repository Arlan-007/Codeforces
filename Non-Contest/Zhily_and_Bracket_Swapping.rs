use std::io::{self, Read};

fn main() {
    let mut s = String::new();
    io::stdin().read_to_string(&mut s).unwrap();
    let mut it = s.split_whitespace();

    let t: usize = it.next().unwrap().parse().unwrap();

    for _ in 0..t {
        let n: usize = it.next().unwrap().parse().unwrap();
        let a = it.next().unwrap().as_bytes();
        let b = it.next().unwrap().as_bytes();

        let mut r1 = Vec::with_capacity(n);
        let mut r2 = Vec::with_capacity(n);

        let mut flip = true;

        for i in 0..n {
            if a[i] == b[i] {
                r1.push(a[i]);
                r2.push(b[i]);
            } else {
                if flip {
                    r1.push(b'(');
                    r2.push(b')');
                } else {
                    r1.push(b')');
                    r2.push(b'(');
                }
                flip = !flip;
            }
        }

        let mut b1 = 0;
        let mut b2 = 0;
        let mut ok = true;

        for i in 0..n {
            if r1[i] == b'(' { b1 += 1; } else { b1 -= 1; }
            if r2[i] == b'(' { b2 += 1; } else { b2 -= 1; }

            if b1 < 0 || b2 < 0 {
                ok = false;
            }
        }

        if b1 != 0 || b2 != 0 {
            ok = false;
        }

        println!("{}", if ok { "YES" } else { "NO" });
    }
}