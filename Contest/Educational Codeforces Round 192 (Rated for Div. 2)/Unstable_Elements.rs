use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut iter = input.split_whitespace();
    let t: usize = iter.next().unwrap().parse().unwrap();

    for _ in 0..t {
        let n: usize = iter.next().unwrap().parse().unwrap();
        let k: i64 = iter.next().unwrap().parse().unwrap();

        let mut runs = Vec::new();
        let mut prev = 0;
        let mut cnt = 0;

        for i in 0..n {
            let x: i64 = iter.next().unwrap().parse().unwrap();
            if i == 0 {
                prev = x;
                cnt = 1;
            } else if x == prev {
                cnt += 1;
            } else {
                runs.push(cnt);
                prev = x;
                cnt = 1;
            }
        }
        runs.push(cnt);
        runs.sort();
        let m = runs.len();

        let mut prefix = vec![0i64; m + 1];
        for i in 0..m {
            prefix[i + 1] = prefix[i] + runs[i];
        }

        let total = prefix[m];
        let mut ans = 0;
        let mut last = -1;

        for i in 0..m {
            if runs[i] == last {
                continue;
            }
            last = runs[i];

            let c = (m - i) as i64;
            let s = total - prefix[i];
            let rem = k - s;

            if rem % c == 0 {
                let p = rem / c;
                if p >= 1 - runs[i] {
                    ans += 1;
                }
            }
        }
        println!("{}", ans);
    }
}