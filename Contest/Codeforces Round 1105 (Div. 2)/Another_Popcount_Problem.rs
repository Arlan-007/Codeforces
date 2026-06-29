use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut it = input.split_whitespace();
    let t: i64 = it.next().unwrap().parse().unwrap();

    for _ in 0..t {
        let n: i64 = it.next().unwrap().parse().unwrap();
        let k: i64 = it.next().unwrap().parse().unwrap();

        let mut lo = 0i64;
        let mut hi = 20 * k;

        while lo < hi {
            let mid = (lo + hi + 1) / 2;

            let q = mid / k;
            let r = mid % k;
            let cost = ((k + r) << q) - k;

            if cost <= n {
                lo = mid;
            } else {
                hi = mid - 1;
            }
        }

        println!("{}", lo);
    }
}