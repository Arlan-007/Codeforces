use std::io::{self, Read};

fn main() {
    let mut s = String::new();
    io::stdin().read_to_string(&mut s).unwrap();
    let mut it = s.split_whitespace();

    let t: usize = it.next().unwrap().parse().unwrap();

    for _ in 0..t {
        let n: i32 = it.next().unwrap().parse().unwrap();

        let mut mx = [-1_000_000_000; 4];
        let mut mn = [ 1_000_000_000; 4];

        for i in 0..n {
            let row = it.next().unwrap().as_bytes();

            for j in 0..n {
                if row[j as usize] == b'#' {
                    let v = [i, j, i + j, i - j];

                    for k in 0..4 {
                        mx[k] = mx[k].max(v[k]);
                        mn[k] = mn[k].min(v[k]);
                    }
                }
            }
        }

        let ok =
            (mx[0] - mn[0] <= 1 && mx[1] - mn[1] <= 1) ||
                (mx[2] - mn[2] <= 1) ||
                (mx[3] - mn[3] <= 1);

        println!("{}", if ok { "YES" } else { "NO" });
    }
}