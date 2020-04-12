(*
References:
+ RWO part 2 Ch. 13
+ https://ocaml.org/learn/tutorials/modules.html#Submodule-interface
*)
module DatatypeMy = struct
  type t = string * int * int
  let compare = compare
end

module TypeMap = Map.Make(DatatypeMy)

TypeMap.add ("first", 330, 42)
