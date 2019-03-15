# Annoying Web Server

When trying to debug microservices, sometimes you have to be prepared for anything.

## Usage

    docker build -t bencord0/annoying-web-server .
    docker run --name aws --rm -p 8000:8000 bencord0/annoying-web-server

## Try it out

    curl --max-time 5 localhost:8000
