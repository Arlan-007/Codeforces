use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut it = input.split_whitespace();
    let t: usize = it.next().unwrap().parse().unwrap();

    for _ in 0..t {
        let n: usize = it.next().unwrap().parse().unwrap();
        let _q: usize = it.next().unwrap().parse().unwrap();

        let mut a = Vec::with_capacity(n);
        for _ in 0..n {
            a.push(it.next().unwrap().parse::<i32>().unwrap());
        }
        
        let mut cur: Vec<(i32, usize)> = a
            .iter().enumerate()
            .map(|(i, &v)| (v, i))
            .collect();
        cur.sort_unstable();

        let mut dest = vec![0usize; n];
        for (pos, &(_, o_idx)) in cur.iter().enumerate() {
            dest[o_idx] = pos;
        }

        let mut need = 1usize;
        for i in 0..n {
            let x = i ^ dest[i];
            if x != 0 {
                let b = 1usize << (usize::BITS as usize - x.leading_zeros() as usize);
                need = need.max(b);
            }
        }
        let ans = need/2;
        println!("{}", ans);
    }
}