use std::io::{self, Write};

fn ask(i: usize, j: usize) -> i64 {
    println!("? {} {}", i, j);
    io::stdout().flush().unwrap();
    let mut s = String::new();
    io::stdin().read_line(&mut s).unwrap();
    s.trim().parse().unwrap()
}

fn next_perm(a: &mut [i64]) -> bool {
    let n = a.len();
    let mut i = n - 2;
    while i > 0 && a[i] > a[i + 1] { i -= 1; }
    if i == 0 && a[i] > a[i + 1] {
        a.reverse();
        return false;
    }
    let mut j = n - 1;
    while a[j] < a[i] { j -= 1; }
    a.swap(i, j);
    a[i + 1..].reverse();
    true
}

fn main() {
    let p = [4, 8, 15, 16, 23, 42];
    let q = [ask(1, 2), ask(2, 3), ask(4, 5), ask(5, 6)];

    let mut a = p.to_vec();
    loop {
        if a[0] * a[1] == q[0] && a[1] * a[2] == q[1] && a[3] * a[4] == q[2] && a[4] * a[5] == q[3] {
            print!("! {} {} {} {} {} {}", a[0], a[1], a[2], a[3], a[4], a[5]);
            io::stdout().flush().unwrap();
            break;
        }
        if !next_perm(&mut a) {
            break;
        }
    }
}