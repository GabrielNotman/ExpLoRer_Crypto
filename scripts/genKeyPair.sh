#!/bin/bash

if [ $# -ne 1 ]
then
    fname="host"
else
    fname=$1
fi

keytypename="prime256v1"

export RANDFILE=./.rnd
echo "Generating EC key pair using $keytypename"
echo "Generating private key: "$fname"_priv.pem"
openssl ecparam -name $keytypename -genkey -noout -out $fname"_priv.pem"
echo "Deriving public key: "$fname"_pub.pem"
openssl ec -in $fname"_priv.pem" -pubout -out $fname"_pub.pem" 2>/dev/null
echo "Extracting EC public key: "
openssl ec -pubin -in $fname"_pub.pem" -outform DER 2>/dev/null | xxd -p -s27 -c256 -u


