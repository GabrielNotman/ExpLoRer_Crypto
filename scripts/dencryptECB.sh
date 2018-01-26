#!/bin/bash

echo "Testing decrypting with AES-256 ECB mode"
echo -n "Enter cipher HEX: "
read cipher
echo $cipher | xxd -r -p > cipher.tmp

set -x
echo -n "Plain text: "
openssl enc -aes-256-ecb -nosalt -p -K $(xxd -p -c256 host_device_secret.bin) -d -in cipher.tmp -out plain.tmp
echo "" >> plain.tmp
cat plain.tmp

rm cipher.tmp
rm plain.tmp
