use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut it = input.split_whitespace();

    let t: usize = it.next().unwrap().parse().unwrap();

    for _ in 0..t {
        let n: usize = it.next().unwrap().parse().unwrap();

        let mut a = vec![0i64; n + 1];
        let mut cnt = vec![0i64; n + 1];

        for i in 1..=n {
            a[i] = it.next().unwrap().parse().unwrap();
            cnt[a[i] as usize] += 1;
        }

        let mut have = vec![0i64; n + 2];
        have[n] = cnt[n];

        for h in (1..n).rev() {
            have[h] = have[h + 1] + cnt[h];
        }

        let mut init: i64 = 0;
        let mut aft: i64 = 0;

        for i in 1..=n {
            init += (i as i64) * a[i];

            let c = have[i];
            aft += c * (2 * n as i64 - c + 1) / 2;
        }

        let cur = aft - init;

        let mut mx = 0i64;

        for i in 1..=n {
            let gain = i as i64 - n as i64 + have[a[i] as usize] - 1;
            mx = mx.max(gain);
        }

        println!("{}", cur + mx);
    }
}