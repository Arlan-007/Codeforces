use std::io::{self, Read};

fn main() {
    let mut s = String::new();
    io::stdin().read_to_string(&mut s).unwrap();
    let mut it = s.split_whitespace().map(|x| x.parse::<i64>().unwrap());
    let t = it.next().unwrap();

    for _ in 0..t {
        let n = it.next().unwrap() as usize;
        let b: Vec<i64> = (0..n).map(|_| it.next().unwrap()).collect();

        let mut idx: Vec<usize> = (0..n).collect();
        idx.sort_by_key(|&i| b[i]);

        let mut a = vec![0i64; n];
        let mut prev = 0i64;
        let mut ok = b[idx[0]] == 0;

        let mut i = 0;
        while ok && i < n {
            let mut j = i;
            while j < n && b[idx[j]] == b[idx[i]] { j += 1; }
            let cnt = (j - i) as i64;

            let v;
            if j < n {
                let diff = b[idx[j]] - b[idx[i]];
                if diff % cnt != 0 {
                    ok = false;
                    break;
                }
                v = diff / cnt;
            } else {
                v = prev + 1;
            }

            if v <= prev {
                ok = false;
                break;
            }
            for &id in &idx[i..j] { a[id] = v; }
            prev = v;
            i = j;
        }

        if ok {
            let s: Vec<String> = a.iter().map(|x| x.to_string()).collect();
            println!("{}", s.join(" "));
        } else {
            println!("-1");
        }
    }
}