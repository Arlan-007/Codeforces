use std::io::Read;

fn main() {
    let mut s = String::new();
    std::io::stdin().read_to_string(&mut s).unwrap();
    let mut it = s.split_whitespace();

    let t: usize = it.next().unwrap().parse().unwrap();
    let mut ans = String::new();

    for _ in 0..t {
        let n: usize = it.next().unwrap().parse().unwrap();

        let mut a = Vec::with_capacity(n);
        for _ in 0..n {
            a.push(it.next().unwrap().parse::<i64>().unwrap());
        }

        a.sort_unstable_by(|x, y| y.cmp(x));

        let mut ok = true;
        for i in 0..n - 2 {
            if a[i] % a[i + 1] != a[i + 2] {
                ok = false;
                break;
            }
        }

        if ok {
            ans.push_str(&format!("{} {}\n", a[0], a[1]));
        } else {
            ans.push_str("-1\n");
        }
    }

    print!("{ans}");
}