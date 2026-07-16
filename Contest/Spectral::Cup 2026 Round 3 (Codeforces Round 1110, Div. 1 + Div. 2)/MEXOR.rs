use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut it = input.split_whitespace();
    let t: usize = it.next().unwrap().parse().unwrap();

    for _ in 0..t {
        let n: i64 = it.next().unwrap().parse().unwrap();
        let k: i64 = it.next().unwrap().parse().unwrap();

        let b = 64 - (n as u64).leading_zeros() as i64;
        let x = k ^ n;

        if k >= (1_i64 << b) || ((n as u64).is_power_of_two() && x >= n) {
            println!("NO");
            continue;
        }
        println!("YES");

        let mut ans = Vec::new();
        if x == 0 {
            for i in 1..n {
                ans.push(i);
            }
            ans.push(0);
        } else if x < n {
            for i in 1..n {
                if i != x {
                    ans.push(i);
                }
            }
            ans.push(0);
            ans.push(x);
        } else {
            let v = 1_i64 << (b - 1);
            let w = x ^ v;
            let lo = v.min(w);
            let hi = v.max(w);

            for i in 1..n {
                if i != lo && i != hi {
                    ans.push(i);
                }
            }
            ans.push(0);
            ans.push(lo);
            ans.push(hi);
        }

        for (i, val) in ans.iter().enumerate() {
            if i > 0 {
                print!(" ");
            }
            print!("{}", val);
        }
        println!();
    }
}