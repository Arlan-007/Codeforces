use std::collections::HashSet;
use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut it = input.split_whitespace();
    let t: usize = it.next().unwrap().parse().unwrap();

    for _ in 0..t {
        let n: usize = it.next().unwrap().parse().unwrap();
        let m: i32 = it.next().unwrap().parse().unwrap();
        let mut left = 0i32;
        let mut right = 0i32;
        let mut set = HashSet::new();

        for _ in 0..n {
            let x: i32 = it.next().unwrap().parse().unwrap();
            if x == -1 {
                left += 1;
            } else if x == -2 {
                right += 1;
            } else {
                set.insert(x);
            }
        }

        let mut pos: Vec<i32> = set.into_iter().collect();
        pos.sort_unstable();
        let k = pos.len() as i32;
        let mut ans = 0i32;

        ans = ans.max(k + left.min(m - k));
        ans = ans.max(k + right.min(m - k));

        for (i, &p) in pos.iter().enumerate() {
            let i = i as i32;
            let free_left = (p - 1) - i;
            let free_right = (m - p) - (k - i - 1);

            let cur = k + left.min(free_left) + right.min(free_right);
            ans = ans.max(cur);
        }
        println!("{}", ans.min(m));
    }
}