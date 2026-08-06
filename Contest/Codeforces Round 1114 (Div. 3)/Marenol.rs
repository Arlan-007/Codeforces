use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut it = input.split_whitespace();
    let t: usize = it.next().unwrap().parse().unwrap();

    for _ in 0..t {
        let n: usize = it.next().unwrap().parse().unwrap();
        let a = it.next().unwrap().as_bytes();
        let b = it.next().unwrap().as_bytes();

        let mut pa = [Vec::<i64>::new(), Vec::<i64>::new()];
        let mut pb = [Vec::<i64>::new(), Vec::<i64>::new()];

        for i in 0..n {
            if a[i] == b'1' {
                pa[i % 2].push(i as i64);
            }
            if b[i] == b'1' {
                pb[i % 2].push(i as i64);
            }
        }

        if pa[0].len() != pb[0].len() || pa[1].len() != pb[1].len() {
            println!("-1");
            continue;
        }

        let mut ans = 0i64;

        for p in 0..2 {
            for i in 0..pa[p].len() {
                ans += (pa[p][i] - pb[p][i]).abs() / 2;
            }
        }

        println!("{}", ans);
    }
}