use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut iter = input.split_whitespace();
    let t: usize = iter.next().unwrap().parse().unwrap();

    for _ in 0..t {
        let n: usize = iter.next().unwrap().parse().unwrap();

        let mut sum = 0i32;
        for _ in 0..n {
            let x: i32 = iter.next().unwrap().parse().unwrap();
            sum += x;
        }

        if n % 2 == 0 && sum % 4 == 0 {
            println!("YES");
        } else {
            println!("NO");
        }
    }
}