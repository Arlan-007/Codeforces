use std::io::{self, Read};

const MAX: usize = 1_000_000;

fn main() {
    let mut spf = vec![0usize; MAX + 1];
    for i in 2..=MAX {
        if spf[i] == 0 {
            spf[i] = i;
            if i * i <= MAX {
                let mut j = i * i;
                while j <= MAX {
                    if spf[j] == 0 {
                        spf[j] = i;
                    }
                    j += i;
                }
            }
        }
    }

    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut it = input.split_whitespace();
    let t: usize = it.next().unwrap().parse().unwrap();

    for _ in 0..t {
        let n: usize = it.next().unwrap().parse().unwrap();
        let mut a = vec![0usize; n];

        for x in &mut a {
            *x = it.next().unwrap().parse().unwrap();
        }

        let mut sorted = true;
        for i in 1..n {
            if a[i - 1] > a[i] {
                sorted = false;
                break;
            }
        }
        if sorted {
            println!("Bob");
            continue;
        }

        let mut alice = false;
        let mut b = Vec::with_capacity(n);

        for &x0 in &a {
            if x0 == 1 {
                b.push(1);
                continue;
            }
            let mut x = x0;
            let first = spf[x];
            b.push(first);

            let mut distinct = 0;
            while x > 1 {
                let p = spf[x];
                distinct += 1;

                while x % p == 0 {
                    x /= p;
                }
            }
            if distinct >= 2 {
                alice = true;
            }
        }
        if alice {
            println!("Alice");
            continue;
        }

        let mut b_sorted = true;
        for i in 1..n {
            if b[i - 1] > b[i] {
                b_sorted = false;
                break;
            }
        }
        println!("{}", if b_sorted { "Bob" } else { "Alice" });
    }
}