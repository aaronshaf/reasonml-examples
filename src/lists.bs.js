// Generated by BUCKLESCRIPT VERSION 2.1.0, PLEASE EDIT WITH CARE
'use strict';

var List       = require("bs-platform/lib/js/list.js");
var $$Array    = require("bs-platform/lib/js/array.js");
var Pervasives = require("bs-platform/lib/js/pervasives.js");

var listOfNumbers = /* :: */[
  1,
  /* :: */[
    2,
    /* :: */[
      3,
      /* [] */0
    ]
  ]
];

var listOfStrings = /* :: */[
  "a",
  /* :: */[
    "b",
    /* :: */[
      "c",
      /* [] */0
    ]
  ]
];

var anotherList = /* :: */[
  0,
  listOfNumbers
];

console.log($$Array.of_list(listOfStrings));

console.log($$Array.of_list(listOfStrings));

console.log(listOfStrings);

console.log(listOfStrings);

console.log(Pervasives.string_of_int(List.length(listOfNumbers)));

console.log(List.hd(listOfStrings));

console.log($$Array.of_list(List.tl(listOfStrings)));

console.log(List.nth(listOfStrings, 1));

console.log($$Array.of_list(List.rev(listOfStrings)));

var otherListOfStrings = /* :: */[
  "d",
  /* :: */[
    "e",
    /* :: */[
      "f",
      /* [] */0
    ]
  ]
];

console.log($$Array.of_list(List.append(listOfStrings, otherListOfStrings)));

console.log($$Array.of_list(Pervasives.$at(listOfStrings, otherListOfStrings)));

console.log($$Array.of_list(List.rev_append(listOfStrings, otherListOfStrings)));

var listOfLists_001 = /* :: */[
  otherListOfStrings,
  /* [] */0
];

var listOfLists = /* :: */[
  listOfStrings,
  listOfLists_001
];

console.log($$Array.of_list(List.concat(listOfLists)));

console.log($$Array.of_list(List.concat(listOfLists)));

console.log($$Array.of_list(List.flatten(listOfLists)));

List.iter((function (element) {
        console.log(element);
        return /* () */0;
      }), listOfStrings);

List.iter((function (element) {
        console.log(element);
        return /* () */0;
      }), listOfStrings);

List.iteri((function (index, string) {
        console.log(Pervasives.string_of_int(index) + (" " + string));
        return /* () */0;
      }), listOfStrings);

var listOfStringsWithExclamation = List.map((function (element) {
        return element + "!";
      }), listOfStrings);

console.log($$Array.of_list(listOfStringsWithExclamation));

var listOfStringsWithExclamation$1 = List.mapi((function (index, element) {
        return Pervasives.string_of_int(index) + (": " + element);
      }), listOfStrings);

console.log($$Array.of_list(listOfStringsWithExclamation$1));

var reversedListOfStringsWithExclamation = List.rev_map((function (element) {
        return element + "!";
      }), listOfStrings);

console.log($$Array.of_list(reversedListOfStringsWithExclamation));

console.log(List.fold_left((function (state, currentElement) {
            return state + currentElement | 0;
          }), 0, listOfNumbers));

var beginningStringState = "";

console.log(List.fold_right((function (currentElement, state) {
            return state + currentElement;
          }), listOfStrings, beginningStringState));

List.iter2((function (string1, string2) {
        console.log(string1 + (":" + string2));
        return /* () */0;
      }), listOfStrings, otherListOfStrings);

var listOfCombinedStrings = List.map2((function (element1, element2) {
        return element1 + (":" + element2);
      }), listOfStrings, otherListOfStrings);

console.log($$Array.of_list(listOfCombinedStrings));

var reversedListOfCombinedStrings = List.rev_map2((function (element1, element2) {
        return element1 + (":" + element2);
      }), listOfStrings, otherListOfStrings);

console.log($$Array.of_list(reversedListOfCombinedStrings));

console.log(List.fold_left2((function (state, currentElement1, currentElement2) {
            return state + (currentElement1 + (currentElement2 + "-"));
          }), beginningStringState, listOfStrings, otherListOfStrings));

console.log(List.fold_right2((function (currentElement1, currentElement2, state) {
            return state + (currentElement1 + (currentElement2 + "-"));
          }), listOfStrings, otherListOfStrings, beginningStringState));

console.log(Pervasives.string_of_bool(List.for_all((function (str) {
                return +(str === "a");
              }), listOfStrings)));

console.log(List.for_all((function (str) {
            return +(str === "a");
          }), listOfStrings));

console.log(Pervasives.string_of_bool(List.for_all((function (str) {
                return +(str !== "d");
              }), listOfStrings)));

console.log(Pervasives.string_of_bool(List.exists((function (str) {
                return +(str === "a");
              }), listOfStrings)));

console.log(Pervasives.string_of_bool(List.exists((function (str) {
                return +(str === "a");
              }), listOfStrings)));

console.log(Pervasives.string_of_bool(List.mem("a", listOfStrings)));

console.log(Pervasives.string_of_bool(List.mem("z", listOfStrings)));

console.log(Pervasives.string_of_bool(List.mem("z", listOfStrings)));

console.log(Pervasives.string_of_int(List.find((function (element) {
                return +(element > 2);
              }), listOfNumbers)));

console.log($$Array.of_list(List.filter((function (element) {
                  return +(element > 1);
                }))(listOfNumbers)));

console.log($$Array.of_list(List.find_all((function (element) {
                  return +(element > 1);
                }))(listOfNumbers)));

var match = List.partition((function (element) {
        return +(element > 1);
      }), listOfNumbers);

var notMatching = match[1];

var matching = match[0];

console.log($$Array.of_list(matching));

console.log($$Array.of_list(notMatching));

var beginningIntState = 0;

exports.listOfNumbers                        = listOfNumbers;
exports.listOfStrings                        = listOfStrings;
exports.anotherList                          = anotherList;
exports.otherListOfStrings                   = otherListOfStrings;
exports.listOfLists                          = listOfLists;
exports.listOfStringsWithExclamation         = listOfStringsWithExclamation$1;
exports.reversedListOfStringsWithExclamation = reversedListOfStringsWithExclamation;
exports.beginningIntState                    = beginningIntState;
exports.beginningStringState                 = beginningStringState;
exports.listOfCombinedStrings                = listOfCombinedStrings;
exports.reversedListOfCombinedStrings        = reversedListOfCombinedStrings;
exports.matching                             = matching;
exports.notMatching                          = notMatching;
/*  Not a pure module */
