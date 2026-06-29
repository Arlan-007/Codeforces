use std::io::{self, Read};

fn main() {
    let mut s = String::new();
    io::stdin().read_to_string(&mut s).unwrap();
    let mut it = s.split_whitespace();
    let t: usize = it.next().unwrap().parse().unwrap();

    for _ in 0..t {
        let n: usize = it.next().unwrap().parse().unwrap();

        let mut a = vec![0i64; n];
        let mut b = vec![0i64; n];

        for x in &mut a {
            *x = it.next().unwrap().parse().unwrap();
        }
        for x in &mut b {
            *x = it.next().unwrap().parse().unwrap();
        }

        let mut used = vec![false; n];
        let mut ans = 0i64;
        let mut ok = true;

        for &x in &a {
            let mut pos = None;

            for j in 0..n {
                if !used[j] && b[j] >= x {
                    pos = Some(j);
                    break;
                }
            }

            let j = match pos {
                Some(v) => v,
                None => {
                    ok = false;
                    break;
                }
            };

            for k in 0..j {
                if !used[k] {
                    ans += 1;
                }
            }

            used[j] = true;
        }

        println!("{}", if ok { ans } else { -1 });
    }
}