type t;

[@bs.send]
external getAccessToken: t => CognitoAccessToken.t = "getAccessToken";