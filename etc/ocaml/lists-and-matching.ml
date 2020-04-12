let has_false (l: bool list) : bool =
    if List.exists (fun v -> v == false) l then true
    else false

assert (has_false [true; false; true])
assert (has_false [true; true; true] = false)

let list_equals (l1: int list) (l2: int list) : bool =
    let rec list_equals_rec l1 l2 : bool =
        match (l1, l2) with
        | ([], []) ->
            true
        | ([h1], [h2]) ->
            h1 == h2
        | (h1::t1, h2::t2) ->
            list_equals_rec t1 t2
    in
    list_equals_rec l1 l2

assert (list_equals [1;2] [1;2])
assert (list_equals [1;3] [1;2] = false)

let m = 0 :: 1 :: 2 :: []

let rec sum l : int =
  match l with
  | [] -> 0
  | hd :: tl -> hd + sum tl

sum [1;3;5]

let rec drop_value l to_drop =
  match l with
  | [] -> []
  | hd :: tl ->
    let new_tl = drop_value tl to_drop in
    if hd = to_drop then new_tl else hd :: new_tl

(* Traverse a list *)
let traverse (l: int list) =
    let v in l
  |> Printf.printf "%d\n" v

traverse [1;3;4]
