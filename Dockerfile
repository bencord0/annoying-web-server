FROM gcc as builder

ADD Makefile /app/
ADD main.c /app/

WORKDIR /app/
RUN make

FROM scratch
COPY --from=builder /app/annoying-web-server /annoying-web-server

ENTRYPOINT ["/annoying-web-server"]
