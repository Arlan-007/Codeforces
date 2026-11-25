use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut it = input.split_whitespace();

    let t: usize = it.next().unwrap().parse().unwrap();

    for _ in 0..t {
        let n: usize = it.next().unwrap().parse().unwrap();

        let mut a = Vec::with_capacity(n);
        for _ in 0..n {
            a.push(it.next().unwrap().parse::<i64>().unwrap());
        }

        a.sort();

        let med = a[n / 2];

        let mut l = 0usize;
        while a[l] < med {
            l += 1;
        }

        let mut r = n - 1;
        while a[r] > med {
            r -= 1;
        }

        println!("{}", l.max(n - 1 - r));
    }
}