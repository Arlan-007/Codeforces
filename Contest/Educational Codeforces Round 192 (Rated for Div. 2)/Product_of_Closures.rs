use std::io::{self, Read};

fn bit_len(x: u64) -> usize {
    64 - x.leading_zeros() as usize
}

fn bit(x: u64, len: usize, pos: usize) -> u64 {
    (x >> (len - 1 - pos)) & 1
}

fn product_prefix(x: u64, y: u64, n: usize) -> String {
    let lx = bit_len(x);
    let ly = bit_len(y);
    let mut s = String::new();

    for i in 0..n {
        let a = bit(x, lx, i % lx);
        let b = bit(y, ly, i % ly);
        if a == 1 && b == 1 {
            s.push('1');
        } else {
            s.push('0');
        }
    }
    s
}

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut it = input.split_whitespace();
    let t: usize = it.next().unwrap().parse().unwrap();

    for _ in 0..t {
        let l: u64 = it.next().unwrap().parse().unwrap();
        let r: u64 = it.next().unwrap().parse().unwrap();
        let n: usize = it.next().unwrap().parse().unwrap();

        let mut cand: Vec<u64> = Vec::new();
        cand.push(l);
        loop {
            let mut now = *cand.last().unwrap();
            let mut lowbit = 1u64;
            while (now & lowbit) == 0 {
                lowbit <<= 1;
            }
            now += lowbit;
            if now <= r {
                cand.push(now);
            } else {
                break;
            }
        }

        let mut best = String::new();
        for i in 0..cand.len() {
            for j in i..cand.len() {
                let cur = product_prefix(cand[i], cand[j], n);
                if best.is_empty() || cur < best {
                    best = cur;
                }
            }
        }
        println!("{}", best);
    }
}