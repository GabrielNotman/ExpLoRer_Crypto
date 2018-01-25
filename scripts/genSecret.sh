#!/bin/bash

if [ $# -ne 2 ]
then
    echo "Correct usage: ./genSecret.sh <privateName> <publicName>"
else
    echo "Generating shared secret using: $1_priv.pem & $2_pub.pem"    
    echo "Saving shared secreted to: $1_$2_secret.bin"
    openssl pkeyutl -derive -inkey $1_priv.pem -peerkey $2_pub.pem -out $1_$2_secret.bin
    echo "Hex dump of $1_$2_secret.bin: "
    xxd -p -u -c256 < $1_$2_secret.bin
fi
