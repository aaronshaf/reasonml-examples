/* https://bucklescript.github.io/docs/en/generate-converters-accessors.html
 */
[@bs.deriving jsConverter]
type thing = {
  foo: string,
  bar: int
};

let thing1 = {foo: "a", bar: 1};

thing1 |> Js.log; /* [ 'a', 1 ] */

thing1 |> thingToJs |> Js.log; /* { foo: 'a', bar: 1 } */

[@bs.deriving jsConverter]
type hockey =
  | Ice
  | Inline
  | Field;

hockeyToJs(Inline) |> Js.log; /* 1 */

switch (hockeyFromJs(2)) {
| Some(Ice) => Js.log("Ice hockey")
| Some(Inline) => Js.log("Inline hockey")
| Some(Field) => Js.log("Field hockey")
| _ => Js.log("received something wrong from the JS side")
}; /* Field hockey */
