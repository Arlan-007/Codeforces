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

        for len in 1..=bit_len(r) {
            let group_l = 1u64 << (len - 1);
            let group_r = (1u64 << len) - 1;

            let left = l.max(group_l);
            let right = r.min(group_r);

            if left > right {
                continue;
            }

            cand.push(left);

            if left + 1 <= right {
                cand.push(left + 1);
            }

            for k in 0..len {
                let step = 1u64 << k;
                let x = ((left + step - 1) / step) * step;
                if x <= right {
                    cand.push(x);
                }
            }
        }

        cand.sort();
        cand.dedup();

        let mut best = String::new();
        for i in 0..cand.len() {
            for j in i + 1..cand.len() {
                let cur = product_prefix(cand[i], cand[j], n);

                if best.is_empty() || cur < best {
                    best = cur;
                }
            }
        }
        println!("{}", best);
    }
}