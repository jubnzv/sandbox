(* {{{ Common *)
let rec last = function
    | [] -> None
    | [x] -> Some x
    | _ :: t -> last t;;

let l1 = [1;2;3];;
let l2 = [4];;
let l3 = l1 @ l2;;
(* }}} *)

(* {{{ Expreriments with JaneStreet's Base lists *)
open Core_kernel
List.tl [];;
List.tl [1];;
List.tl [1; 2];;
(* }}} *)
