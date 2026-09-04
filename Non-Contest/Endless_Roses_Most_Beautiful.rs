use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut it = input.split_whitespace();
    let n: usize = it.next().unwrap().parse().unwrap();
    let k: usize = it.next().unwrap().parse().unwrap();

    let val: Vec<i32> = (0..n).map(|_| it.next().unwrap().parse().unwrap()).collect();
    let colors: Vec<char> = it.next().unwrap().chars().collect();

    let mut w = vec![];
    let mut o = vec![];
    let mut r = vec![];

    for i in 0..colors.len() {
        if colors[i] == 'W' { w.push(val[i]); }
        if colors[i] == 'O' { o.push(val[i]); }
        if colors[i] == 'R' { r.push(val[i]); }
    }

    w.sort_by(|a, b| b.cmp(a));
    o.sort_by(|a, b| b.cmp(a));
    r.sort_by(|a, b| b.cmp(a));

    let mut ans = -1;
    for i in 1..k {
        let j = k - i;
        if i <= w.len() && j <= o.len() {
            ans = ans.max(w[..i].iter().sum::<i32>() + o[..j].iter().sum::<i32>());
        }
        if i <= o.len() && j <= r.len() {
            ans = ans.max(o[..i].iter().sum::<i32>() + r[..j].iter().sum::<i32>());
        }
    }

    println!("{}", ans);
}