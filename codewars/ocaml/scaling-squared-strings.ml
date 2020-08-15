(* https://www.codewars.com/kata/56ed20a2c4e5d69155000301/train/ocaml *)
#load "str.cma";;

let scale (s: string) (hcount: int) (vcount: int) =
  let mk_string s =
    let repeat s =
      List.init vcount (fun _ -> s)
      |> String.concat "\n"
    in
    List.init (String.length s) (String.get s)
    |> List.fold_left (fun acc c -> acc ^ (String.make hcount c)) ""
    |> repeat
  in
  let rec join = function
    | [] -> ""
    | [str] -> str
    | ""::strs -> join strs
    | str::strs -> str ^ "\n" ^ join strs
  in
  Str.split (Str.regexp "\n") s
  |> List.fold_left (fun acc e -> acc @ [mk_string e]) []
  |> join
;;

scale "abcd\nefgh\nijkl\nmnop" 2 3;;
