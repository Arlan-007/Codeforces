use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut it = input.split_whitespace();
    let t: usize = it.next().unwrap().parse().unwrap();

    for _ in 0..t {
        let n: usize = it.next().unwrap().parse().unwrap();
        let c: i64 = it.next().unwrap().parse().unwrap();

        let mut a = Vec::with_capacity(n);
        let mut ans = -c * n as i64;
        for _ in 0..n {
            let x: i64 = it.next().unwrap().parse().unwrap();
            ans += x;
            a.push(x);
        }
        a.sort();

        for i in 0..n / 2 {
            if a[i] < c {
                ans += c - a[i];
            } else {
                break;
            }
        }
        println!("{}", ans);
    }
}