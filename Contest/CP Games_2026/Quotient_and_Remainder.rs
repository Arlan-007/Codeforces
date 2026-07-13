use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut it = input.split_whitespace();
    let t: usize = it.next().unwrap().parse().unwrap();

    for _ in 0..t {
        let n: usize = it.next().unwrap().parse().unwrap();
        let k: i64 = it.next().unwrap().parse().unwrap();

        let mut q = Vec::with_capacity(n);
        let mut r = Vec::with_capacity(n);

        for _ in 0..n {
            q.push(it.next().unwrap().parse::<i64>().unwrap());
        }
        for _ in 0..n {
            r.push(it.next().unwrap().parse::<i64>().unwrap());
        }

        q.sort();
        r.sort();

        let mut lo = 0;
        let mut hi = n;

        while lo < hi {
            let mid = (lo + hi + 1) / 2;
            let mut ok = true;
            for i in 0..mid {
                if (q[i] + 1) * (r[mid - 1 - i] + 1) > k + 1 {
                    ok = false;
                    break;
                }
            }
            if ok {
                lo = mid;
            } else {
                hi = mid - 1;
            }
        }
        println!("{}", lo);
    }
}