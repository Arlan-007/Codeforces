use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut it = input.split_whitespace();

    let t: usize = it.next().unwrap().parse().unwrap();

    for _ in 0..t {
        let n: usize = it.next().unwrap().parse().unwrap();
        let m: usize = it.next().unwrap().parse().unwrap();

        for i in 0..n {
            for j in 0..m {
                if i%2 == 0 {
                    print!("{} " , (n / 2 + i / 2) * m + j + 1);
                }
                else {
                    print!("{} " , (i / 2) * m + j + 1);
                }
            }
            println!("");
        }
    }
}