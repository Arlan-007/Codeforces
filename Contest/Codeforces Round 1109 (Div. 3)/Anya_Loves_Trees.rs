use std::io::{self, Read};

type Info = (i32, i32, i32, bool);

fn dfs(v: usize, ch: &Vec<Vec<usize>>, a: &Vec<i32>) -> Info {
    if ch[v].is_empty() {
        return (a[v], a[v], 1, true);
    }

    let mut mn = i32::MAX;
    let mut mx = i32::MIN;
    let mut cnt = 0;
    let mut ok = true;
    let mut child = Vec::new();

    for (i, &u) in ch[v].iter().enumerate() {
        let (l, r, c, good) = dfs(u, ch, a);
        mn = mn.min(l);
        mx = mx.max(r);
        cnt += c;
        ok &= good;
        child.push((l, r, i));
    }

    ok &= mx - mn + 1 == cnt;
    child.sort();
    for i in 1..child.len() {
        ok &= child[i - 1].1 + 1 == child[i].0;
    }

    let mut pos = vec![0; child.len()];
    for (i, &(_, _, idx)) in child.iter().enumerate() {
        pos[idx] = i;
    }
    for i in 1..pos.len() {
        ok &= pos[i] == (pos[i - 1] + 1) % pos.len();
    }

    (mn, mx, cnt, ok)
}

fn main() {
    let mut s = String::new();
    io::stdin().read_to_string(&mut s).unwrap();
    let mut it = s.split_whitespace();
    let t: usize = it.next().unwrap().parse().unwrap();
    let mut out = String::new();

    for _ in 0..t {
        let n: usize = it.next().unwrap().parse().unwrap();

        let mut ch = vec![Vec::new(); n + 1];
        for v in 2..=n {
            let p: usize = it.next().unwrap().parse().unwrap();
            ch[p].push(v);
        }
        let mut a = vec![0; n + 1];
        for i in 1..=n {
            a[i] = it.next().unwrap().parse().unwrap();
        }
        out.push_str(if dfs(1, &ch, &a).3 { "YES\n" } else { "NO\n" });
    }
    print!("{out}");
}