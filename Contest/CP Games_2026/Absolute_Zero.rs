use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();

    let mut it = input.split_whitespace();

    let t: usize = it.next().unwrap().parse().unwrap();

    for _ in 0..t {
        let n: i64 = it.next().unwrap().parse().unwrap();

        let mut o = false;
        let mut e = false;

        for _ in 0..n {
            let x: i64 = it.next().unwrap().parse().unwrap();
            if x % 2 == 0 { e = true; } else { o = true; }
        }

        if o && e {
            println!("-1");
        } else {
            let mut v = Vec::new();
            for i in (0..30).rev() {
                v.push(1 << i);
            }
            if e {
                v.push(1);
            }

            println!("{}", v.len());
            for x in v {
                print!("{} ", x);
            }
            println!();
        }
    }
}