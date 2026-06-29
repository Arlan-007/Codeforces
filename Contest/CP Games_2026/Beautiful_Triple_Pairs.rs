use std::collections::HashMap;
use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut it = input.split_whitespace();

    let t: usize = it.next().unwrap().parse().unwrap();

    for _ in 0..t {
        let n: usize = it.next().unwrap().parse().unwrap();

        let mut a = vec![0i64; n];
        for x in &mut a {
            *x = it.next().unwrap().parse().unwrap();
        }

        let mut mask_cnt: HashMap<(i64, i64, i64), i64> = HashMap::new();
        let mut trip_cnt: HashMap<(i64, i64, i64), i64> = HashMap::new();

        let mut ans = 0i64;

        for i in 0..n - 2 {
            let t = (a[i], a[i + 1], a[i + 2]);

            ans += mask_cnt.get(&(0, t.1, t.2)).copied().unwrap_or(0)
                - trip_cnt.get(&t).copied().unwrap_or(0);

            ans += mask_cnt.get(&(t.0, 0, t.2)).copied().unwrap_or(0)
                - trip_cnt.get(&t).copied().unwrap_or(0);

            ans += mask_cnt.get(&(t.0, t.1, 0)).copied().unwrap_or(0)
                - trip_cnt.get(&t).copied().unwrap_or(0);

            *mask_cnt.entry((0, t.1, t.2)).or_insert(0) += 1;
            *mask_cnt.entry((t.0, 0, t.2)).or_insert(0) += 1;
            *mask_cnt.entry((t.0, t.1, 0)).or_insert(0) += 1;

            *trip_cnt.entry(t).or_insert(0) += 1;
        }

        println!("{}", ans);
    }
}