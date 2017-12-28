type game = {
  name: string,
  mutable players: int
};

let todaysGame = {name: "Catan", players: 4};

/* access field */
let name = todaysGame.name;

/* immutable update */
let tomorrowsGame = {...todaysGame, players: 5};

/* mutable update */
type song = {
  artist: string,
  mutable name: string
};

let currentlyPlaying = {artist: "Beatles", name: "Hey Jude"};

currentlyPlaying.name = "I Want To Hold Your Hand";

/* punning */
type thing = {
  name: string,
  field: bool
};

let field = true;

let foo: thing = {name: "hello", field};

let bar: thing = {name: "hello", field: true};

Js.log(foo == bar); /* 1 (true) */