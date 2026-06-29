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

        let mut ans = 0;
        let mut i = 0;

        while i < n {
            if s[i] == '1' {
                i += k + 1;
                continue;
            }

            let mut found = false;

            for j in i + 1..=(i + k).min(n - 1) {
                if s[j] == '1' {
                    i = j + k + 1;
                    found = true;
                    break;
                }
            }

            if !found {
                ans += 1;
                i += k + 1;
            }
        }

        println!("{}", ans);
    }
}