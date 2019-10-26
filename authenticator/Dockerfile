FROM node:lts-alpine as builder

WORKDIR /cloudvpn/authenticator

COPY package.json package.json
COPY yarn.lock yarn.lock
RUN yarn install --frozen-lockfile

COPY . .
RUN yarn build:prod

FROM node:lts-alpine

RUN chown node -R /usr/local/lib/node_modules

WORKDIR /home/node/cloudvpn/authenticator
RUN chown -R node /home/node /usr/local

USER node

COPY package.json package.json
COPY yarn.lock yarn.lock
RUN yarn install --production --frozen-lockfile

COPY --from=builder --chown=node /cloudvpn/authenticator/build build
CMD [ "yarn", "start" ]
