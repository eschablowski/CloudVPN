FROM node:lts-alpine as builder

WORKDIR /cloudvpn/entrypoint

COPY package.json package.json
COPY yarn.lock yarn.lock
RUN yarn install #--frozen-lockfile

COPY . .
RUN yarn build:prod

FROM node:lts-alpine

COPY package.json package.json
COPY yarn.lock yarn.lock
RUN yarn install --production #--frozen-lockfile

COPY --from=builder /cloudvpn/entrypoint/build build
CMD [ "yarn", "start" ]
