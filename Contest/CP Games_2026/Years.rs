use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut it = input.split_whitespace();

    let n: usize = it.next().unwrap().parse().unwrap();

    let mut pop: Vec<(i64, i64)> = Vec::with_capacity(2 * n);

    for _ in 0..n {
        let b: i64 = it.next().unwrap().parse().unwrap();
        let d: i64 = it.next().unwrap().parse().unwrap();

        pop.push((b, 1));
        pop.push((d, -1));
    }

    pop.sort_unstable_by_key(|&(year, _)| year);

    let mut alive: i64 = 0;
    let mut count: i64 = 0;
    let mut yr: i64 = 0;

    let mut i = 0;
    while i < pop.len() {
        let year = pop[i].0;
        let mut delta = 0i64;

        while i < pop.len() && pop[i].0 == year {
            delta += pop[i].1;
            i += 1;
        }

        alive += delta;

        if alive > count {
            count = alive;
            yr = year;
        }
    }

    println!("{} {}", yr, count);
}