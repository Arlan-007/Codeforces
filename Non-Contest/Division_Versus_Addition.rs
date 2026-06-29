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

        let mut pref_log = vec![0i64; n + 1];
        let mut pref_type1 = vec![0i64; n + 1];
        let mut pref_type2 = vec![0i64; n + 1];

        for i in 1..=n {
            let x: u64 = it.next().unwrap().parse().unwrap();

            let lg = 63 - x.leading_zeros() as i64;
            pref_log[i] = pref_log[i - 1] + lg;

            let is_pow2 = x.count_ones() == 1;
            let is_pow2_minus1 = !is_pow2 && x > 1 && (x - 1).count_ones() == 1;
            pref_type1[i] = pref_type1[i - 1] + if is_pow2_minus1 { 1 } else { 0 };
            pref_type2[i] = pref_type2[i - 1] + if !is_pow2 && !is_pow2_minus1 { 1 } else { 0 };
        }

        for _ in 0..q {
            let l: usize = it.next().unwrap().parse().unwrap();
            let r: usize = it.next().unwrap().parse().unwrap();

            let base = pref_log[r] - pref_log[l - 1];
            let cnt1 = pref_type1[r] - pref_type1[l - 1];
            let cnt2 = pref_type2[r] - pref_type2[l - 1];

            let ans = base + cnt2 + cnt1 / 2;
            out.push_str(&format!("{}\n", ans));
        }
    }

    print!("{}", out);
}