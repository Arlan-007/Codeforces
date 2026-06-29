use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut it = input.split_whitespace();
    let t: usize = it.next().unwrap().parse().unwrap();

    for _ in 0..t {
        let n: usize = it.next().unwrap().parse().unwrap();
        let mut p = Vec::with_capacity(n);

        let mut min_x = i64::MAX;
        let mut min2_x = i64::MAX;
        let mut max_x = i64::MIN;
        let mut max2_x = i64::MIN;
        let mut cnt_min_x = 0;
        let mut cnt_max_x = 0;

        let mut min_y = i64::MAX;
        let mut min2_y = i64::MAX;
        let mut max_y = i64::MIN;
        let mut max2_y = i64::MIN;
        let mut cnt_min_y = 0;
        let mut cnt_max_y = 0;

        for _ in 0..n {
            let x: i64 = it.next().unwrap().parse().unwrap();
            let y: i64 = it.next().unwrap().parse().unwrap();

            p.push((x, y));

            if x < min_x {
                min2_x = min_x;
                min_x = x;
                cnt_min_x = 1;
            } else if x == min_x {
                cnt_min_x += 1;
            } else if x < min2_x {
                min2_x = x;
            }

            if x > max_x {
                max2_x = max_x;
                max_x = x;
                cnt_max_x = 1;
            } else if x == max_x {
                cnt_max_x += 1;
            } else if x > max2_x {
                max2_x = x;
            }

            if y < min_y {
                min2_y = min_y;
                min_y = y;
                cnt_min_y = 1;
            } else if y == min_y {
                cnt_min_y += 1;
            } else if y < min2_y {
                min2_y = y;
            }

            if y > max_y {
                max2_y = max_y;
                max_y = y;
                cnt_max_y = 1;
            } else if y == max_y {
                cnt_max_y += 1;
            } else if y > max2_y {
                max2_y = y;
            }
        }

        if n == 1 {
            println!("1");
            continue;
        }

        let mut ans = i64::MAX;

        for &(x, y) in &p {
            let mnx = if x == min_x && cnt_min_x == 1 {
                min2_x
            } else {
                min_x
            };

            let mxx = if x == max_x && cnt_max_x == 1 {
                max2_x
            } else {
                max_x
            };

            let mny = if y == min_y && cnt_min_y == 1 {
                min2_y
            } else {
                min_y
            };

            let mxy = if y == max_y && cnt_max_y == 1 {
                max2_y
            } else {
                max_y
            };

            let w = mxx - mnx + 1;
            let h = mxy - mny + 1;
            let area = w * h;

            let cur = if area >= n as i64 {
                area
            } else {
                ((w + 1) * h).min(w * (h + 1))
            };

            ans = ans.min(cur);
        }

        println!("{}", ans);
    }
}