use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut it = input.split_whitespace();
    let t: usize = it.next().unwrap().parse().unwrap();

    for _ in 0..t {
        let n: usize = it.next().unwrap().parse().unwrap();
        let s = it.next().unwrap().as_bytes().to_vec();

        let total = (n as i64) * ((n + 1) as i64) / 2;
        let mut cnt = [0i64; 3];
        cnt[0] = 1;

        let mut pref = 0usize;
        for &c in &s {
            let val = if c == b'0' { 1 } else { 2 };
            pref = (pref + val) % 3;
            cnt[pref] += 1;
        }

        let mut zero = 0i64;
        for x in cnt {
            zero += x * (x - 1) / 2;
        }

        let non_zero = total - zero;
        let mut bad = 0i64;

        let mut l = 0usize;
        while l < n {
            let mut r = l;
            while r + 1 < n && s[r] != s[r + 1] {
                r += 1;
            }

            let m = (r - l + 1) as i64;
            bad += ((m - 1) * (m - 1)) / 4;
            l = r + 1;
        }
        println!("{}", non_zero - bad);
    }
}