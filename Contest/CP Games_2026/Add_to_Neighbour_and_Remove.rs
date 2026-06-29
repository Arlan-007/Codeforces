use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut it = input.split_whitespace();

    let t: usize = it.next().unwrap().parse().unwrap();

    for _ in 0..t {
        let n: usize = it.next().unwrap().parse().unwrap();

        let mut a = vec![0i64; n];
        let mut sum = 0i64;

        for i in 0..n {
            a[i] = it.next().unwrap().parse().unwrap();
            sum += a[i];
        }

        let mut ans = n - 1;

        for k in 0..n {
            let parts = n - k;

            if sum % parts as i64 != 0 {
                continue;
            }

            let need = sum / parts as i64;
            let mut cur = 0i64;
            let mut ok = true;

            for &x in &a {
                cur += x;

                if cur == need {
                    cur = 0;
                } else if cur > need {
                    ok = false;
                    break;
                }
            }

            if ok && cur == 0 {
                ans = k;
                break;
            }
        }

        println!("{}", ans);
    }
}