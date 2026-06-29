use std::io::{self, Read};

fn check(a:usize) -> bool {
    let mut n: usize = a;
    while n != 1 {
        if n%3 == 0 {
            n /= 3;
        }
        else {
            n -= 1;
            if n%3 == 0 {
                n /= 3;
            }
            else {
                return false;
            }
        }
    }
    return true;
}

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut it = input.split_whitespace();

    let q: usize = it.next().unwrap().parse().unwrap();

    for _ in 0..q {
        let mut n: usize = it.next().unwrap().parse().unwrap();
        while !check(n) {
            n += 1;
        }
        println!("{}", n);
    }
}