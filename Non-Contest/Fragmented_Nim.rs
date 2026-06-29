use std::io::{self, Read};

fn main() {
    let mut s = String::new();
    io::stdin().read_to_string(&mut s).unwrap();
    let mut it = s.split_whitespace();

    let t: usize = it.next().unwrap().parse().unwrap();
    let mut out = String::new();

    for _ in 0..t {
        let n: usize = it.next().unwrap().parse().unwrap();
        let mut ones = 0;
        let mut big = false;

        for _ in 0..n {
            let x: i64 = it.next().unwrap().parse().unwrap();
            if x == 1 { ones += 1; } else { big = true; }
        }

        let moves = ones + big as i32;
        out.push_str(if moves % 2 == 1 { "Alice\n" } else { "Bob\n" });
    }

    print!("{}", out);
}