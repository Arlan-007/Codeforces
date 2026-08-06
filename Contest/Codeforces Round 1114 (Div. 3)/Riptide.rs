use std::io::{self, Read};

fn main() {
    let mut s = String::new();
    io::stdin().read_to_string(&mut s).unwrap();
    let mut it = s.split_whitespace();
    let t: usize = it.next().unwrap().parse().unwrap();

    for _ in 0..t {
        let mut a = [
            it.next().unwrap().parse::<i64>().unwrap(),
            it.next().unwrap().parse::<i64>().unwrap(),
            it.next().unwrap().parse::<i64>().unwrap(),
        ];
        a.sort();

        println!("{}", (a[1] - a[0]).min(a[2] - a[1]));
    }
}