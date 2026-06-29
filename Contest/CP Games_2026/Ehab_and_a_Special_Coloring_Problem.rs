use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();

    let n: usize = input.trim().parse().unwrap();

    let mut a = vec![0usize; n + 1];
    let mut c = 1;

    for i in 2..=n {
        if a[i] == 0 {
            for j in (i..=n).step_by(i) {
                if a[j] == 0 {
                    a[j] = c;
                }
            }
            c += 1;
        }
    }

    for i in 2..=n {
        print!("{} ", a[i]);
    }

    println!();
}