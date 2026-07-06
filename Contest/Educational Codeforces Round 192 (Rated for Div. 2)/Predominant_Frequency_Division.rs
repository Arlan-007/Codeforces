use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut it = input.split_whitespace();
    let t: usize = it.next().unwrap().parse().unwrap();

    for _ in 0..t {
        let n: usize = it.next().unwrap().parse().unwrap();

        let mut pref1 = vec![0i32; n];
        let mut pref2 = vec![0i32; n];

        for i in 0..n {
            let x: i32 = it.next().unwrap().parse().unwrap();

            let w1 = if x == 1 { 1 } else { -1 };
            let w2 = if x == 3 { -1 } else { 1 };

            if i == 0 {
                pref1[i] = w1;
                pref2[i] = w2;
            } else {
                pref1[i] = pref1[i - 1] + w1;
                pref2[i] = pref2[i - 1] + w2;
            }
        }

        let mut suf_max = vec![i32::MIN; n];
        suf_max[n - 2] = pref2[n - 2];
        for i in (0..n - 2).rev() {
            suf_max[i] = suf_max[i + 1].max(pref2[i]);
        }

        let mut ok = false;
        for i in 0..=n - 3 {
            if pref1[i] >= 0 && suf_max[i + 1] >= pref2[i] {
                ok = true;
                break;
            }
        }
        println!("{}", if ok { "YES" } else { "NO" });
    }
}