use std::io::{self, Read};

fn main() {
    let mut s = String::new();
    io::stdin().read_to_string(&mut s).unwrap();
    let mut it = s.split_whitespace();
    let t: usize = it.next().unwrap().parse().unwrap();

    for _ in 0..t {
        let n: usize = it.next().unwrap().parse().unwrap();

        let mut a = vec![0usize; n];
        for i in 0..n {
            a[i] = it.next().unwrap().parse::<usize>().unwrap() - 1;
        }

        let mut able = vec![vec![false; n]; n];
        for i in 0..n {
            let mut us = vec![false; n];
            let mut mn = a[i];
            let mut mx = a[i];
            for j in i..n {
                if us[a[j]] {
                    break;
                }
                us[a[j]] = true;
                mn = mn.min(a[j]);
                mx = mx.max(a[j]);
                if mx - mn == j - i {
                    able[mn][mx] = true;
                }
            }
        }

        let mut found = false;
        for ans in (1..=n / 2).rev() {
            for i in 0..=n - 2 * ans {
                if able[i][i + ans - 1] && able[i + ans][i + 2 * ans - 1] {
                    println!("{ans}");
                    found = true;
                    break;
                }
            }
            if found {
                break;
            }
        }
        if !found {
            println!("0");
        }
    }
}