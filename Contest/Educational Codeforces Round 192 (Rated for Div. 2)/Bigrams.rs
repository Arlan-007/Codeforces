use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut iter = input.split_whitespace();
    let t: usize = iter.next().unwrap().parse().unwrap();

    for _ in 0..t {
        let k: usize = iter.next().unwrap().parse().unwrap();

        let mut two = 0;
        let mut three = false;

        for _ in 0..k {
            let c: i64 = iter.next().unwrap().parse().unwrap();

            if c >= 3 {
                three = true;
            }
            if c >= 2 {
                two += 1;
            }
        }

        if three || two >= 2 {
            println!("YES");
        } else {
            println!("NO");
        }
    }
}