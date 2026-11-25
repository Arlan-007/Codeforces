use std::io::{self, Read};

fn main() {
    let mut s = String::new();
    io::stdin().read_to_string(&mut s).unwrap();
    let mut it = s.split_whitespace();
    let t: usize = it.next().unwrap().parse().unwrap();
    let mut out = String::new();

    for _ in 0..t {
        let n: usize = it.next().unwrap().parse().unwrap();
        let mut a = vec![0usize; n + 1];
        for i in 1..=n {
            a[i] = it.next().unwrap().parse().unwrap();
        }

        let mut del = vec![0usize; n + 1];
        let mut st: Vec<usize> = Vec::new();
        for i in 1..=n {
            while let Some(&j) = st.last() {
                if a[j] < a[i] { st.pop(); } else { break; }
            }
            st.push(i);
            del[i] += i - st.len();
        }
        st.clear();

        for i in (1..=n).rev() {
            while let Some(&j) = st.last() {
                if a[j] < a[i] { st.pop(); } else { break; }
            }
            st.push(i);
            del[i] += (n - i + 1) - st.len();
        }
        let ans = *del[1..].iter().min().unwrap();
        out.push_str(&format!("{ans}\n"));
    }
    print!("{out}");
}