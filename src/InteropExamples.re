[@bs.deriving jsConverter]
type thing = {
  foo: string,
  bar: int
};

let thing1 = {foo: "a", bar: 1};

Js.log(thing1); /* [ 'a', 1 ] */

Js.log(thing1 |> thingToJs); /* { foo: 'a', bar: 1 } */