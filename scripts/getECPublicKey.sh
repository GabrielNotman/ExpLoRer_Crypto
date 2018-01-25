#!/bin/bash

if [ $# -ne 1 ]
then
    fname="host"
else
    fname=$1
fi

echo "Extracting EC public key: "
openssl ec -pubin -in $fname"_pub.pem" -outform DER 2>/dev/null | xxd -p -s27 -c256 -u


