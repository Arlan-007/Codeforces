use std::io::{self, Read};

fn main() {
    let mut s = String::new();
    io::stdin().read_to_string(&mut s).unwrap();
    let mut it = s.split_whitespace();
    let t: usize = it.next().unwrap().parse().unwrap();

    for _ in 0..t {
        let n: usize = it.next().unwrap().parse().unwrap();
        let mut par = vec![0; n + 1];
        let mut g = vec![Vec::new(); n + 1];
        let mut a = vec![0; n + 1];

        for i in 2..=n {
            let p: usize = it.next().unwrap().parse().unwrap();
            par[i] = p;
            g[p].push(i);
        }
        for i in 1..=n {
            a[i] = it.next().unwrap().parse().unwrap();
        }

        let mut rem = vec![0; n + 1];
        let mut mn = vec![0; n + 1];
        let mut mx = vec![0; n + 1];
        let mut cnt = vec![0; n + 1];
        let mut ok = vec![true; n + 1];
        let mut st = Vec::new();

        for i in 1..=n {
            rem[i] = g[i].len();
            if rem[i] == 0 {
                mn[i] = a[i];
                mx[i] = a[i];
                cnt[i] = 1;
                st.push(i);
            }
        }

        while let Some(v) = st.pop() {
            if v == 1 {
                continue;
            }
            let p = par[v];
            rem[p] -= 1;
            if rem[p] != 0 {
                continue;
            }

            let mut lo = i32::MAX;
            let mut hi = i32::MIN;
            let mut c = 0;
            let mut good = true;
            for &u in &g[p] {
                good &= ok[u];
                lo = lo.min(mn[u]);
                hi = hi.max(mx[u]);
                c += cnt[u];
            }
            if hi - lo + 1 != c {
                good = false;
            }
            if g[p].len() > 1 {
                let mut bad = 0;
                for i in 0..g[p].len() {
                    let x = g[p][i];
                    let y = g[p][(i + 1) % g[p].len()];
                    if mx[x] + 1 != mn[y] {
                        bad += 1;
                    }
                }
                good &= bad == 1;
            }

            mn[p] = lo;
            mx[p] = hi;
            cnt[p] = c;
            ok[p] = good;
            st.push(p);
        }
        println!("{}", if ok[1] { "YES" } else { "NO" });
    }
}