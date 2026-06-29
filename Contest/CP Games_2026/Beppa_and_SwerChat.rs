use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut it = input.split_whitespace();

    let t: usize = it.next().unwrap().parse().unwrap();
    let mut out = String::new();

    for _ in 0..t {
        let n: usize = it.next().unwrap().parse().unwrap();

        let mut pos = vec![0usize; n + 1];
        for i in 0..n {
            let x: usize = it.next().unwrap().parse().unwrap();
            pos[x] = i;
        }

        let mut b = vec![0usize; n];
        for i in 0..n {
            b[i] = it.next().unwrap().parse().unwrap();
        }

        let mut ans = 0usize;
        for i in (1..n).rev() {
            if pos[b[i - 1]] > pos[b[i]] {
                ans = i;
                break;
            }
        }

        out.push_str(&format!("{}\n", ans));
    }

    print!("{}", out);
}