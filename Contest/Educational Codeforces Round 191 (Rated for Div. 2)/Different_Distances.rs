use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut it = input.split_whitespace();

    let t: usize = it.next().unwrap().parse().unwrap();

    for _ in 0..t {
        let n: usize = it.next().unwrap().parse().unwrap();
        let k = [0usize, 1, 3, 6];
        let mut st = true;

        for &s in &k {
            for i in 0..n {
                let x = (i + s) % n + 1;
                if !st {
                    print!(" ");
                }
                st = false;
                print!("{}", x);
            }
        }

        println!();
    }
}