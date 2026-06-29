use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let n: usize = input.trim().parse().unwrap();

    if n == 1 {
        println!("a");
        println!("a");
        println!("b");
        println!("b");
        return;
    }

    let base = "aabbccdd".repeat(30);

    if n % 2 == 0 {
        let s1 = format!("e{}f", &base[..n - 2]);
        let s2 = format!("e{}f", &base[4..4 + n - 2]);
        let s3 = &base[..n];
        let s4 = &base[4..4 + n];

        println!("{s1}");
        println!("{s2}");
        println!("{s3}");
        println!("{s4}");
    } else {
        let s1 = format!("e{}", &base[..n - 1]);
        let s2 = format!("e{}", &base[4..4 + n - 1]);
        let s3 = format!("{}e", &base[..n - 1]);
        let s4 = format!("{}e", &base[4..4 + n - 1]);

        println!("{s1}");
        println!("{s2}");
        println!("{s3}");
        println!("{s4}");
    }
}