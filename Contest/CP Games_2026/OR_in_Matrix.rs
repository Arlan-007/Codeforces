use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut it = input.split_whitespace();

    let n: usize = it.next().unwrap().parse().unwrap();
    let m: usize = it.next().unwrap().parse().unwrap();

    let mut b = vec![vec![0i32; m]; n];
    for i in 0..n {
        for j in 0..m {
            b[i][j] = it.next().unwrap().parse().unwrap();
        }
    }

    let mut a = vec![vec![1i32; m]; n];

    for i in 0..n {
        for j in 0..m {
            if b[i][j] == 0 {
                for k in 0..m {
                    a[i][k] = 0;
                }
                for k in 0..n {
                    a[k][j] = 0;
                }
            }
        }
    }

    let mut c = vec![vec![0i32; m]; n];

    for i in 0..n {
        for j in 0..m {
            let mut val = 0;

            for k in 0..m {
                val |= a[i][k];
            }

            for k in 0..n {
                val |= a[k][j];
            }

            c[i][j] = val;
        }
    }

    if c != b {
        println!("NO");
        return;
    }

    println!("YES");
    for row in a {
        for (j, x) in row.iter().enumerate() {
            if j > 0 {
                print!(" ");
            }
            print!("{}", x);
        }
        println!();
    }
}