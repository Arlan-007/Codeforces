use std::io::{self, Read};

fn count_eq(a: &[i64], val: i64) -> usize {
    let l = a.partition_point(|&v| v < val);
    let r = a.partition_point(|&v| v <= val);
    r - l
}

fn nice(x: i64, a: &[i64], need: usize) -> bool {
    let get_4x = a.len() - a.partition_point(|&v| v < 4 * x);

    let good = get_4x
        + count_eq(a, x)
        + count_eq(a, 2 * x)
        + count_eq(a, 3 * x);

    good >= need
}

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut it = input.split_whitespace();

    let t: usize = it.next().unwrap().parse().unwrap();

    let mut out = String::new();

    for _ in 0..t {
        let n: usize = it.next().unwrap().parse().unwrap();
        let k: usize = it.next().unwrap().parse().unwrap();

        let mut a = vec![0i64; n];
        let mut mx = 0i64;
        for i in 0..n {
            a[i] = it.next().unwrap().parse().unwrap();
            mx = mx.max(a[i]);
        }

        a.sort_unstable();

        let need = n - k;
        let mut ans = 0i64;

        for x in 1..=mx {
            if nice(x, &a, need) {
                ans = x;
            }
        }

        out.push_str(&format!("{}\n", ans));
    }

    print!("{}", out);
}