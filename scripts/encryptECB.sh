#!/bin/bash

echo "Testing encrypting with AES-256 ECB mode"
echo -n "Enter plain text: "
read plaintext
echo -n $plaintext > plain.tmp

echo "Cipher text:"
openssl enc -aes-256-ecb -nosalt -K $(xxd -p -u -c256 host_device_secret.bin) -e -in plain.tmp | xxd -p -c256 -u

rm plain.tmp
