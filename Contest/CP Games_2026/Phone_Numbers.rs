use std::collections::HashMap;
use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut it = input.split_whitespace();
    let n: usize = it.next().unwrap().parse().unwrap();
    let mut mp: HashMap<String, Vec<String>> = HashMap::new();

    for _ in 0..n {
        let name = it.next().unwrap().to_string();
        let k: usize = it.next().unwrap().parse().unwrap();

        let entry = mp.entry(name).or_default();

        for _ in 0..k {
            entry.push(it.next().unwrap().to_string());
        }
    }

    let mut ans: Vec<(String, Vec<String>)> = Vec::new();

    for (name, nums) in mp {
        let mut nums = nums;

        nums.sort();
        nums.dedup();

        let mut keep = vec![true; nums.len()];

        for i in 0..nums.len() {
            for j in 0..nums.len() {
                if i == j {
                    continue;
                }

                if nums[j].ends_with(&nums[i]) {
                    keep[i] = false;
                    break;
                }
            }
        }

        let mut res = Vec::new();

        for i in 0..nums.len() {
            if keep[i] {
                res.push(nums[i].clone());
            }
        }

        ans.push((name, res));
    }

    println!("{}", ans.len());

    for (name, nums) in ans {
        print!("{} {}", name, nums.len());

        for num in nums {
            print!(" {}", num);
        }

        println!();
    }
}