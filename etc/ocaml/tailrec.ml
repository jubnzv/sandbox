let rec f a x = if x <= 1 then a else (f [@tailcall]) (a * x) (x - 1)
let rec g x = if x <= 1 then 1 else x * (g [@tailcall]) (x - 1)
(* Line 2, characters 40-63:     *)
(* Warning 51: expected tailcall *)
