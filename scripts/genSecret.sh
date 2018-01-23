#!/bin/bash

if [ $# -ne 2 ]
then
    echo "Correct usage: ./genSecret.sh <privateName> <publicName>"
else
    set -x #echo on
    openssl pkeyutl -derive -inkey $1_priv.pem -peerkey $2_pub.pem -out $1_$2_secret.bin
    base64 $1_$2_secret.bin
fi
