/* This is like
   import { authorName } from 'module1'
   console.log(authorName)
   in JavaScript */
Module1.authorName |> Js.log;

/* Same as */
Js.log(Module1.authorName);
