use std::io::{self, Read};

fn main() {
    let mut s = String::new();
    io::stdin().read_to_string(&mut s).unwrap();
    let mut it = s.split_whitespace();
    let t: usize = it.next().unwrap().parse().unwrap();
    let mut out = String::new();

    for _ in 0..t {
        let n: usize = it.next().unwrap().parse().unwrap();
        let m: usize = it.next().unwrap().parse().unwrap();
        let mut a = vec![0u8; n * m];
        let mut ones = 0usize;
        for i in 0..n * m {
            let x: u8 = it.next().unwrap().parse().unwrap();
            a[i] = x;
            ones += x as usize;
        }

        let mut need = ones / 2;
        let mut r = 0usize;
        let mut c = 0usize;
        let mut found = false;
        'outer: for i in 0..n {
            for j in (0..m).rev() {
                if a[i * m + j] == 1 {
                    need -= 1;
                    if need == 0 {
                        r = i;
                        c = j;
                        found = true;
                        break 'outer;
                    }
                }
            }
        }

        let ans = (ones / 2) * ((ones + 1) / 2);
        let mut path = String::new();
        if c == 0 {
            for _ in 0..=r { path.push('D'); }
            for _ in 0..m { path.push('R'); }
            for _ in 0..(n - r - 1) { path.push('D'); }
        } else {
            for _ in 0..r { path.push('D'); }
            for _ in 0..c { path.push('R'); }
            path.push('D');
            for _ in 0..(m - c) { path.push('R'); }
            for _ in 0..(n - r - 1) { path.push('D'); }
        }
        out.push_str(&format!("{}\n{}\n", ans, path));
    }
    print!("{}", out);
}