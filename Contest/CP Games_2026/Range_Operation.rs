use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();

    let mut it = input.split_whitespace();

    let t: usize = it.next().unwrap().parse().unwrap();

    for _ in 0..t {
        let n: usize = it.next().unwrap().parse().unwrap();

        let mut s=0;
        let mut mn=0;
        let mut mx=0;

        for i in 0..n {
            let x: i64 = it.next().unwrap().parse().unwrap();

            s += x;
            let p = i as i64;
            let cur: i64 = (p+1)*(p+2) - s;
            mn = mn.min(cur);
            mx = mx.max(cur-mn);
        }

        println!("{}", s+mx);
    }
}