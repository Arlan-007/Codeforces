use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut it = input.split_whitespace();
    let n: usize = it.next().unwrap().parse().unwrap();
    let mut a: Vec<(i32, usize)> = Vec::with_capacity(n);
    for i in 0..n {
        let x: i32 = it.next().unwrap().parse().unwrap();
        a.push((x, i));
    }
    a.sort_by_key(|x| x.0);

    let p1: Vec<usize> = a.iter().map(|x| x.1).collect();
    let mut p2 = p1.clone();
    let mut p3 = p1.clone();
    let mut pairs = Vec::new();
    let mut triple = None;

    let mut i = 0;
    while i < n {
        let mut j = i;
        while j < n && a[j].0 == a[i].0 {
            j += 1;
        }
        let len = j - i;
        if len >= 2 {
            pairs.push(i);
        }
        if len >= 3 && triple.is_none() {
            triple = Some(i);
        }
        i = j;
    }

    if pairs.len() >= 2 {
        p2.swap(pairs[0], pairs[0] + 1);
        p3.swap(pairs[1], pairs[1] + 1);
    } else if let Some(i) = triple {
        p2.swap(i, i + 1);
        p3.swap(i + 1, i + 2);
    } else {
        println!("NO");
        return;
    }
    println!("YES");
    for p in [&p1, &p2, &p3] {
        for (i, &idx) in p.iter().enumerate() {
            if i > 0 {
                print!(" ");
            }
            print!("{}", idx + 1);
        }
        println!();
    }
}