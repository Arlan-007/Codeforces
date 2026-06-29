use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut it = input.split_whitespace();

    let n: usize = it.next().unwrap().parse().unwrap();

    let seq = [4, 8, 15, 16, 23, 42];
    let mut cnt = [0usize; 6];

    for _ in 0..n {
        let x: i32 = it.next().unwrap().parse().unwrap();

        for i in 0..6 {
            if x == seq[i] {
                if i == 0 {
                    cnt[0] += 1;
                } else if cnt[i - 1] > cnt[i] {
                    cnt[i] += 1;
                }
                break;
            }
        }
    }

    let removed = n - cnt[5] * 6;
    println!("{}", removed);
}