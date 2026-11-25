use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut it = input.split_whitespace();

    let t: usize = it.next().unwrap().parse().unwrap();

    for _ in 0..t {
        let n: usize = it.next().unwrap().parse().unwrap();
        let m: usize = it.next().unwrap().parse().unwrap();
        let l: usize = it.next().unwrap().parse().unwrap();

        let mut a = vec![0usize; n];
        for i in 0..n {
            a[i] = it.next().unwrap().parse().unwrap();
        }

        let mut lvls = vec![0i64; m];
        let mut curr = n;

        for time in 0..l {
            let idx = std::cmp::min(m, curr + 1) - 1;
            lvls[idx] += 1;

            lvls.sort_unstable_by(|x, y| y.cmp(x));

            if curr > 0 && a[n - curr] - 1 == time {
                lvls[0] = 0;
                lvls.sort_unstable_by(|x, y| y.cmp(x));
                curr -= 1;
            }
        }

        println!("{}", lvls[0]);
    }
}