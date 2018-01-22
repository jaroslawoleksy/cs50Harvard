def run():
    while True:
        try:
            cardNumber = input("Number: ")
            cardNumberLength = len(cardNumber)
            if cardNumberLength < 13 or cardNumberLength > 16 or cardNumberLength == 14:
                print("INVALID")
                return
            cardNumber = int(cardNumber)
            if cardNumber > 0:
                break
        except ValueError:
            print("", end="")
            
    #Calculate Sum of Digits
    checkSum = calculateDigitSum(cardNumber)
    if checkSum % 10 == 0:
        firstTwoNumbers = int(str(cardNumber)[:2])
        if firstTwoNumbers == 34 or firstTwoNumbers == 37:
            print("AMEX")
        elif (firstTwoNumbers >= 51 and firstTwoNumbers <= 55):
            print("MASTERCARD")
        elif str(cardNumber)[0] == "4":
            print("VISA")
        else:
            print("INVALID")
    else:
        print("INVALID")
            
def calculateDigitSum(number):
    number = str(number)
    sum = 0
    x = len(number) - 1
    shouldSquare = False
    while x >= 0:
        if shouldSquare:
            toAdd = int(number[x]) * 2
            if toAdd >= 10:
                toAdd = 1 + toAdd % 10
            sum += toAdd
            shouldSquare = False
        else:
            sum += int(number[x])
            shouldSquare = True
        x -= 1
    return sum

if __name__ == "__main__":
    run()