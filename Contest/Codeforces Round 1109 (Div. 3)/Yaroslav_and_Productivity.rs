use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut it = input.split_whitespace();
    let t: usize = it.next().unwrap().parse().unwrap();

    for _ in 0..t {
        let n: usize = it.next().unwrap().parse().unwrap();
        let m: usize = it.next().unwrap().parse().unwrap();

        let mut a = vec![0_i64; n + 1];
        let mut pref = vec![0_i64; n + 1];

        for i in 1..=n {
            a[i] = it.next().unwrap().parse().unwrap();
            pref[i] = pref[i - 1] + a[i];
        }

        let mut b = Vec::new();
        for _ in 0..m {
            b.push(it.next().unwrap().parse::<usize>().unwrap());
        }

        b.sort();
        let mut ans = 0_i64;
        ans += (pref[b[0]] - pref[0]).abs();

        for i in 1..m {
            let l = b[i - 1] + 1;
            let r = b[i];
            ans += (pref[r] - pref[l - 1]).abs();
        }
        if b[m - 1] < n {
            ans += pref[n] - pref[b[m - 1]];
        }
        println!("{}", ans);
    }
}