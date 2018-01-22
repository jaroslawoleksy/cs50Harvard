while True:
    length = input("Height: ")
    if length.isdigit():
        length = int(length)
        if length < 24:
            break
n = length - 1
while(n >= 0):
    for i in range(n):
        print(" ", end="")
    for i in range(length - n):
        print("#", end="")
    n -= 1
    print("#")