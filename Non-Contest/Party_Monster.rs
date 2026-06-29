use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut it = input.split_whitespace();

    let t: usize = it.next().unwrap().parse().unwrap();

    for _ in 0..t {
        let _n: usize = it.next().unwrap().parse().unwrap();
        let str = it.next().unwrap();

        let mut ans: i32 = 0;
        for i in str.chars() {
            if i == '(' {
                ans = ans + 1;
            } else if i == ')' {
                ans = ans - 1;
            }
        }

        println!("{}", if ans == 0 { "YES" } else { "NO" });
    }

}