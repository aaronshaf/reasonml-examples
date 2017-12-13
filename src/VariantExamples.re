/* Variants are like enums */
type dataLoadingStatusVariant =
  | Loading
  | Successful
  | Error;

/* Variant (enum) cases must start with upper-case letter
      type dataLoadingStatusVariant =
        | loading
        | successful;
      ... would be invalid

   */
/* If you're wondering... where did Loading, Successful, and Error come from?
   They were automatically constructed above. Compare this pseudocode:

      constructor Loading;
      constructor Successful;
      constructor Error;

      type dataLoadingStatusVariant = Loading | Successful | Error;
   */
let dataLoadingStatus = Loading;

let message =
  switch dataLoadingStatus {
  | Loading => "Loading"
  | Successful => "Successful"
  | Error => "Error"
  };

message |> Js.log;

/* Variant constructors can have arguments */
type customerInfo =
  | None
  | Name(string)
  | Order(string, int);

let info = Order("Josh", 26);

let greeting =
  switch info {
  | None => "How can I help you?"
  | Order(item, quantity) =>
    "You rordered " ++ string_of_int(quantity) ++ " of " ++ item
  | Name(name) => "Hello " ++ name ++ "!"
  };

greeting |> Js.log;
/*
 TODO: option, Some('a), None */
