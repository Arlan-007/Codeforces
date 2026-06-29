use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut it = input.split_whitespace();

    let t: usize = it.next().unwrap().parse().unwrap();

    for _ in 0..t {
        let n: usize = it.next().unwrap().parse().unwrap();
        let x: usize = it.next().unwrap().parse().unwrap();

        if n % x != 0 {
            println!("-1");
            continue;
        }

        let mut p: Vec<usize> = (1..=n).collect();

        if x == n {
            p[0] = n;
            p[n - 1] = 1;
        } else {
            p[0] = x;
            p[n - 1] = 1;
            p[x - 1] = n;

            let mut cur = x - 1;

            for i in 1..n - 1 {
                if p[cur] % (i + 1) == 0 && p[i] % (cur + 1) == 0 {
                    p.swap(i, cur);
                    cur = i;
                }
            }
        }

        for (i, v) in p.iter().enumerate() {
            if i > 0 {
                print!(" ");
            }
            print!("{}", v);
        }
        println!();
    }
}