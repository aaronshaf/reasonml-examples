/* and */
Js.log(string_of_bool(1 === 1 && 2 === 2)); /* true */

(1 === 1 && 2 === 2) |> string_of_bool |> Js.log; /* true */

Js.log(string_of_bool(1 === 1 && 2 === 3)); /* false */

(1 === 1 && 2 === 3) |> string_of_bool |> Js.log; /* false */

/* or */
Js.log(string_of_bool(1 === 1 || 2 === 3)); /* true */

(1 === 1 || 2 === 3) |> string_of_bool |> Js.log; /* true */

Js.log(string_of_bool(1 === 2 || 2 === 3)); /* false */

(1 === 2 || 2 === 3) |> string_of_bool |> Js.log; /* false */

/* custom operator */
let ($$$) = (l0: int, l1: int) => l0 * l0 * l0 * l1 * l1 * l1;

Js.log(2 $$$ 3);
/* TODO: |> (pipe)
   "The pipe |> is a left-associative binary operator that's defined as a |> b == b(a)." (JF)
   */
