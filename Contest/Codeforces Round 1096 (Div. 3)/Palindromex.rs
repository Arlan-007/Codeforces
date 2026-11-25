use std::io::{self, Read};

fn main() {
    let mut s = String::new();
    io::stdin().read_to_string(&mut s).unwrap();
    let mut it = s.split_whitespace();

    let t: usize = it.next().unwrap().parse().unwrap();
    let mut out = String::new();

    for _ in 0..t {
        let n: usize = it.next().unwrap().parse().unwrap();
        let m = 2 * n;

        let mut v = vec![0usize; m];
        let mut z = Vec::with_capacity(2);

        for i in 0..m {
            v[i] = it.next().unwrap().parse().unwrap();
            if v[i] == 0 {
                z.push(i);
            }
        }

        let mut ans = 0;

        for &(mut l, mut r) in &[
            (z[0], z[0]),
            (z[1], z[1]),
            ((z[0] + z[1]) / 2, (z[0] + z[1] + 1) / 2),
        ] {
            let mut seen = vec![false; n + 1];

            while l < m && r < m && v[l] == v[r] {
                seen[v[l]] = true;
                if l == 0 || r + 1 == m {
                    break;
                }
                l -= 1;
                r += 1;
            }

            let mut mex = 0;
            while mex <= n && seen[mex] {
                mex += 1;
            }
            ans = ans.max(mex);
        }

        out.push_str(&format!("{}\n", ans));
    }

    print!("{}", out);
}