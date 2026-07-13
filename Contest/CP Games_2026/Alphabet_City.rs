use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut it = input.split_whitespace();

    let n: usize = it.next().unwrap().parse().unwrap();
    let m: i64 = it.next().unwrap().parse().unwrap();

    let mut cnt = vec![[0i64; 26]; n];
    let mut total = [0i64; 26];

    for i in 0..n {
        let s = it.next().unwrap();
        for b in s.bytes() {
            let c = (b - b'A') as usize;
            cnt[i][c] += 1;
            total[c] += 1;
        }
    }

    for i in 0..n {
        let mut lo = 0;
        let mut hi = m;

        while lo < hi {
            let mid = (lo + hi + 1) / 2;
            let mut ok = true;
            for c in 0..26 {
                let other = total[c] - cnt[i][c];
                let need = mid * other + cnt[i][c];
                let have = m * other;
                if need > have {
                    ok = false;
                    break;
                }
            }
            if ok {
                lo = mid;
            } else {
                hi = mid - 1;
            }
        }

        if lo == 0 {
            let mut ok = true;
            for c in 0..26 {
                if cnt[i][c] > m * (total[c] - cnt[i][c]) {
                    ok = false;
                    break;
                }
            }
            if ok {
                print!("0 ");
            } else {
                print!("-1 ");
            }
        } else {
            print!("{} ", lo);
        }
    }
    println!();
}