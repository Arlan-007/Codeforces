use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut s = input.trim().as_bytes().to_vec();
    let n = s.len();

    let mut cnt = [0usize; 256];
    for &ch in &s {
        cnt[ch as usize] += 1;
    }

    let mut best = 0usize;
    for i in 1..256 {
        if cnt[i] > cnt[best] {
            best = i;
        }
    }

    let mut f = vec![true; n + 1];
    if n >= 1 {
        f[1] = true;
    }
    for i in 2..=n {
        if f[i] {
            let mut j = i * i;
            while j <= n {
                f[j] = false;
                j += i;
            }
        }
    }
    for i in 2..=n / 2 {
        f[i] = false;
    }

    for i in 1..=n {
        if !f[i] {
            if cnt[best] == 0 {
                println!("NO");
                return;
            }
            s[i - 1] = best as u8;
            cnt[best] -= 1;
        }
    }

    let mut p = 0usize;
    for i in 1..=n {
        if f[i] {
            while p < 256 && cnt[p] == 0 {
                p += 1;
            }
            s[i - 1] = p as u8;
            cnt[p] -= 1;
        }
    }

    println!("YES");
    println!("{}", String::from_utf8(s).unwrap());
}