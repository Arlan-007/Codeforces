use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut it = input.split_whitespace();
    let t: usize = it.next().unwrap().parse().unwrap();

    for _ in 0..t {
        let n: usize = it.next().unwrap().parse().unwrap();
        let s: Vec<u8> = it.next().unwrap().bytes().collect();

        let mut blocks = 1;
        for i in 1..n {
            if s[i] != s[i - 1] {
                blocks += 1;
            }
        }

        let mut ans = blocks;

        for i in 1..n - 1 {
            if s[i] != s[i - 1] && s[i] != s[i + 1] {
                if s[i - 1] == s[i + 1] {
                    ans = blocks - 2;
                    break;
                } else {
                    ans = ans.min(blocks - 1);
                }
            }
        }

        println!("{}", ans);
    }
}