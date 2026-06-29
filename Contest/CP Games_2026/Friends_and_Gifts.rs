use std::io::{self, Read};

fn main() {
    let mut s = String::new();
    io::stdin().read_to_string(&mut s).unwrap();
    let mut it = s.split_whitespace();

    let n: usize = it.next().unwrap().parse().unwrap();
    let mut a: Vec<usize> = (0..n)
        .map(|_| it.next().unwrap().parse().unwrap())
        .collect();

    let mut used = vec![false; n];
    let mut zero = vec![];

    for i in 0..n {
        if a[i] == 0 {
            zero.push(i);
        } else {
            used[a[i] - 1] = true;
        }
    }

    let mut miss = vec![];
    for i in 0..n {
        if !used[i] {
            miss.push(i);
        }
    }

    let mut bad = vec![];

    for i in 0..zero.len() {
        a[zero[i]] = miss[i] + 1;
        if zero[i] == miss[i] {
            bad.push(i);
        }
    }

    if bad.len() == 1 {
        let b = bad[0];
        for i in 0..zero.len() {
            if i != b {
                a.swap(zero[i], zero[b]);
                break;
            }
        }
    } else if bad.len() > 1 {
        let vals: Vec<_> = bad.iter().map(|&i| a[zero[i]]).collect();
        let m = bad.len();

        for i in 0..m {
            a[zero[bad[i]]] = vals[(i + m - 1) % m];
        }
    }

    for x in a {
        print!("{} ", x);
    }
    println!();
}