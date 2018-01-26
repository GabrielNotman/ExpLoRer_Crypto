#!/bin/bash

echo "Testing decrypting with AES-256 ECB mode"
echo -n "Enter cipher HEX: "
read cipher
echo $cipher | xxd -r -p > cipher.tmp

echo -n "Enter IV HEX: "
read iv

echo -n "Plain text: "

openssl enc -aes-256-cbc -nosalt -nopad -iv $iv -K $(xxd -p -u -c256 ./host_device_secret.bin) -d -in cipher.tmp -out plain.tmp
echo "" >> plain.tmp
cat plain.tmp

rm cipher.tmp
rm plain.tmp
