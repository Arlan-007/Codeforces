use std::io::{self, Read};
use std::collections::HashMap;

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let s = input.trim();
    let mut freq: HashMap<char, usize> = HashMap::new();
    for c in s.chars() {
        *freq.entry(c).or_insert(0) += 1;
    }
    let total = freq.values().filter(|&&f| f % 2 == 1).count();
    if total == 0 || total % 2 == 1 {
        println!("First");
    } else {
        println!("Second");
    }
}