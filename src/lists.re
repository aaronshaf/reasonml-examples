/* Lists can only have one type of element */
let myListOfNumbers = [1, 2, 3];

let listOfStrings = ["a", "b", "c"]; /* invalid: [1, '2', 3.4] */

/* Add element to list by "prepending"
   This means adding an element to the beginning.
   This is super fast. */
let anotherList = [0, ...myListOfNumbers];

/* list -> array (prettier when printed) */
Js.log(listOfStrings |> Array.of_list); /* [ 'a', 'b', 'c' ] */

/* Lists are "singly linked lists" */
Js.log(listOfStrings); /* [ 'a', [ 'b', [ 'c', 0 ] ] ] */

/* Length of list */
Js.log(List.length(myListOfNumbers) |> string_of_int); /* 3 */

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

/* Reverse first list and concatenate to second (faster than List.rev list1 @ list12) */
Js.log(
  List.rev_append(listOfStrings, otherListOfStrings) |> Array.of_list
); /* [ 'c', 'b', 'a', 'd', 'e', 'f' ] */

let listOfLists = [listOfStrings, otherListOfStrings];

/* Concatenate a list of lists */
Js.log(List.concat(listOfLists) |> Array.of_list); /* [ 'a', 'b', 'c', 'd', 'e', 'f' ] */

/* List.flatten is the same as List.concat */
Js.log(List.flatten(listOfLists) |> Array.of_list); /* [ 'a', 'b', 'c', 'd', 'e', 'f' ] */

/* ## Iterators
 */
/* Iterate over list */
List.iter((element) => Js.log(element), listOfStrings); /* a
b
c
*/

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
