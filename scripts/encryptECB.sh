#!/bin/bash

echo "Testing encrypting with AES-256 ECB mode"
echo -n "Enter plain text: "
read plaintext
echo -n $plaintext > plain.tmp

echo "Cipher text:"
openssl enc -aes-256-ecb -nosalt -k ./host_device_secret.bin -e -in plain.tmp | xxd -p -c16 -u

rm plain.tmp
