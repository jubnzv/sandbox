(* https://www.cs.cornell.edu/courses/cs3110/2019sp/textbook/ads/ex_maybe_monad.html *)

(* {{{ Introduction *)
(* this works fine and evaluates to 3 *)
let x = 1 + (4 / 2)

let div (x:int) (y:int) : int option =
  if y=0 then None
  else Some (x / y)

let ( / ) = div

(* this won't type check *)
let x = 1 + (4 / 2)
(* }}} *)

(* {{{ Implementation *)
let return (x : int) : int option =
  Some x

let bind (x : int option) (op : int -> int option) : int option =
  match x with
  | None -> None
  | Some a -> op a

let (>>=) = bind

let upgrade_binary op x y =
  x >>= fun a ->
  y >>= fun b ->
  op a b

let return_binary op x y =
  return (op x y)

let ( + ) = upgrade_binary (return_binary Caml.( + ))
let ( - ) = upgrade_binary (return_binary Caml.( - ))
let ( * ) = upgrade_binary (return_binary Caml.( * ))
let ( / ) = upgrade_binary div;;

( / ) (Some(4)) (Some(2));; (* Some 2 *)
( / ) (Some(4)) (Some(0));; (* None *)
(* }}} *)

(* {{{ Fold example *)
let ( + ) = upgrade_binary (return_binary Caml.( + ))
let sum_maybe_list values =
  let rec aux acc values =
      match acc with
      | Some _ -> begin
          match values with
          | [] -> acc
          | [x] -> ( + ) acc x
          | x :: xs -> aux (( + ) acc x) xs
      end
      | None -> None
    in
  aux (Some 0) values
;;

sum_maybe_list [(Some 1); (Some 2); (Some 4);];;
sum_maybe_list [(Some 1); None; (Some 4);];;
(* }}} *)

(* vim: set foldmethod=marker foldlevel=0 foldenable : *)
