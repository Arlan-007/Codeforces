use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut it = input.split_whitespace();
    let t: usize = it.next().unwrap().parse().unwrap();

    for _ in 0..t {
        let n: usize = it.next().unwrap().parse().unwrap();
        let mut res = Vec::new();

        if n == 1 {
            res.push("1".to_string());
        } else if n == 3 {
            res.push("169".to_string());
            res.push("961".to_string());
            res.push("196".to_string());
        } else {
            let mut cur = vec!["169".to_string(), "961".to_string(), "196".to_string()];

            let mut size = 3;
            while size < n {
                size += 2;
                cur = cur.iter().map(|s| format!("{}00", s)).collect();

                let z = (size - 3) / 2;
                let zeros = "0".repeat(z);
                cur.push(format!("9{}6{}1", zeros, zeros));
                cur.push(format!("1{}6{}9", zeros, zeros));
            }
            res = cur;
        }

        for s in res {
            println!("{} ", s);
        }
    }
}