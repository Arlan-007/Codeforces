use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut it = input.split_whitespace();
    let t: usize = it.next().unwrap().parse().unwrap();

    for _ in 0..t {
        let n: usize = it.next().unwrap().parse().unwrap();

        let mut sum = 0i64;
        let mut ok = true;
        for i in 1..=n {
            let x: i64 = it.next().unwrap().parse().unwrap();
            sum += x;
            let need = (i as i64) * ((i + 1) as i64) / 2;
            if sum < need {
                ok = false;
            }
        }

        if ok {
            println!("YES");
        } else {
            println!("NO");
        }
    }
}