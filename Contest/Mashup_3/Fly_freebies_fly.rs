use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut it = input.split_whitespace();

    let n: usize = it.next().unwrap().parse().unwrap();
    let mut t = Vec::new();
    for _ in 0..n {
        let t_: i64 = it.next().unwrap().parse().unwrap();
        t.push(t_);
    }
    let mut T : i64 = it.next().unwrap().parse().unwrap();
    t.sort();


    let mut max_cnt = 0;

    for i in 0..n {
        let mut cnt = 0;
        for j in i..n {
            if t[j] - t[i] <= T {
                cnt += 1;
            } else {
                break;
            }
        }
        max_cnt = max_cnt.max(cnt);
    }

    println!("{}", max_cnt);

}