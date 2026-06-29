use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut it = input.split_whitespace();

    let n: usize = it.next().unwrap().parse().unwrap();

    let mut p = Vec::new();
    let mut have = vec![vec![false; 2001]; 2001];

    for _ in 0..n {
        let x: i32 = it.next().unwrap().parse().unwrap();
        let y: i32 = it.next().unwrap().parse().unwrap();

        p.push((x, y));
        have[(x + 1000) as usize][(y + 1000) as usize] = true;
    }

    let mut ans = 0i64;

    for i in 0..n {
        for j in 0..n {
            if i == j {
                continue;
            }

            let mx = 2 * p[j].0 - p[i].0;
            let my = 2 * p[j].1 - p[i].1;

            if (-1000..=1000).contains(&mx)
                && (-1000..=1000).contains(&my)
                && have[(mx + 1000) as usize][(my + 1000) as usize]
            {
                ans += 1;
            }
        }
    }

    println!("{}", ans / 2);
}