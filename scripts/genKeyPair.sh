#!/bin/bash

if [ $# -ne 1 ]
then
    echo "Correct usage: ./genKeyPair.sh <keyName>"
else
    set -x #echo on
    export RANDFILE=./.rnd
    openssl ecparam -name secp256k1 -genkey -noout -out $1_priv.pem
    openssl ec -in $1_priv.pem -pubout -out $1_pub.pem
    cat $1_pub.pem
fi

