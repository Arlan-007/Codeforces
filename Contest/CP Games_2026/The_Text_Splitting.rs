use std::io;

fn main() {
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    let mut it = input.split_whitespace();
    let n: usize = it.next().unwrap().parse().unwrap();
    let p: usize = it.next().unwrap().parse().unwrap();
    let q: usize = it.next().unwrap().parse().unwrap();

    input.clear();
    io::stdin().read_line(&mut input).unwrap();
    let s = input.trim();

    for x in 0..=n / p {
        let rem = n - x * p;
        if rem % q == 0 {
            println!("{}", x + rem / q);
            let mut i = 0;
            for _ in 0..x {
                println!("{}", &s[i..i + p]);
                i += p;
            }
            for _ in 0..rem / q {
                println!("{}", &s[i..i + q]);
                i += q;
            }
            return;
        }
    }
    println!("-1");
}