# bs-aws-amplify
BuckleScript bindings for AWS Amplify client library **(work in progress)**

### Trying out
While work in progress, this package is available at [Github Package Registry](https://github.com/features/packages)

To use the GPR, change the registry for the @amblientlight scope
before installing, in your project directory, run:

```bash
echo "@ambientlight:registry=https://npm.pkg.github.com" >> .npmrc
yarn install @ambientlight/bs-aws-amplify
# if yarn fails with integrity failure, please add dependency manually to package.json and run the following
yarn --update-checksums
```
Then add `@ambientlight/bs-aws-amplify` into `bs-dependencies` in your project `bsconfig.json`

## Configuring

1. after running `amplify init` or `amplify configure` or `amplify env add` `aws-exports.js` should be generated in the specified src folder (as defined in `amplify/.config/project-config.json`)
2. add bindings for `aws-exports.js` as `AWSExports.re` given that source folder is `src/`

  ```reason
  [@bs.deriving abstract]
  type t = {
    aws_project_region: string,
    aws_cognito_identity_pool_id: string,
    aws_cognito_region: string,
    aws_user_pools_id: string,
    aws_user_pools_web_client_id: string,
    aws_content_delivery_bucket: string,
    aws_content_delivery_url: string,
    aws_appsync_graphqlEndpoint: string,
    aws_appsync_region: string,
    aws_appsync_authenticationType: string,
    aws_appsync_apiKey: string
  };

  [@bs.module "src/aws-exports"][@bs.val]
  external config: t = "default";
  ```

3. then in your entry (often `Index.re`) run `Amplify.configure`:

  ```reason
  open AWSAmplify
  Amplify.amplify |. Amplify.configure(AWSExports.config);
  ```
