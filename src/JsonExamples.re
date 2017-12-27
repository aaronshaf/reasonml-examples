/* using generated converter instead of custom decoder */
[@bs.deriving jsConverter]
type game = {
  name: string,
  players: int
};

let json = {| {
  "name": "Monopoly",
  "players": 6
} |};

json |> Json.parseOrRaise |> Obj.magic |> gameFromJs |> Js.log; /* [ 'Monopoly', 6 ] */

/* using custom decoder */
let decodeGame = (json) : game =>
  Json.Decode.{name: json |> field("name", string), players: json |> field("players", int)};

json |> Json.parseOrRaise |> decodeGame |> Js.log; /* [ 'Monopoly', 6 ] */

let json2 = {| [
{
  "name": "Monopoly",
  "players": 6
},
{
  "name": "Catan",
  "players": 4
}
] |};

/* using nested decoder */
let decodeGames = (json) => json |> Json.Decode.list(decodeGame);

json2 |> Json.parseOrRaise |> decodeGames |> Js.log; /* [ [ 'Monopoly', 6 ], [ [ 'Catan', 4 ], 0 ] ] */