type t;

[@bs.deriving abstract]
type data = {
  [@bs.as "Name"] name: string,
  [@bs.as "Value"] value: string
};

[@bs.send] external getValue: t => string = "getValue";
[@bs.send] external setValue: (t, ~value: string) => t = "setValue";
[@bs.send] external getName: t => string = "getName";
[@bs.send] external setName: (t, ~name: string) => t = "setName";
[@bs.send] external toString: t => string = "toString";
[@bs.send] external toJSON: t => Js.Json.t = "toJSON";

[@bs.module "amazon-cognito-identity-js"] [@bs.new] 
external make: (~data: data) => t = "CognitoUserAttribute";