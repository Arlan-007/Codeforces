use std::io::{self, Read};

fn min_largest_pile(a: Vec<i64>) -> i64 {
    let mut stack: Vec<i64> = Vec::new();

    for mut x in a {
        while let Some(&top) = stack.last() {
            if top > x {
                x += top;
                stack.pop();
            } else {
                break;
            }
        }
        stack.push(x);
    }
    *stack.iter().max().unwrap()
}

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut it = input.split_whitespace();
    let t: usize = it.next().unwrap().parse().unwrap();

    for _ in 0..t {
        let n: usize = it.next().unwrap().parse().unwrap();

        let mut a = Vec::with_capacity(n);
        for _ in 0..n {
            a.push(it.next().unwrap().parse::<i64>().unwrap());
        }

        println!("{}", min_largest_pile(a));
    }
}