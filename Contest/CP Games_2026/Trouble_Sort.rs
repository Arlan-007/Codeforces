use std::io::{self, Read};

fn is_sorted(a: &[i64]) -> bool {
    for i in 1..a.len() {
        if a[i] < a[i-1] {
            return false;
        }
    }
    true
}

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut it = input.split_whitespace();

    let t: usize = it.next().unwrap().parse().unwrap();
    let mut out = String::new();

    for _ in 0..t {
        let n: usize = it.next().unwrap().parse().unwrap();

        let mut a = vec![0i64; n];
        for i in 0..n {
            a[i] = it.next().unwrap().parse().unwrap();
        }

        let mut b = vec![0i32; n];
        let mut has0 = false;
        let mut has1 = false;
        for i in 0..n {
            b[i] = it.next().unwrap().parse().unwrap();
            if b[i] == 0 {
                has0 = true;
            } else {
                has1 = true;
            }
        }

        let ok = if has0 && has1 {
            true
        } else {
            is_sorted(&a)
        };

        out.push_str(if ok { "Yes\n" } else { "No\n" });
    }

    print!("{out}");
}