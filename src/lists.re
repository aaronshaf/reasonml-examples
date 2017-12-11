/* Lists can only have one type of element */
let listOfNumbers = [1, 2, 3];

let listOfStrings = ["a", "b", "c"]; /* invalid: [1, '2', 3.4] */

/* Add element to list by "prepending"
   This means adding an element to the beginning.
   This is super fast. */
let anotherList = [0, ...listOfNumbers];

/* list -> array (prettier when printed) */
listOfStrings |> Array.of_list |> Js.log; /* [ 'a', 'b', 'c' ] */

/* Same as */
Js.log(Array.of_list(listOfStrings));

/* Lists are "singly linked lists" */
Js.log(listOfStrings); /* [ 'a', [ 'b', [ 'c', 0 ] ] ] */

/* Same as */
listOfStrings |> Js.log;

/* Length of list */
Js.log(List.length(listOfNumbers) |> string_of_int); /* 3 */

/* Head of list */
Js.log(List.hd(listOfStrings)); /* a */

/* Tail of list */
Js.log(List.tl(listOfStrings) |> Array.of_list); /* [ 'b', 'c' ] */

/* nth element of list (first element is at position 0) */
Js.log(List.nth(listOfStrings, 1)); /* b */

/* reverse a list */
Js.log(List.rev(listOfStrings) |> Array.of_list); /* [ 'c', 'b', 'a' ] */

let otherListOfStrings = ["d", "e", "f"];

/* Print two concatenated lists */
Js.log(List.append(listOfStrings, otherListOfStrings) |> Array.of_list); /* [ 'a', 'b', 'c', 'd', 'e', 'f' ] */

/* @ is the operator for catenating lists */
Js.log(listOfStrings @ otherListOfStrings |> Array.of_list); /* [ 'a', 'b', 'c', 'd', 'e', 'f' ] */

/* Reverse first list and concatenate to second; faster than List.rev(list1 @ list12) */
Js.log(
  List.rev_append(listOfStrings, otherListOfStrings) |> Array.of_list
); /* [ 'c', 'b', 'a', 'd', 'e', 'f' ] */

let listOfLists = [listOfStrings, otherListOfStrings];

/* Concatenate a list of lists */
Js.log(List.concat(listOfLists) |> Array.of_list); /* [ 'a', 'b', 'c', 'd', 'e', 'f' ] */

Js.log(listOfLists |> List.concat |> Array.of_list);

/* List.flatten is the same as List.concat */
Js.log(List.flatten(listOfLists) |> Array.of_list); /* [ 'a', 'b', 'c', 'd', 'e', 'f' ] */

/* ## Iterators
 */
/* Iterate over list */
List.iter((element) => Js.log(element), listOfStrings); /*
a
b
c
*/

listOfStrings |> List.iter((element) => Js.log(element));

/* Iterate over list with (index, value) */
List.iteri(
  (index, string) => Js.log(string_of_int(index) ++ " " ++ string),
  listOfStrings
); /*
 0 a
 1 b
 2 c
  */

/* Map over list */
let listOfStringsWithExclamation =
  List.map((element) => element ++ "!", listOfStrings);

Js.log(listOfStringsWithExclamation |> Array.of_list); /* [ 'a!', 'b!', 'c!' ] */

/* Map over list with index */
let listOfStringsWithExclamation =
  List.mapi(
    (index, element) => string_of_int(index) ++ ": " ++ element,
    listOfStrings
  );

Js.log(listOfStringsWithExclamation |> Array.of_list); /* [ '0: a', '1: b', '2: c' ] */

/* Map and reverse the result; faster than List.rev(List.map(list)) */
let reversedListOfStringsWithExclamation =
  List.rev_map((element) => element ++ "!", listOfStrings);

Js.log(reversedListOfStringsWithExclamation |> Array.of_list); /* [ 'c!', 'b!', 'a!' ] */

let beginningIntState = 0;

/* fold_left is a left reducer; compare Array.prototype.reduce in JavaScript */
Js.log(
  List.fold_left(
    (state, currentElement) => state + currentElement,
    beginningIntState,
    listOfNumbers
  )
); /* 6 */

let beginningStringState = "";

/* fold_left is a left reducer; compare Array.prototype.reduceRight in JavaScript */
Js.log(
  List.fold_right(
    (currentElement, state) => state ++ currentElement,
    listOfStrings,
    beginningStringState
  )
); /* cba */

/* Iterate over two lists */
List.iter2(
  (string1, string2) => Js.log(string1 ++ ":" ++ string2),
  listOfStrings,
  otherListOfStrings
); /*
a:d
b:e
c:f
*/

/* Map over two lists */
let listOfCombinedStrings =
  List.map2(
    (element1, element2) => element1 ++ ":" ++ element2,
    listOfStrings,
    otherListOfStrings
  );

Js.log(listOfCombinedStrings |> Array.of_list); /* [ 'a:d', 'b:e', 'c:f' ] */

/* Reverse the result of a map over two lists; faster than List.rev(List.map2(list1, list2) */
let reversedListOfCombinedStrings =
  List.rev_map2(
    (element1, element2) => element1 ++ ":" ++ element2,
    listOfStrings,
    otherListOfStrings
  );

Js.log(reversedListOfCombinedStrings |> Array.of_list); /* [ 'c:f', 'b:e', 'a:d' ]*/

/* fold_left2 is a left reducer on two lists */
Js.log(
  List.fold_left2(
    (state, currentElement1, currentElement2) =>
      state ++ currentElement1 ++ currentElement2 ++ "-",
    beginningStringState,
    listOfStrings,
    otherListOfStrings
  )
); /* ad-be-cf- */

/* fold_right2 is a left reducer on two lists */
Js.log(
  List.fold_right2(
    (currentElement1, currentElement2, state) =>
      state ++ currentElement1 ++ currentElement2 ++ "-",
    listOfStrings,
    otherListOfStrings,
    beginningStringState
  )
); /* cf-be-ad- */

/* for_all; compare Array.prototype.every */
Js.log(List.for_all((str) => str === "a", listOfStrings) |> string_of_bool); /* false */

Js.log(listOfStrings |> List.for_all((str) => str === "a")); /* false */

Js.log(List.for_all((str) => str !== "d", listOfStrings) |> string_of_bool); /* true */

/* exists: compare Array.prototype.some */
listOfStrings |> List.exists((str) => str === "a") |> string_of_bool |> Js.log; /* true */

/* Same as */
Js.log(string_of_bool(List.exists((str) => str === "a", listOfStrings)));

/* TODO: for_all2 */
/* TODO: exists2 */
/* mem; compare to Array.prototype.includes */
listOfStrings |> List.mem("a") |> string_of_bool |> Js.log;
