use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut it = input.split_whitespace();

    let t: usize = it.next().unwrap().parse().unwrap();

    for _ in 0..t {
        let n: usize = it.next().unwrap().parse().unwrap();
        let x: usize = it.next().unwrap().parse().unwrap();
        let s: i64 = it.next().unwrap().parse().unwrap();
        let u: Vec<char> = it.next().unwrap().chars().collect();

        let mut need = vec![0i64; n + 1];

        for i in (0..n).rev() {
            need[i] = match u[i] {
                'E' => need[i + 1] + 1,
                'I' => (need[i + 1] - (s - 1)).max(0),
                'A' => {
                    let join = need[i + 1] + 1;
                    let open = (need[i + 1] - (s - 1)).max(0);
                    join.min(open)
                }
                _ => 0,
            };
        }

        let mut used: i64 = 0;
        let mut seated: i64 = 0;
        let mut ans: i64 = 0;

        for i in 0..n {
            let free = used * s - seated;
            let empty = x as i64 - used;
            let eia = u[i];

            match eia {
                'I' => {
                    if empty > 0 {
                        used += 1;
                        seated += 1;
                        ans += 1;
                    }
                }
                'E' => {
                    if free > 0 {
                        seated += 1;
                        ans += 1;
                    }
                }
                'A' => {
                    if free > 0 && free - 1 >= need[i + 1] {
                        seated += 1;
                        ans += 1;
                    } else if empty > 0 {
                        used += 1;
                        seated += 1;
                        ans += 1;
                    } else if free > 0 {
                        seated += 1;
                        ans += 1;
                    }
                }
                _ => {}
            }
        }

        println!("{}", ans);
    }
}