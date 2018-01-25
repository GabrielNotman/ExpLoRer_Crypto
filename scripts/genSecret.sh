#!/bin/bash

if [ $# -ne 2 ]
then
    privname="host"
    pubname="device"   
else
    privname=$1
    pubname=$2
fi

echo "Generating shared secret using: "$privname"_priv.pem & "$pubname"_pub.pem"    
echo "Saving shared secreted to: "$privname"_"$pubname"_secret.bin"
openssl pkeyutl -derive -inkey $privname"_priv.pem" -peerkey $pubname"_pub.pem" -out $privname"_"$pubname"_secret.bin"
echo "Hex dump of "$privname"_"$pubname"_secret.bin: "
xxd -p -u -c256 < $privname"_"$pubname"_secret.bin"

