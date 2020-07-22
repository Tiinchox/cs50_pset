from cs50 import get_float

def main():

    change = get_change()
    cents = change * 100

    ## Coins
    quarter = 25
    dime = 10
    nickel = 5
    penny = 1

    coins = 0

    ##How many quarters?
    while cents >= quarter:

        coins += 1
        cents -= quarter

    ##How many dimes?
    while cents >= dime:

        coins += 1
        cents -= dime

    ##How many nickels?
    while cents >= nickel:

        coins += 1
        cents -= nickel

    ##How many pennies?
    while cents >= penny:

        coins += 1
        cents -= penny

    ##We print the total of coins returned
    print(f"Coins returned: {coins}")

def get_change():

    while True:
        change = get_float("Change owed: ")

    ##User can only input positive values
        if change > 0:
            break
    return change

main()
