use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut it = input.split_whitespace();
    let t: usize = it.next().unwrap().parse().unwrap();

    for _ in 0..t {
        let n: usize = it.next().unwrap().parse().unwrap();

        let mut xor = 0u32;
        let mut cnt = [0usize; 30];

        for _ in 0..n {
            let x: u32 = it.next().unwrap().parse().unwrap();
            xor ^= x;

            for b in 0..30 {
                if (x >> b) & 1 == 1 {
                    cnt[b] += 1;
                }
            }
        }

        if n == 1 {
            println!("0");
        } else if xor == 0 {
            println!("1");
        } else {
            let h = xor.ilog2() as usize;
            println!("{}", cnt[h]);
        }
    }
}