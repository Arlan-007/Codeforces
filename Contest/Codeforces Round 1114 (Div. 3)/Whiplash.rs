use std::io::{self, Read};
use std::collections::BTreeMap;

fn main() {
    let mut s = String::new();
    io::stdin().read_to_string(&mut s).unwrap();
    let mut it = s.split_whitespace().map(|x| x.parse::<i64>().unwrap());
    let t = it.next().unwrap();

    for _ in 0..t {
        let n = it.next().unwrap() as usize;
        let a: Vec<i64> = (0..n).map(|_| it.next().unwrap()).collect();
        let b: Vec<i64> = (0..n).map(|_| it.next().unwrap()).collect();
        let xa = a.iter().fold(0, |acc, &x| acc ^ x);
        let xb = b.iter().fold(0, |acc, &x| acc ^ x);

        let mut ma: BTreeMap<i64, usize> = BTreeMap::new(); *ma.entry(xa).or_insert(0) += 1;
        let mut mb: BTreeMap<i64, usize> = BTreeMap::new(); *mb.entry(xb).or_insert(0) += 1;
        for i in 0..n {
            *ma.entry(a[i] ^ xa).or_insert(0) += 1;
        }
        for i in 0..n {
            *mb.entry(b[i] ^ xb).or_insert(0) += 1;
        }

        if ma == mb {
            println!("YES");
        } else {
            println!("NO");
        }
    }
}