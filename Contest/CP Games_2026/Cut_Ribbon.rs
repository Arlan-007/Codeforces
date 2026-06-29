use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut it = input.split_whitespace();

    let n: usize = it.next().unwrap().parse().unwrap();
    let a: usize = it.next().unwrap().parse().unwrap();
    let b: usize = it.next().unwrap().parse().unwrap();
    let c: usize = it.next().unwrap().parse().unwrap();

    let mut ans = 0usize;

    for x in 0..=n / a {
        for y in 0..=n / b {
            let used = x * a + y * b;
            if used > n {
                break;
            }

            let rem = n - used;
            if rem % c == 0 {
                let z = rem / c;
                ans = ans.max(x + y + z);
            }
        }
    }

    println!("{}", ans);
}