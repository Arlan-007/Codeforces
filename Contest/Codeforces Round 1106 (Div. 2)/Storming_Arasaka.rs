use std::io::{self, Read};

const MAX: usize = 1_000_000;

fn main() {
    let mut spf = vec![0; MAX + 1];
    for i in 2..=MAX {
        if spf[i] == 0 {
            for j in (i..=MAX).step_by(i) {
                if spf[j] == 0 {
                    spf[j] = i;
                }
            }
        }
    }

    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut it = input.split_whitespace();
    let t: usize = it.next().unwrap().parse().unwrap();

    for _ in 0..t {
        let mut n: usize = it.next().unwrap().parse().unwrap();

        let mut total = 0;
        let mut distinct = 0;

        while n > 1 {
            let p = spf[n];
            distinct += 1;
            while n % p == 0 {
                n /= p;
                total += 1;
            }
        }
        println!("{}", total + distinct - 1);
    }
}