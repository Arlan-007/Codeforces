use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut it = input.split_whitespace();
    let t: usize = it.next().unwrap().parse().unwrap();

    for _ in 0..t {
        let n: usize = it.next().unwrap().parse().unwrap();
        let k: usize = it.next().unwrap().parse().unwrap();
        let s: Vec<char> = it.next().unwrap().chars().collect();

        if 2 * k > n {
            println!("-1");
            continue;
        }
        let mut ans = 0;
        for i in 0..k {
            if s[i] == 'L' {
                ans += 1;
            }
        }
        for i in n - k..n {
            if s[i] == 'R' {
                ans += 1;
            }
        }
        println!("{}", ans);
    }
}