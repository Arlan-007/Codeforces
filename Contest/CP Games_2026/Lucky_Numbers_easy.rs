use std::io::{self, Read};

fn nxnum(len: usize, half: usize, pos: usize, cur: i64, fours: usize, out: &mut Vec<i64>) {
    if pos == len {
        if fours == half {
            out.push(cur);
        }
        return;
    }

    if fours < half {
        nxnum(len, half, pos + 1, cur * 10 + 4, fours + 1, out);
    }

    if pos - fours < half {
        nxnum(len, half, pos + 1, cur * 10 + 7, fours, out);
    }
}

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let n: i64 = input.trim().parse().unwrap();

    let mut ans = i64::MAX;

    for len in 1..=18 {
        if len % 2 != 0 {
            continue;
        }

        let mut nums = Vec::new();
        nxnum(len, len / 2, 0, 0, 0, &mut nums);

        for x in nums {
            if x >= n && x < ans {
                ans = x;
            }
        }
    }

    println!("{}", ans);
}