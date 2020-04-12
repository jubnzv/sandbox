type iec_data_type =
  | STRING
  | WSTRING
  | TIME
  | NONE

let from_string s =
  match s with
  | "STRING" -> STRING
  | "WSTRING" -> WSTRING
  | "TIME" -> TIME
  | _ -> NONE

from_string "SFDFSDF"
from_string "STRING"


