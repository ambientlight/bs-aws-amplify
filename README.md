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
