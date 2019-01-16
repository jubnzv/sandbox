// https://www.codewars.com/kata/exes-and-ohs
fn xo(s: &'static str) -> bool {
    let sl = s.to_lowercase();
    sl.matches("x").count() == sl.matches("o").count()
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn returns_expected() {
        assert_eq!(xo("Xo"), true);
        assert_eq!(xo("xxOo"), true);
        assert_eq!(xo("xxxm"), false);
        assert_eq!(xo("Oo"), false);
        assert_eq!(xo("ooom"), false);
        assert_eq!(xo("xo"), true);
    }
}
