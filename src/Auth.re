type t;

module CognitoUser {
  [@bs.deriving abstract]
  type t = {
    username: string,
    [@bs.optional] challengeName: string
  }
};

module SignUpParams {
  [@bs.deriving abstract]
  type t = {
    username: string,
    password: string,
    [@bs.optional] attributes: Js.Dict.t(string),
    [@bs.optional] validationData: array(CognitoUserAttribute.t)
  }
};

module ConfirmSignUpOptions {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional] forceAliasCreation: bool
  }
};

module SignUpResult {
  [@bs.deriving abstract]
  type t = {
    user: CognitoUser.t,
    userConfirmed: bool,
  }
};

module SignOutOpts {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional] global: bool
  };
};

[@bs.val][@bs.module "aws-amplify"]
external auth: t = "Auth";

/**
  Get current user's session

    @return A promise resolves to session object if success
  */
[@bs.send]
external currentSession: t => Js.Promise.t(CognitoUserSession.t) = "currentSession";

[@bs.module "aws-amplify"][@bs.scope "Auth"]
external signIn: (~username: string, ~password: string) => Js.Promise.t(CognitoUser.t) = "signIn";

[@bs.module "aws-amplify"][@bs.scope "Auth"]
external completeNewPassword: (~user: CognitoUser.t, ~password: string, ~requiredAttributes: Js.t({.})=?, unit) => Js.Promise.t(CognitoUser.t) = "completeNewPassword";

[@bs.module "aws-amplify"][@bs.scope "Auth"]
external signUp: (~params: SignUpParams.t) => Js.Promise.t(SignUpResult.t) = "signUp";

[@bs.module "aws-amplify"][@bs.scope "Auth"]
external confirmSignUp: (~username: string, ~code: string, ~options: option(ConfirmSignUpOptions.t)=?, unit) => Js.Promise.t(Js.t({.})) = "confirmSignUp";

[@bs.module "aws-amplify"][@bs.scope "Auth"]
external resendSignUp: (~username: string) => Js.Promise.t(string) = "resendSignUp";

[@bs.module "aws-amplify"][@bs.scope "Auth"]
external signOut: (~opts: option(SignOutOpts.t)=?, unit) => Js.Promise.t(Js.t({.})) = "signOut";