#!/bin/sh

curl -u c0081524-782d-46dc-a096-e82e6810dc1d:nZwQHkEm6HXC -X POST \
--limit-rate 40000 \
--header "Content-Type: audio/flac" \
--header "Transfer-Encoding: chunked" \
--data-binary @../audio/0001.flac \
"https://stream.watsonplatform.net/speech-to-text/api/v1/recognize?continuous=true"
