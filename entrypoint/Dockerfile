FROM alpine:latest as builder

RUN apk add --no-cache make g++ cmake curl-dev boost-dev linux-headers git

WORKDIR /entrypoint

COPY . .

WORKDIR /entrypoint/build

RUN cmake .. \
    && make
    # && make install

CMD [ "/entrypoint/build/CloudVPN_entrypoint" ]

FROM alpine:latest

RUN apk add --no-cache curl-dev boost-dev linux-headers

COPY --from=builder /entrypoint/build/CloudVPN_entrypoint /bin/entrypoint

CMD [ "/bin/entrypoint" ]
