use std::io::{self, Read};

fn main() {
    let mut s = String::new();
    io::stdin().read_to_string(&mut s).unwrap();
    let mut it = s.split_whitespace();

    let n: usize = it.next().unwrap().parse().unwrap();
    let mut sum = 0i64;
    let mut min_pos = i64::MAX;
    let mut max_neg = i64::MIN;

    for _ in 0..n {
        let x: i64 = it.next().unwrap().parse().unwrap();
        if x > 0 {
            sum += x;
            if x % 2 != 0 {
                min_pos = min_pos.min(x);
            }
        } else if x % 2 != 0 {
            max_neg = max_neg.max(x);
        }
    }

    if sum % 2 != 0 {
        println!("{}", sum);
    } else {
        let a = if min_pos == i64::MAX { i64::MIN } else { sum - min_pos };
        let b = if max_neg == i64::MIN { i64::MIN } else { sum + max_neg };
        println!("{}", a.max(b));
    }
}