use std::io::{self, Read};

fn good(t: &[u8]) -> bool {
    let mut a = 0;
    let mut b = 0;
    let mut c = 0;

    for &x in t {
        match x {
            b'a' => a += 1,
            b'b' => b += 1,
            _ => c += 1,
        }
    }

    a > b && a > c
}

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut it = input.split_whitespace();

    let tc: usize = it.next().unwrap().parse().unwrap();

    for _ in 0..tc {
        let _n: usize = it.next().unwrap().parse().unwrap();
        let s = it.next().unwrap().as_bytes();

        let mut ans = 100;

        for i in 0..s.len() {
            for len in 2..=7 {
                if i + len <= s.len() && good(&s[i..i + len]) {
                    ans = ans.min(len);
                }
            }
        }

        if ans == 100 {
            println!("-1");
        } else {
            println!("{}", ans);
        }
    }
}