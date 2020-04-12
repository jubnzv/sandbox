type iec_data_type =
  | STRING
  | WSTRING
  | TIME
  | NONE

(* Incorrect! Shoud have same type. *)
let get_type s =
  match s with
  | string -> s ^ " test"
  | iec_data_type -> s

get_type "SFDFSDF"
get_type STRING
get_type TIME


