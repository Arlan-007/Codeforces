use std::collections::BTreeMap;
use std::io::{self, Read};

fn main() {
    let mut s = String::new();
    io::stdin().read_to_string(&mut s).unwrap();
    let mut it = s.split_whitespace().map(|x| x.parse::<i64>().unwrap());
    let t = it.next().unwrap();

    for _ in 0..t {
        let n = it.next().unwrap() as usize;
        let mut ms: BTreeMap<i64, usize> = BTreeMap::new();
        for _ in 0..n {
            *ms.entry(it.next().unwrap()).or_insert(0) += 1;
        }

        let mut cur = 0i64;
        let mut ans = Vec::with_capacity(n);
        for _ in 0..n {
            match ms.range(1 - cur..).next().map(|(&x, _)| x) {
                Some(x) => {
                    if *ms.get_mut(&x).map(|c| { *c -= 1; c }).unwrap() == 0 {
                        ms.remove(&x);
                    }
                    cur += x;
                    ans.push(cur.to_string());
                }
                None => break,
            }
        }

        if ans.len() == n {
            println!("{}", ans.join(" "));
        } else {
            println!("-1");
        }
    }
}