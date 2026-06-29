use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut it = input.split_whitespace();
    let t: usize = it.next().unwrap().parse().unwrap();

    let mut c = [[0u64; 35]; 35];
    for i in 0..35 {
        c[i][0] = 1;
        c[i][i] = 1;
        for j in 1..i {
            c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
        }
    }

    for _ in 0..t {
        let n: u64 = it.next().unwrap().parse().unwrap();
        let k: i32 = it.next().unwrap().parse().unwrap();

        let d = 63 - n.leading_zeros() as usize;
        let mut good = 0u64;

        for p in 0..d {
            let limit = k - p as i32 - 1;
            if limit < 0 {
                continue;
            }
            let lim = limit.min(p as i32);
            for ones in 0..=lim {
                good += c[p][ones as usize];
            }
        }
        if (d as i32 + 1) <= k {
            good += 1;
        }
        println!("{}", n - good);
    }
}