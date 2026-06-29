use std::io::{self, Read};

fn next(x: i64) -> i64 {
    x + x % 10
}

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut it = input.split_whitespace();

    let t: usize = it.next().unwrap().parse().unwrap();

    for _ in 0..t {
        let n: usize = it.next().unwrap().parse().unwrap();

        let mut a = vec![0i64; n];
        let mut flag = false;

        for i in 0..n {
            a[i] = it.next().unwrap().parse().unwrap();

            if a[i] % 5 == 0 {
                flag = true;
                a[i] = next(a[i]);
            }
        }

        if flag {
            let mn = *a.iter().min().unwrap();
            let mx = *a.iter().max().unwrap();

            println!("{}", if mn == mx { "Yes" } else { "No" });
        } else {
            let mut flag2 = false;
            let mut flag3 = false;

            for &v in &a {
                let mut x = v;

                while x % 10 != 2 {
                    x = next(x);
                }

                if x % 20 == 2 {
                    flag2 = true;
                } else {
                    flag3 = true;
                }
            }

            println!(
                "{}",
                if flag2 && flag3 { "No" } else { "Yes" }
            );
        }
    }
}