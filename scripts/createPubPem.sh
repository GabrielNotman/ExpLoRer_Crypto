#!/bin/bash

header="3059301306072A8648CE3D020106082A8648CE3D03010703420004"
tempfname="tempDER.tmp"

if [ $# -ne 1 ]
then
    fname="device"
else
    fname=$1
fi

echo "Generating "$fname"_pub.pem from HEX string"
echo -n "Enter EC public key HEX: "
read key

echo $header.$key | xxd -r -p >$tempfname
echo "DER key:"
xxd -p -u -c32 $tempfname

openssl ec -pubin -inform DER -in $tempfname -outform PEM -out $fname"_pub.pem" 2>/dev/null
rm $tempfname
echo "PEM key:"
cat $fname"_pub.pem"
