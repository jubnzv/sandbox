// https://www.codewars.com/kata/592e830e043b99888600002d/train/rust

// fn encode(msg: String, n: i32) -> Vec<i32> {
//     let n_str = n.to_string();
//     let mut n_digits_iter = n_str.chars().map(|c| (c as u8 - '0' as u8)).cycle();
//     msg.chars()
//         .map(|c| ((c as u8) - b'a' + 1 + n_digits_iter.next().unwrap()) as i32)
//         .collect::<Vec<i32>>()
// }

// Now, learn about `zip`
fn encode(msg: String, n: i32) -> Vec<i32> {
    msg.bytes()
        .zip(n.to_string().bytes().cycle())
        .map(|(a, b)| (a - b'a' + 1 + b - b'0') as i32)
        .collect()
}

#[test]
fn fixed_tests() {
    assert_eq!(encode("scout".to_string(), 1939), vec![20, 12, 18, 30, 21]);
    assert_eq!(
        encode("masterpiece".to_string(), 1939),
        vec![14, 10, 22, 29, 6, 27, 19, 18, 6, 12, 8]
    );
}
