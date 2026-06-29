use std::io::{self, Read};

fn main() {
    let mut s = String::new();
    io::stdin().read_to_string(&mut s).unwrap();
    let a: Vec<i32> = s.split_whitespace().map(|x| x.parse().unwrap()).collect();

    let face = |p: &[usize; 4]| a[p[0]] == a[p[1]] && a[p[1]] == a[p[2]] && a[p[2]] == a[p[3]];
    let eq = |pairs: &[(usize, usize)]| pairs.iter().all(|&(x, y)| a[x] == a[y]);

    let faces = [
        [0, 1, 2, 3],
        [4, 5, 6, 7],
        [8, 9, 10, 11],
        [12, 13, 14, 15],
        [16, 17, 18, 19],
        [20, 21, 22, 23],
    ];

    let mut same = Vec::new();
    for i in 0..6 {
        if face(&faces[i]) {
            same.push(i);
        }
    }

    let ok = if same.len() == 2 {
        match (same[0], same[1]) {
            (0, 2) => {
                eq(&[(4, 14), (5, 15), (16, 6), (17, 7), (20, 18), (21, 19), (12, 22), (13, 23)]) ||
                    eq(&[(4, 18), (5, 19), (16, 22), (17, 23), (20, 14), (21, 15), (12, 6), (13, 7)])
            }
            (1, 5) => {
                eq(&[(2, 17), (3, 19), (16, 11), (18, 10), (9, 14), (8, 12), (15, 0), (13, 1)]) ||
                    eq(&[(2, 14), (3, 12), (16, 0), (18, 1), (9, 17), (8, 19), (15, 11), (13, 10)])
            }
            (3, 4) => {
                eq(&[(0, 5), (2, 7), (4, 9), (6, 11), (8, 20), (10, 22), (1, 21), (3, 23)]) ||
                    eq(&[(1, 4), (3, 6), (8, 5), (10, 7), (0, 22), (2, 20), (21, 9), (23, 11)])
            }
            _ => false,
        }
    } else {
        false
    };

    println!("{}", if ok { "YES" } else { "NO" });
}