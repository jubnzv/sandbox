(* Experiments with JaneStreet's Base monads. *)
open Core_kernel
(* val ( >>= ) : 'a option -> ('a -> 'b option) -> 'b option = <fun> *)
let ( >>= ) = Option.( >>= )
(* val ( >>| ) : 'a option -> ('a -> 'b) -> 'b option = <fun> *)
let ( >>| ) = Option.( >>| )

(* {{{ Util *)
let update (element : int) : (int) =
  element + 1
let unwrap = function
  | Some v -> v
  | None -> []
(* }}} *)

(* {{{ Maybe monad (>>=) example. *)
let get_first_value_or_empty_list (values : int list) : (int list) =
  let process_first (element : int) : (int list option) =
    Some([element; 19])
  in
  List.nth values 0
  >>= (fun e -> Some(update e))
  >>= process_first
  |> unwrap
;;

get_first_value_or_empty_list [];;
get_first_value_or_empty_list [1];;
get_first_value_or_empty_list [1;2;3];;
(* }}} *)

(* {{{ >>| example *)
(* Same as maybe, but wraps result in [Some]. *)
let map_example (values : int list) =
  let process_first (element : int) : (int list) =
    [element; 19]
  in
  List.nth values 0
  (* Some 2 *)
  (* >>= (fun e -> Some(update e)) *)
  (* Some Some 2 *)
  >>= (fun e -> Some(update e))
  >>| process_first
  |> unwrap
;;

map_example [];;
map_example [1];;
map_example [1;2;3];;
(* }}} *)

(* {{{ Expreiments with recursion inside >>| calls *)
let map_example (values : int list) =
  let process_first (element : int) : (int list) =
    [element; 19]
  in
  List.nth values 0
  (* Some 2 *)
  (* >>= (fun e -> Some(update e)) *)
  (* Some Some 2 *)
  >>= (fun e -> Some(update e))
  >>| process_first
  |> unwrap
;;

let recursion_example =

;;

map_example [];;
map_example [1];;
map_example [1;2;3];;
(* }}} *)
