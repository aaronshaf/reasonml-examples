// Generated by BUCKLESCRIPT VERSION 2.1.1, PLEASE EDIT WITH CARE
'use strict';

var Caml_obj = require("bs-platform/lib/js/caml_obj.js");

var todaysGame = /* record */[
  /* name */"Catan",
  /* players */4
];

var name = todaysGame[/* name */0];

var tomorrowsGame = /* record */[
  /* name */todaysGame[/* name */0],
  /* players */5
];

var currentlyPlaying = /* record */[
  /* artist */"Beatles",
  /* name */"Hey Jude"
];

currentlyPlaying[/* name */1] = "I Want To Hold Your Hand";

var foo = /* record */[
  /* name */"hello",
  /* field : true */1
];

var bar = /* record */[
  /* name */"hello",
  /* field : true */1
];

console.log(Caml_obj.caml_equal(foo, bar));

var field = /* true */1;

exports.todaysGame       = todaysGame;
exports.name             = name;
exports.tomorrowsGame    = tomorrowsGame;
exports.currentlyPlaying = currentlyPlaying;
exports.field            = field;
exports.foo              = foo;
exports.bar              = bar;
/*  Not a pure module */
