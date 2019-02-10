//! Argument contains a funciton call

macro_rules! mfun {
    ($f:expr) => ($f);
}

fn fun(a: i32) {
    println!("call fun: a = {}", a);
}

fn main() {
    mfun!(fun(3));
}

