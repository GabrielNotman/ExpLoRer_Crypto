#!/bin/bash

echo "Testing enrypting with AES-256 CBC mode"
echo -n "Enter plain text: "
read plaintext
echo -n $plaintext > plain.tmp

echo -n "Enter IV HEX: "
read iv

echo "Cipher text:"
openssl enc -aes-256-cbc -nosalt -iv $iv -K $(xxd -p -u -c256 host_device_secret.bin) -e -in plain.tmp | xxd -p -c256 -u

rm plain.tmp
