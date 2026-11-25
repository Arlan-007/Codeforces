use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();

    let mut it = input.split_whitespace();
    let t: usize = it.next().unwrap().parse().unwrap();

    for _ in 0..t {
        let n: usize = it.next().unwrap().parse().unwrap();

        let mut a = vec![0i32; n];

        for i in 0..n {
            a[i] = it.next().unwrap().parse().unwrap();
        }

        let mut sum: i32 = a.iter()
            .filter(|&&x| x != 1)
            .sum();

        if *a.last().unwrap() == 1 {
            sum += 1;
        }

        println!("{}", sum);
    }
}