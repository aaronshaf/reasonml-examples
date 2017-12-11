/* Lists can only have one type of element */
let myListOfNumbers = [1, 2, 3];

let myListOfStrings = ["a", "b", "c"]; /* invalid: [1, '2', 3.4] */

/* Add element to list by "prepending"
   This means adding an element to the beginning.
   This is super fast. */
let anotherList = [0, ...myListOfNumbers];

/* list -> array (prettier when printed) */
Js.log(myListOfStrings |> Array.of_list); /* [ 'a', 'b', 'c' ] */

/* Lists are "singly linked lists" */
Js.log(myListOfStrings); /* [ 'a', [ 'b', [ 'c', 0 ] ] ] */

/* Length of list */
Js.log(List.length(myListOfNumbers) |> string_of_int); /* 3 */

/* Head of list */
Js.log(List.hd(myListOfStrings)); /* a */

/* Tail of list */
Js.log(List.tl(myListOfStrings) |> Array.of_list); /* [ 'b', 'c' ] */

/* nth element of list (first element is at position 0) */
Js.log(List.nth(myListOfStrings, 1)); /* b */

/* reverse a list */
Js.log(List.rev(myListOfStrings) |> Array.of_list); /* [ 'c', 'b', 'a' ] */

let myOtherListOfStrings = ["d", "e", "f"];

/* Print two concatenated lists */
Js.log(List.append(myListOfStrings, myOtherListOfStrings) |> Array.of_list); /* [ 'a', 'b', 'c', 'd', 'e', 'f' ] */

/* @ is the operator for catenating lists */
Js.log(myListOfStrings @ myOtherListOfStrings |> Array.of_list); /* [ 'a', 'b', 'c', 'd', 'e', 'f' ] */

/* Reverse first list and concatenate to second (faster than List.rev list1 @ list12) */
Js.log(
  List.rev_append(myListOfStrings, myOtherListOfStrings) |> Array.of_list
); /* [ 'c', 'b', 'a', 'd', 'e', 'f' ] */

let listOfLists = [myListOfStrings, myOtherListOfStrings];

/* Concatenate a list of lists */
Js.log(List.concat(listOfLists) |> Array.of_list); /* [ 'a', 'b', 'c', 'd', 'e', 'f' ] */

/* List.flatten is the same as List.concat */
Js.log(List.flatten(listOfLists) |> Array.of_list); /* [ 'a', 'b', 'c', 'd', 'e', 'f' ] */
