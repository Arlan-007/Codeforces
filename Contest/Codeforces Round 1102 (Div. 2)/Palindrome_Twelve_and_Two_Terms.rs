use std::io::Read;

fn main() {
    let mut s = String::new();
    std::io::stdin().read_to_string(&mut s).unwrap();
    let mut it = s.split_whitespace();

    let t: usize = it.next().unwrap().parse().unwrap();
    let mut out = String::new();

    for _ in 0..t {
        let n: u64 = it.next().unwrap().parse().unwrap();

        if n == 10 {
            out.push_str("-1\n");
            continue;
        }

        let a = match n % 12 {
            0 => 0,
            1 => 1,
            2 => 2,
            3 => 3,
            4 => 4,
            5 => 5,
            6 => 6,
            7 => 7,
            8 => 8,
            9 => 9,
            10 => 22,
            11 => 11,
            _ => unreachable!(),
        };

        let b = n - a;
        out.push_str(&format!("{} {}\n", a, b));
    }

    print!("{}", out);
}