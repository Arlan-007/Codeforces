use std::io;

fn main() {
    let mut s = String::new();
    io::stdin().read_line(&mut s).unwrap();
    let n: usize = s.trim().parse().unwrap();

    if n < 3 {
        println!("-1");
        return;
    }

    if n == 3 {
        println!("210");
        return;
    }

    let mut rem = 1;
    for _ in 0..(n - 1) {
        rem = (rem * 10) % 210;
    }

    let end = (210 - rem) % 210;
    print!("1");

    for _ in 0..(n - 4) {
        print!("0");
    }

    println!("{:03}", end);
}