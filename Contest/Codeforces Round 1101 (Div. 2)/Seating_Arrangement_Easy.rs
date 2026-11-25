use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut it = input.split_whitespace();

    let t: usize = it.next().unwrap().parse().unwrap();

    for _ in 0..t {
        let _n: usize = it.next().unwrap().parse().unwrap();
        let x: usize = it.next().unwrap().parse().unwrap();
        let s: usize = it.next().unwrap().parse().unwrap();
        let u = it.next().unwrap().chars().collect::<Vec<char>>();

        let mut dp = vec![-1i32; x + 1];
        dp[0] = 0;

        for i in u {
            let mut ndp = dp.clone();

            for tables in 0..=x {
                let people = dp[tables];
                if people < 0 {
                    continue;
                }

                if (i == 'I' || i == 'A') && tables < x {
                    ndp[tables + 1] = ndp[tables + 1].max(people + 1);
                }

                if (i == 'E' || i == 'A') && (people as usize) < tables * s {
                    ndp[tables] = ndp[tables].max(people + 1);
                }
            }

            dp = ndp;
        }

        println!("{}", dp.into_iter().max().unwrap());
    }
}