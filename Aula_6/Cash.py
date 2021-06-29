from cs50 import get_float

def main():
    cash = change()*100
    coins = 0

    while cash >= 25:
        cash = cash - 25
        coins += 1
    while cash >= 10:
        cash = cash - 10
        coins += 1
    while cash >= 5:
        cash = cash - 5
        coins += 1
    while cash >= 1:
        cash = cash - 1
        coins += 1

    print(coins)



def change():
    while True:
        money = get_float("Change owned: ")
        if money > 0:
            break
    return money

main()