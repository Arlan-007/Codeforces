use std::io::{self, Read};

const MAXN: usize = 10000001;

fn main() {
    let mut prime = vec![true; MAXN];
    prime[0] = false;
    prime[1] = false;

    let mut i = 2;
    while i * i < MAXN {
        if prime[i] {
            let mut j = i * i;
            while j < MAXN {
                prime[j] = false;
                j += i;
            }
        }
        i += 1;
    }

    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut it = input.split_whitespace();

    let t: usize = it.next().unwrap().parse().unwrap();

    for _ in 0..t {
        let n: usize = it.next().unwrap().parse().unwrap();

        let mut ans: usize = 0;
        for i in 2..=n {
            if prime[i] {
                ans += n / i;
            }
        }

        println!("{}", ans);
    }
}