use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut it = input.split_whitespace();

    let mut s: Vec<char> = it.next().unwrap().chars().collect();
    let mut k: usize = it.next().unwrap().parse().unwrap();

    let n = s.len();

    for i in 0..n {
        if k == 0 {
            break;
        }

        let mut pos = i;

        for j in (i + 1)..=std::cmp::min(n - 1, i + k) {
            if s[j] > s[pos] {
                pos = j;
            }
        }

        let cost = pos - i;

        for j in (i + 1..=pos).rev() {
            s.swap(j, j - 1);
        }

        k -= cost;
    }

    let ans: String = s.into_iter().collect();
    println!("{}", ans);
}