use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut it = input.split_whitespace();
    let t: usize = it.next().unwrap().parse().unwrap();

    for _ in 0..t {
        let mut n: i64 = it.next().unwrap().parse().unwrap();
        let mut free = true;

        let mut p = 2;
        while (p as i64) * (p as i64) <= n {
            let mut cnt = 0;
            while n % p as i64 == 0 {
                n /= p as i64;
                cnt += 1;
            }
            if cnt >= 2 {
                free = false;
                break;
            }
            p += 1;
        }

        if free {
            println!("Bob");
        } else {
            println!("Alice");
        }
    }
}