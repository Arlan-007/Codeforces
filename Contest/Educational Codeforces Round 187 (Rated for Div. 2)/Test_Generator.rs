use std::io::{self, Read};

fn can(s: u64, m: u64, n: u64) -> bool {
    let mut carry: i128 = 0;
    let n = n as i128;

    for i in (0..60).rev() {
        carry <<= 1;
        if ((s >> i) & 1) == 1 {
            carry += 1;
        }

        if ((m >> i) & 1) == 1 {
            let take = carry.min(n);
            carry -= take;
        }
    }
    carry == 0
}

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut it = input.split_whitespace();
    let t: usize = it.next().unwrap().parse().unwrap();
    let mut out = String::new();

    for _ in 0..t {
        let s: u64 = it.next().unwrap().parse().unwrap();
        let m: u64 = it.next().unwrap().parse().unwrap();

        if !can(s, m, 1u64 << 60) {
            out.push_str("-1\n");
            continue;
        }

        let mut l = 0u64;
        let mut r = 1u64 << 60;
        let mut ans = r;

        while l <= r {
            let mid = l + ((r - l) >> 1);
            if can(s, m, mid) {
                ans = mid;
                if mid == 0 {
                    break;
                }
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        out.push_str(&format!("{}\n", ans));
    }
    print!("{}", out);
}