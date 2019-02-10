/// Written while figuring out with problem described in this PR:
/// https://github.com/Wilfred/remacs/pull/1339
///
/// `mtest` macro expansion should not work in global scope.
///

macro_rules! mtest {
    ($a:ident, $b:expr, $c:expr) => {{
        let $a: *const u32 = &10;
        #[allow(unused_unsafe)]
        unsafe {  }
    }};
}

// Not working.
// Comment it and see: `rustc expansion_in_global_scope.rs -Zunstable-options --pretty=expanded | vim -` for explanation.
// mtest!(b, 6, 7);

fn main() {
    mtest!(a, 4, 5);
}
