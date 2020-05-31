open Core_kernel

type aty = {
    mutable afield : int list;
};;

let check_mutable a =
    a.afield <- a.afield @ [1];
    ()
;;

let () =
    let a1 = { afield = [] } in
    check_mutable a1;
    check_mutable a1;
    List.iter
      a1.afield
      ~f:(fun i -> Printf.printf "%d\n" i)
;;
