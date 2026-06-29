use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut it = input.split_whitespace();

    let t: usize = it.next().unwrap().parse().unwrap();

    for _ in 0..t {
        let n: usize = it.next().unwrap().parse().unwrap();
        let mut k: usize = it.next().unwrap().parse().unwrap();
        let s: Vec<char> = it.next().unwrap().chars().collect();

        let p = k % 2;
        let mut cnt = vec![0usize; n];
        let mut ans = vec!['0'; n];

        if p == 0 {
            for i in 0..n - 1 {
                if s[i] == '0' && k > 0 {
                    cnt[i] = 1;
                    k -= 1;
                }
            }
        } else {
            for i in 0..n - 1 {
                if s[i] == '1' && k > 0 {
                    cnt[i] = 1;
                    k -= 1;
                }
            }
        }

        cnt[n - 1] = k;

        for i in 0..n {
            let flips = if p == 0 {
                cnt[i] % 2
            } else {
                (cnt[i] + 1) % 2
            };

            let bit = (s[i] as u8 - b'0') ^ (flips as u8);
            ans[i] = (bit + b'0') as char;
        }

        println!("{}", ans.iter().collect::<String>());

        for i in 0..n {
            print!("{}{}", cnt[i], if i + 1 == n { '\n' } else { ' ' });
        }
    }
}