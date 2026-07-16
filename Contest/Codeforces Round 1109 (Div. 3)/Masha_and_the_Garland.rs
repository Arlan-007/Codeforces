use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut it = input.split_whitespace();
    let t: usize = it.next().unwrap().parse().unwrap();
    let mut out = String::new();

    for _ in 0..t {
        let n: usize = it.next().unwrap().parse().unwrap();
        let q: usize = it.next().unwrap().parse().unwrap();

        let s = it.next().unwrap().as_bytes();
        let mut c = vec![0u8; n + 1];

        for i in 1..=n {
            let bit = s[i - 1] - b'0';
            c[i] = bit ^ ((i & 1) as u8);
        }

        let mut pref1 = vec![0usize; n + 1];
        let mut pref0 = vec![0usize; n + 1];

        for i in 1..=n {
            pref1[i] = pref1[i - 1];
            pref0[i] = pref0[i - 1];
            if c[i] == 1 && (i == 1 || c[i - 1] == 0) {
                pref1[i] += 1;
            }
            if c[i] == 0 && (i == 1 || c[i - 1] == 1) {
                pref0[i] += 1;
            }
        }

        for _ in 0..q {
            let l: usize = it.next().unwrap().parse().unwrap();
            let r: usize = it.next().unwrap().parse().unwrap();
            let k: usize = it.next().unwrap().parse().unwrap();

            let mut one = pref1[r] - pref1[l - 1];
            if l > 1 && c[l] == 1 && c[l - 1] == 1 {
                one += 1;
            }
            let mut zero = pref0[r] - pref0[l - 1];
            if l > 1 && c[l] == 0 && c[l - 1] == 0 {
                zero += 1;
            }

            if one.min(zero) <= k {
                out.push_str("YES\n");
            } else {
                out.push_str("NO\n");
            }
        }
    }
    print!("{}", out);
}