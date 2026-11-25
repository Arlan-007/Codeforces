use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut it = input.split_whitespace();

    let n: usize = it.next().unwrap().parse().unwrap();
    let d: usize = it.next().unwrap().parse().unwrap();

    let mut a = vec![0usize; n + 1];
    let mut pos_a = vec![0usize; n + 1];

    for i in 1..=n {
        a[i] = it.next().unwrap().parse().unwrap();
        pos_a[a[i]] = i;
    }

    let mut b = vec![0usize; n + 1];
    let mut pos_b = vec![0usize; n + 1];

    for i in 1..=n {
        b[i] = it.next().unwrap().parse().unwrap();
        pos_b[b[i]] = i;
    }

    let mut c = vec![0i64; n + 1];
    for i in 1..=n {
        c[i] = pos_a[b[i]] as i64;
    }

    let nn = n as i64;

    let contrib = |i: usize, c: &Vec<i64>| -> i64 {
        if i == 1 {
            c[1] - 1
        } else {
            (c[i] - c[i - 1] - 1).rem_euclid(nn)
        }
    };

    let mut ans: i64 = 0;
    for i in 1..=n {
        ans += contrib(i, &c);
    }

    println!("{}", ans);

    for _ in 0..d - 1 {
        let typ: i32 = it.next().unwrap().parse().unwrap();
        let x: usize = it.next().unwrap().parse().unwrap();
        let y: usize = it.next().unwrap().parse().unwrap();

        let mut affected: Vec<usize> = Vec::new();

        if typ == 1 {
            let sx = a[x];
            let sy = a[y];

            let i = pos_b[sx];
            let j = pos_b[sy];

            for p in [i, i + 1, j, j + 1] {
                if p >= 1 && p <= n {
                    affected.push(p);
                }
            }

            affected.sort_unstable();
            affected.dedup();

            for &p in &affected {
                ans -= contrib(p, &c);
            }

            c.swap(i, j);

            for &p in &affected {
                ans += contrib(p, &c);
            }

            a.swap(x, y);
            pos_a[sx] = y;
            pos_a[sy] = x;
        } else {
            for p in [x, x + 1, y, y + 1] {
                if p >= 1 && p <= n {
                    affected.push(p);
                }
            }

            affected.sort_unstable();
            affected.dedup();

            for &p in &affected {
                ans -= contrib(p, &c);
            }

            c.swap(x, y);

            for &p in &affected {
                ans += contrib(p, &c);
            }

            let sx = b[x];
            let sy = b[y];

            b.swap(x, y);
            pos_b[sx] = y;
            pos_b[sy] = x;
        }

        println!("{}", ans);
    }
}