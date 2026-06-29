use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut it = input.split_whitespace();

    let t: usize = it.next().unwrap().parse().unwrap();

    for _ in 0..t {
        let n: usize = it.next().unwrap().parse().unwrap();

        let mut a = Vec::with_capacity(n);
        for _ in 0..n {
            a.push(it.next().unwrap().parse::<i64>().unwrap());
        }

        let mut sum = 0;
        let mut v = Vec::with_capacity(n);
        for i in 0..n {
            sum += a[i];
            let k = i as i64;
            v.push(sum/(k+1));
        }

        print!("{} ", v[0]);
        for i in 1..n {
            v[i] = v[i].min(v[i-1]);
            print!("{} ", v[i]);
        }
        println!();

    }
}