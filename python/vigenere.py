import sys

def run():
    if len(sys.argv) != 2:
        print("Usage: python vigenere.py k")
        return
    k = sys.argv[1]
    for i in range(0, len(k)):
        if k[i].isalpha() == False:
            print("Usage: python vigenere.py k")
            return
    
    plaintext = input("plaintext: ")
    print("ciphertext: ", end="")
    currentKeyLetterCount = 0
    for i in range(0, len(plaintext)):
        if plaintext[i].isalpha():
            if k[currentKeyLetterCount].isupper():
                key = ord(k[currentKeyLetterCount]) - 65
            else:
                key = ord(k[currentKeyLetterCount]) - 97
            currentKeyLetterCount += 1
            currentKeyLetterCount %= len(k)
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
        
                
if __name__ == "__main__":
    run()