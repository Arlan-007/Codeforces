use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();

    let mut it = input.split_whitespace();

    let n: usize = it.next().unwrap().parse().unwrap();
    let m = 32768;

    for _ in 0..n {
        let x: i32 = it.next().unwrap().parse().unwrap();

        let mut ans = 20;

        for add in 0..=15 {
            let cur = (x + add) % m;

            for mul in 0..=15 {
                if ((cur << mul) % m) == 0 {
                    ans = ans.min(add + mul);
                }
            }
        }

        print!("{} ", ans);
    }
}