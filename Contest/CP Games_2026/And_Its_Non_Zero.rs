fn main() {
    use std::io::{self, Read};

    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut it = input.split_whitespace();

    let t: usize = it.next().unwrap().parse().unwrap();
    let mut out = String::new();

    for _ in 0..t {
        let l: i64 = it.next().unwrap().parse().unwrap();
        let r: i64 = it.next().unwrap().parse().unwrap();

        let len = r - l + 1;
        let mut ans = len;

        for bit in 0..20 {
            let period = 1_i64 << (bit + 1);
            let half = 1_i64 << bit;

            let full_r = (r + 1) / period;
            let rem_r = (r + 1) % period;
            let ones_r = full_r * half + (rem_r - half).max(0);

            let n = l - 1;
            let ones_l = if n < 0 {
                0
            } else {
                let full_l = (n + 1) / period;
                let rem_l = (n + 1) % period;
                full_l * half + (rem_l - half).max(0)
            };

            let cnt = ones_r - ones_l;
            ans = ans.min(len - cnt);
        }

        out.push_str(&format!("{ans}\n"));
    }

    print!("{out}");
}