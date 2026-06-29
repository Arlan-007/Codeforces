use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut it = input.split_whitespace();
    let t: usize = it.next().unwrap().parse().unwrap();

    for _ in 0..t {
        let n: usize = it.next().unwrap().parse().unwrap();
        let k: usize = it.next().unwrap().parse().unwrap();
        let s = it.next().unwrap().as_bytes();
        let open = s.iter().filter(|&&x| x == b'(').count();

        let (mut min, mut ans) = (usize::MAX, vec![]);

        for c in 0..=k {
            let d = k - c;
            if c > open || d > n - open {
                continue;
            }

            let mut rm = vec!['0'; n];
            let (mut rc, mut rd) = (c, d);
            for i in 0..n {
                if s[i] == b'(' && rc > 0 {
                    rm[i] = '1';
                    rc -= 1;
                }
            }
            for i in (0..n).rev() {
                if s[i] == b')' && rd > 0 {
                    rm[i] = '1';
                    rd -= 1;
                }
            }

            let (mut cost, mut cur) = (0, 0);
            for i in 0..n {
                if rm[i] == '0' {
                    if s[i] == b'(' { cur += 1; } else if cur > 0 {
                        cur -= 1;
                        cost += 1;
                    }
                }
            }

            if cost < min {
                min = cost;
                ans = rm;
            }
        }

        println!("{}", ans.iter().collect::<String>());
    }
}