use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut it = input.split_whitespace();

    let m: usize = it.next().unwrap().parse().unwrap();
    let s: i32 = it.next().unwrap().parse().unwrap();

    if (s == 0 && m > 1) || s > 9 * m as i32 {
        println!("-1 -1");
        return;
    }

    if m == 1 && s == 0 {
        println!("0 0");
        return;
    }

    let mut maxim = String::new();
    let mut rem = s;

    for _ in 0..m {
        let d = rem.min(9);
        maxim.push((b'0' + d as u8) as char);
        rem -= d;
    }

    let mut minim = String::new();
    let mut rem = s;

    for pos in 0..m {
        let start = if pos == 0 { 1 } else { 0 };

        for d in start..=9 {
            let left = m - pos - 1;
            let rem_sum = rem - d;

            if rem_sum >= 0 && rem_sum <= 9 * left as i32 {
                minim.push((b'0' + d as u8) as char);
                rem -= d;
                break;
            }
        }
    }

    println!("{} {}", minim, maxim);
}