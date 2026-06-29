use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut it = input.split_whitespace();

    let t: usize = it.next().unwrap().parse().unwrap();

    for _ in 0..t {
        let n: i32 = it.next().unwrap().parse().unwrap();
        let rk: i32 = it.next().unwrap().parse().unwrap();
        let ck: i32 = it.next().unwrap().parse().unwrap();
        let rd: i32 = it.next().unwrap().parse().unwrap();
        let cd: i32 = it.next().unwrap().parse().unwrap();

        let mut ans = 0;

        if rd > rk {
            ans = ans.max(rd);
        } else if rd < rk {
            ans = ans.max(n - rd);
        }

        if cd > ck {
            ans = ans.max(cd);
        } else if cd < ck {
            ans = ans.max(n - cd);
        }

        println!("{}", ans);
    }
}