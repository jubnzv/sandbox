(* Dump ocaml records in the json file. *)
type operator = NEG | NOT | POW
[@@deriving yojson]

and expr =
  | OpExpr of operator * string
  | Test of string
[@@deriving yojson]

and expr_list = expr list [@@deriving yojson]

let () =
  let e1 = OpExpr(NEG, "test1") in
  let e2 = Test("test2") in
  let e3 = OpExpr(NOT, "test3") in
  let exprs = expr_list_to_yojson [e1; e2; e3] in
  Printf.printf "%s\n" (Yojson.Safe.to_string exprs);
  Yojson.Safe.to_file "test.json" exprs
