use std::io::{self, Read};

const MAX: usize = 1_000_000;

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut it = input.split_whitespace();

    let t: usize = it.next().unwrap().parse().unwrap();

    for _ in 0..t {
        let n: usize = it.next().unwrap().parse().unwrap();
        let m: usize = it.next().unwrap().parse().unwrap();

        let mut freq = vec![0usize; n + m + 1];
        let mut mult = vec![0usize; n + m + 1];
        let mut b = vec![0usize; m];

        for _ in 0..n {
            let x: usize = it.next().unwrap().parse().unwrap();
            freq[x] += 1;
        }

        for i in 1..n + m + 1 {
            for j in (i..=n + m).step_by(i) {
                mult[j] += freq[i];
            }
        }

        let mut alice = 0usize;
        let mut bob = 0usize;
        let mut common = 0usize;

        for i in 0..m {
            b[i] = it.next().unwrap().parse().unwrap();
        }


        for x in b {
            if mult[x] == 0 {
                bob += 1;
            } else if mult[x] == n {
                alice += 1;
            } else {
                common += 1;
            }
        }

    if alice + (common + 1) / 2 > bob + common / 2 {
            println!("Alice");
        } else {
            println!("Bob");
        }
    }
}