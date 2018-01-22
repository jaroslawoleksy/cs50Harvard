while True:
    try:
        change = float(input("O hai! How much change is owed?"))
        if change > 0:
            break
    except ValueError:
        print("", end="")

cents = int(change * 100)
quarters = cents // 25
cents = cents % 25
dimes = cents // 10;
cents = cents % 10;
nickles = cents // 5;
cents = cents % 5;
pennies = cents;

print(quarters + dimes + nickles + pennies)