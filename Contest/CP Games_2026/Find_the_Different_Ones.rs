use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut it = input.split_whitespace();

    let t: usize = it.next().unwrap().parse().unwrap();
    let mut out = String::new();

    for _ in 0..t {
        let n: usize = it.next().unwrap().parse().unwrap();

        let mut a = vec![0i32; n];
        for i in 0..n {
            a[i] = it.next().unwrap().parse().unwrap();
        }

        let mut p = vec![-1isize; n];

        for i in 1..n {
            p[i] = p[i - 1];

            if a[i] != a[i - 1] {
                p[i] = (i - 1) as isize;
            }
        }

        let q: usize = it.next().unwrap().parse().unwrap();

        for _ in 0..q {
            let l: usize = it.next().unwrap().parse::<usize>().unwrap() - 1;
            let r: usize = it.next().unwrap().parse::<usize>().unwrap() - 1;

            if p[r] < l as isize {
                out.push_str("-1 -1\n");
            } else {
                out.push_str(&format!("{} {}\n", p[r] + 1, r as isize + 1));
            }
        }

        out.push('\n');
    }

    print!("{out}");
}