type t;

[@bs.send]
external configure: (t, 'a) => unit = "configure";

[@bs.val][@bs.module "aws-amplify"]
external amplify: t = "default";