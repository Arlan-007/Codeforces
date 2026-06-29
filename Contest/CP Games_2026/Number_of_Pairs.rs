use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut it = input.split_whitespace();

    let t: usize = it.next().unwrap().parse().unwrap();

    for _ in 0..t {
        let n: usize = it.next().unwrap().parse().unwrap();
        let l: i64 = it.next().unwrap().parse().unwrap();
        let r: i64 = it.next().unwrap().parse().unwrap();

        let mut a: Vec<i64> = (0..n)
            .map(|_| it.next().unwrap().parse().unwrap())
            .collect();

        a.sort_unstable();

        let mut ans: i64 = 0;

        for i in 0..n {
            let low = l - a[i];
            let high = r - a[i];

            let left = a[i + 1..].partition_point(|&x| x < low);
            let right = a[i + 1..].partition_point(|&x| x <= high);

            ans += (right - left) as i64;
        }

        println!("{}", ans);
    }
}