use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut it = input.split_whitespace();
    let t: usize = it.next().unwrap().parse().unwrap();

    for _ in 0..t {
        let _n: usize = it.next().unwrap().parse().unwrap();
        let s = it.next().unwrap().as_bytes();

        let mut to = [None; 26];
        let mut used = [false; 26];
        let mut cnt = 0;

        let mut ans = String::new();

        for &ch in s {
            let x = (ch - b'a') as usize;
            if to[x].is_none() {
                for y in 0..26 {
                    if y == x || used[y] {
                        continue;
                    }

                    let mut v = y;
                    let mut cycle = false;

                    while let Some(nxt) = to[v] {
                        v = nxt;
                        if v == x {
                            cycle = true;
                            break;
                        }
                    }

                    if cycle && cnt < 25 {
                        continue;
                    }

                    to[x] = Some(y);
                    used[y] = true;
                    cnt += 1;
                    break;
                }
            }
            ans.push((to[x].unwrap() as u8 + b'a') as char);
        }

        println!("{ans}");
    }
}