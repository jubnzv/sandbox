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

