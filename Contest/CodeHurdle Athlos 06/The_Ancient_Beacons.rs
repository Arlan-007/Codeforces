use std::io::{self, Read};

fn stable(x: u64, k: u32) -> bool {
    x.count_ones() >= k
}

fn start(b: &[bool], i: usize) -> i64 {
    if b[i] && (i == 0 || !b[i - 1]) { 1 } else { 0 }
}

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut it = input.split_whitespace();
    let t: usize = it.next().unwrap().parse().unwrap();
    let mut out = String::new();

    for _ in 0..t {
        let n: usize = it.next().unwrap().parse().unwrap();
        let q: usize = it.next().unwrap().parse().unwrap();
        let k: u32 = it.next().unwrap().parse().unwrap();

        let mut a = vec![0u64; n];
        for i in 0..n {
            a[i] = it.next().unwrap().parse().unwrap();
        }

        let mut b: Vec<bool> = a.iter().map(|&x| stable(x, k)).collect();

        let mut ans = 0i64;
        for i in 0..n {
            ans += start(&b, i);
        }

        for _ in 0..q {
            let typ: u32 = it.next().unwrap().parse().unwrap();
            if typ == 3 {
                out.push_str(&format!("{}\n", ans));
                continue;
            }

            let i: usize = it.next().unwrap().parse::<usize>().unwrap() - 1;
            let x: u64 = it.next().unwrap().parse().unwrap();

            ans -= start(&b, i);
            if i + 1 < n {
                ans -= start(&b, i + 1);
            }

            if typ == 1 {
                a[i] |= x;
            } else {
                a[i] ^= x;
            }

            b[i] = stable(a[i], k);
            ans += start(&b, i);
            if i + 1 < n {
                ans += start(&b, i + 1);
            }
        }
    }
    print!("{}", out);
}