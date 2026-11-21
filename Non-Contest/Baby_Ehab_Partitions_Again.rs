use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut it = input.split_whitespace();
    let n: usize = it.next().unwrap().parse().unwrap();

    let mut dp = vec![false; 100001]; dp[0] = true;
    let (mut sum, mut best, mut pos) = (0, u32::MAX, 0);
    for i in 1..=n {
        let x: usize = it.next().unwrap().parse().unwrap();
        sum += x;

        for s in (x..=sum.min(100000)).rev() {
            dp[s] |= dp[s - x];
        }

        let zeros = x.trailing_zeros();
        if zeros < best {
            best = zeros;
            pos = i;
        }
    }

    if sum % 2 == 0 && dp[sum / 2] {
        println!("1\n{}", pos);
    } else {
        println!("0");
    }
}