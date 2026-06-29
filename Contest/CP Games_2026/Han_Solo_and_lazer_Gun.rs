use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut it = input.split_whitespace();

    let n: usize = it.next().unwrap().parse().unwrap();
    let x0: i64 = it.next().unwrap().parse().unwrap();
    let y0: i64 = it.next().unwrap().parse().unwrap();

    let mut pts = Vec::with_capacity(n);

    for _ in 0..n {
        let x: i64 = it.next().unwrap().parse().unwrap();
        let y: i64 = it.next().unwrap().parse().unwrap();

        pts.push((x - x0, y - y0));
    }

    let mut used = vec![false; n];
    let mut ans = 0;

    for i in 0..n {
        if used[i] {
            continue;
        }

        ans += 1;
        used[i] = true;

        let (dx1, dy1) = pts[i];

        for j in (i + 1)..n {
            let (dx2, dy2) = pts[j];

            if dx1 * dy2 == dy1 * dx2 {
                used[j] = true;
            }
        }
    }

    println!("{}", ans);
}