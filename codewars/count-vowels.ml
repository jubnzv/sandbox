(* https://www.codewars.com/kata/57a1dd9fcf1fa5d0d100005f/train/ocaml *)
(* Write function countVowels which returns how many times any vowel
   [a,e,i,o,u] occurs in a string. Consider only lowercase strings. *)

let count_vowels (s: string): int =
  List.init (String.length s) (String.get s)
  |> List.fold_left (fun acc e -> begin
      if List.mem e ['a'; 'e'; 'i'; 'o'; 'u']  then
          (acc + 1)
      else acc
  end) 0

count_vowels "xyz";;
count_vowels "abc";;
