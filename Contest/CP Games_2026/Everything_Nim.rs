use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut it = input.split_whitespace();

    let t: usize = it.next().unwrap().parse().unwrap();

    for _ in 0..t {
        let n: usize = it.next().unwrap().parse().unwrap();

        let mut a = Vec::with_capacity(n);
        for _ in 0..n {
            a.push(it.next().unwrap().parse::<i64>().unwrap());
        }

        a.sort_unstable();
        a.dedup();

        let mut len = 0usize;
        while len < a.len() && a[len] == (len as i64) + 1 {
            len += 1;
        }

        let Wins = if len == a.len() {
            len % 2 == 1
        } else {
            len % 2 == 0
        };

        println!("{}", if Wins { "Alice" } else { "Bob" });
    }
}