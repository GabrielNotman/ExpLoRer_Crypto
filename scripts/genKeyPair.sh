#!/bin/bash

if [ $# -ne 1 ]
then
    echo "Correct usage: ./genKeyPair.sh <keyName>"
else
    export RANDFILE=./.rnd
    echo "Generating EC key pair using prime256v1"
    echo "Generating private key: "$1"_priv.pem"
    openssl ecparam -name prime256v1 -genkey -noout -out $1_priv.pem
    echo "Deriving public key: "$1"_pub.pem"
    openssl ec -in $1_priv.pem -pubout -out $1_pub.pem 2>/dev/null
    echo "Extracting ECC public key: "
    openssl ec -pubin -in $1_pub.pem -outform DER 2>/dev/null | xxd -p -s27 -c256 -u
fi

