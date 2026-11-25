use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut it = input.split_whitespace();

    let t: usize = it.next().unwrap().parse().unwrap();

    for _ in 0..t {
        let n: usize = it.next().unwrap().parse().unwrap();
        let s = it.next().unwrap();

        let mut ccnt = [0i32; 10];
        for b in s.bytes() {
            ccnt[(b - b'0') as usize] += 1;
        }

        let mut l = 0;
        let mut r = n / 4 + 1;

        while l + 1 < r {
            let m = (l + r) / 2;

            let mut cnt = ccnt;
            let mut nh = 0;

            while cnt[0] > 0 && nh < m as i32 {
                cnt[0] -= 1;
                nh += 1;
            }

            while cnt[1] >= 2 && nh < m as i32 {
                cnt[1] -= 2;
                nh += 1;
            }

            let mut nm = 0;
            for i in 0..=5 {
                nm += cnt[i];
            }

            if nh >= m as i32 && nm >= m as i32 {
                l = m;
            } else {
                r = m;
            }
        }

        println!("{}", l);
    }
}