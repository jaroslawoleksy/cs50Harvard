import sys
import crypt
from itertools import product

def run():
    if len(sys.argv) != 2:
        print("Usage: python crack.py hashed")
        return
    
    hashedPassword = sys.argv[1]
    salt = hashedPassword[:2]
    print(crypt.crypt("ZZZZ", salt))
    for i in range(1, 5):
        keywords = product("abcdefghisjklmonpqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVXYZ", repeat = i)
        
        for word in keywords:
            password = ""
            for letter in word:
                password += letter
            if crypt.crypt(password, salt) == hashedPassword:
                print(password)
                return
    print("Password not found")

if __name__ == "__main__":
    run()