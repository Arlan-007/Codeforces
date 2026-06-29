use std::io::{self, Read};

fn id(s: &str) -> usize {
    match s {
        "Anka" => 0,
        "Chapay" => 1,
        "Cleo" => 2,
        "Dracul" => 3,
        "Hexadecimal" => 4,
        "Snowy" => 5,
        "Troll" => 6,
        _ => unreachable!(),
    }
}

fn main() {
    let mut s = String::new();
    io::stdin().read_to_string(&mut s).unwrap();
    let mut it = s.split_whitespace();

    let n: usize = it.next().unwrap().parse().unwrap();
    let mut like = [[0i64; 7]; 7];

    for _ in 0..n {
        let a = id(it.next().unwrap());
        it.next();
        let b = id(it.next().unwrap());
        like[a][b] = 1;
    }

    let exp = [
        it.next().unwrap().parse::<i64>().unwrap(),
        it.next().unwrap().parse::<i64>().unwrap(),
        it.next().unwrap().parse::<i64>().unwrap(),
    ];

    let mut best = (i64::MAX, -1i64);

    for m in 0..2187 {
        let mut x = m;
        let mut t = [0usize; 7];
        let mut cnt = [0usize; 3];

        for i in 0..7 {
            t[i] = x % 3;
            cnt[t[i]] += 1;
            x /= 3;
        }

        if cnt.iter().any(|&c| c == 0) {
            continue;
        }

        let mut mn = i64::MAX;
        let mut mx = 0i64;

        for k in 0..3 {
            let total = exp[k];
            let per = total / cnt[k] as i64;
            mn = mn.min(per);
            mx = mx.max(per);
        }

        let diff = mx - mn;

        let mut score = 0i64;
        for i in 0..7 {
            for j in 0..7 {
                if t[i] == t[j] {
                    score += like[i][j];
                }
            }
        }

        if diff < best.0 || (diff == best.0 && score > best.1) {
            best = (diff, score);
        }
    }

    println!("{} {}", best.0, best.1);
}