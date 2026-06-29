use std::collections::BTreeMap;
use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut it = input.split_whitespace();

    let tc: usize = it.next().unwrap().parse().unwrap();
    let mut out = String::new();

    for _ in 0..tc {
        let len: usize = it.next().unwrap().parse().unwrap();
        let mut vals = vec![0i64; len];

        for x in &mut vals {
            *x = it.next().unwrap().parse().unwrap();
        }

        let mut low: i64 = 0;
        let mut high: i64 = (len as i64) + 1;

        while low < high {
            let mid = (low + high) / 2;

            let mut bag: BTreeMap<i64, i64> = BTreeMap::new();
            for &x in &vals {
                *bag.entry(x).or_insert(0) += 1;
            }

            let mut ok = true;

            for need in (0..mid).rev() {
                if bag.contains_key(&need) {
                    let mut remove_it = false;
                    {
                        let cnt = bag.get_mut(&need).unwrap();
                        *cnt -= 1;
                        if *cnt == 0 {
                            remove_it = true;
                        }
                    }
                    if remove_it {
                        bag.remove(&need);
                    }
                } else {
                    let largest = match bag.last_key_value() {
                        Some((&v, _)) => v,
                        None => {
                            ok = false;
                            break;
                        }
                    };

                    if largest < 2 * need + 1 {
                        ok = false;
                        break;
                    }

                    let mut remove_it = false;
                    {
                        let cnt = bag.get_mut(&largest).unwrap();
                        *cnt -= 1;
                        if *cnt == 0 {
                            remove_it = true;
                        }
                    }
                    if remove_it {
                        bag.remove(&largest);
                    }
                }
            }

            if ok {
                low = mid + 1;
            } else {
                high = mid;
            }
        }

        out.push_str(&(low - 1).to_string());
        out.push('\n');
    }

    print!("{}", out);
}