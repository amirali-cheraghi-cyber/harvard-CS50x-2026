from cs50 import get_float

while True:
    change = get_float("Change owed: ")
    if change >= 0:
        break

cents = round(change * 100)

coins = 0

while cents >= 25:
    cents = cents - 25
    coins = coins + 1

while cents >= 10:
    cents = cents - 10
    coins = coins + 1

while cents >= 5:
    cents = cents - 5
    coins = coins + 1

while cents >= 1:
    cents = cents - 1
    coins = coins + 1

print(coins)
