/* This is like
   import { authorName } from 'module1'
   console.log(authorName)
   in JavaScript */
Module1.authorName |> Js.log;

/* Same as */
Js.log(Module1.authorName);

/* This "imports" from subdir/module2.re because module names are directory-agnostic */
Js.log(Module2.authorName);
