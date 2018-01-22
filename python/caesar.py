import sys

if len(sys.argv) != 2:
    print("Usage: python caesar.py k", end="")
else:
    key = int(sys.argv[1])
    key = key % 26
    plaintext = input("plaintext:  ")
    print("ciphertext: ", end="")
    for i in range(0, len(plaintext)):
        if plaintext[i].isalpha():
            newAscii = ord(plaintext[i]) + key
            if ord(plaintext[i]) >= 97:
                if newAscii > 122:
                    newAscii = 97 - 123 + newAscii
            if ord(plaintext[i]) <= 90:
                if newAscii > 90:
                    newAscii = 65 - 91 + newAscii
            print(chr(newAscii), end="")
        else:
            print(plaintext[i], end="")

print("")