macro_rules! msimple {
    ($e:expr) => (println!("value: {}", $e));
}

fn main() {
    msimple!(3);
}
