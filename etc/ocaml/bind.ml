(* https://jobjo.github.io/2019/04/24/ocaml-has-some-new-shiny-syntax.html *)

open Core_kernel

let bind o f =
  match o with
  | Some x  -> f x
  | None    -> None
let ( >>= ) o f = bind o f

let return_opt v =
    if phys_equal v 0 then
        None
    else
        Some((v+1))

let do_safe_sum (a : int) (b : int) : (int option) =
    return_opt a >>= fun x ->
    return_opt b >>= fun y ->
        Some(x+y)

do_safe_sum 0 1;;
do_safe_sum 1 0;;
do_safe_sum 2 3;;

