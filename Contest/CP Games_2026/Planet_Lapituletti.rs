use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut it = input.split_whitespace();

    let t: usize = it.next().unwrap().parse().unwrap();

    for _ in 0..t {
        let h: i32 = it.next().unwrap().parse().unwrap();
        let m: i32 = it.next().unwrap().parse().unwrap();

        let s = it.next().unwrap();
        let parts: Vec<_> = s.split(':').collect();

        let mut hh: i32 = parts[0].parse().unwrap();
        let mut mm: i32 = parts[1].parse().unwrap();

        loop {
            let d = |x: i32| -> i32 {
                match x {
                    0 => 0,
                    1 => 1,
                    2 => 5,
                    5 => 2,
                    8 => 8,
                    _ => -1,
                }
            };

            let h1 = hh / 10;
            let h2 = hh % 10;
            let m1 = mm / 10;
            let m2 = mm % 10;

            let a = d(m2);
            let b = d(m1);
            let c = d(h2);
            let d2 = d(h1);

            if a != -1 && b != -1 && c != -1 && d2 != -1 {
                let nh = a * 10 + b;
                let nm = c * 10 + d2;

                if nh < h && nm < m {
                    println!("{:02}:{:02}", hh, mm);
                    break;
                }
            }

            mm += 1;
            if mm == m {
                mm = 0;
                hh += 1;
                if hh == h {
                    hh = 0;
                }
            }
        }
    }
}