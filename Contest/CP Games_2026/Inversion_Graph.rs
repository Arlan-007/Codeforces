use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut it = input.split_whitespace();

    let t: usize = it.next().unwrap().parse().unwrap();

    for _ in 0..t {
        let n: usize = it.next().unwrap().parse().unwrap();

        let mut mx = 0usize;
        let mut ans = 0;

        for i in 0..n {
            let x: usize = it.next().unwrap().parse().unwrap();
            mx = mx.max(x);

            if mx == i + 1 {
                ans += 1;
            }
        }

        println!("{}", ans);
    }
}