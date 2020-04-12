let flip fn x y =
    fn y x

let pw x y =
    x ** y

pw 3. 2.

flip pw 3. 2.
