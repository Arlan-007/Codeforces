use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut iter = input.split_whitespace();
    let t: usize = iter.next().unwrap().parse().unwrap();

    for _ in 0..t {
        let n: usize = iter.next().unwrap().parse().unwrap();
        let k: i64 = iter.next().unwrap().parse().unwrap();
        let m: i64 = iter.next().unwrap().parse().unwrap();

        if m < k {
            println!("NO");
        } else {
            println!("YES");

            for _ in 0..n - 1 {
                print!("1 ");
            }
            println!("{}", m - k + 1);
        }
    }
}