use std::io;

fn main() {
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();

    let mut it = input.split_whitespace();

    let n: i32 = it.next().unwrap().parse().unwrap();
    let x1: i32 = it.next().unwrap().parse().unwrap();
    let y1: i32 = it.next().unwrap().parse().unwrap();
    let x2: i32 = it.next().unwrap().parse().unwrap();
    let y2: i32 = it.next().unwrap().parse().unwrap();

    let mut a = 0;
    if y1 == 0 {
        a = x1;
    } else if x1 == n {
        a = n + y1;
    } else if y1 == n {
        a = 3 * n - x1;
    } else {
        a = 4 * n - y1;
    }

    let mut b = 0;
    if y2 == 0 {
        b = x2;
    } else if x2 == n {
        b = n + y2;
    } else if y2 == n {
        b = 3 * n - x2;
    } else {
        b = 4 * n - y2;
    }

    let d = (a - b).abs();
    println!("{}", d.min(4 * n - d));
}