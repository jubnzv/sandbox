macro_rules! mmatch {
    (x => $e:expr) => (println!("x value: {}", $e));
    (y => $e:expr) => (println!("y value: {}", $e));
}

fn main() {
    mmatch!(x => 3);
}
