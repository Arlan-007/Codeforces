use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut iter = input.split_whitespace();
    let t: usize = iter.next().unwrap().parse().unwrap();

    for _ in 0..t {
        let a = iter.next().unwrap().as_bytes();
        let b = iter.next().unwrap().as_bytes();

        let n = a.len();
        let m = b.len();
        let mut pref_a = vec![0; n];
        let mut pref_b = vec![0; m];

        let mut sum = 0;
        for i in 0..n {
            sum = (sum + (a[i] - b'0') as i32) % 10;
            pref_a[i] = sum;
        }

        sum = 0;
        for i in 0..m {
            sum = (sum + (b[i] - b'0') as i32) % 10;
            pref_b[i] = sum;
        }

        if pref_a[n - 1] != pref_b[m - 1] {
            println!("-1");
            continue;
        }

        let mut prev = vec![0; m + 1];
        let mut cur = vec![0; m + 1];

        for i in 1..=n {
            for j in 1..=m {
                if pref_a[i - 1] == pref_b[j - 1] {
                    cur[j] = prev[j - 1] + 1;
                } else {
                    cur[j] = prev[j].max(cur[j - 1]);
                }
            }
            std::mem::swap(&mut prev, &mut cur);
            cur.fill(0);
        }
        println!("{}", prev[m]);
    }
}