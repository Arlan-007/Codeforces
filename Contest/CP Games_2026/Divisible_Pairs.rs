use std::collections::HashMap;
use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut it = input.split_whitespace();

    let t: usize = it.next().unwrap().parse().unwrap();
    let mut out = String::new();

    for _ in 0..t {
        let n: usize = it.next().unwrap().parse().unwrap();
        let x: i64 = it.next().unwrap().parse().unwrap();
        let y: i64 = it.next().unwrap().parse().unwrap();

        let mut mp: HashMap<(i64, i64), i64> = HashMap::new();
        let mut ans: i64 = 0;

        for _ in 0..n {
            let a: i64 = it.next().unwrap().parse().unwrap();

            let rx = a % x;
            let ry = a % y;

            let need = ((x - rx) % x, ry);

            if let Some(cnt) = mp.get(&need) {
                ans += *cnt;
            }

            *mp.entry((rx, ry)).or_insert(0) += 1;
        }

        out.push_str(&format!("{}\n", ans));
    }

    print!("{out}");
}