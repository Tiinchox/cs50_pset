#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    //Initialize cash. It must accept decimal numbers so we used FLOAT instead of INT.
    float cash = 0.0;
    
    //Coins
    int qt = 25; //Quarter
    int dm = 10; //Dime
    int nk = 5;  //Nickel     
    int pn = 1;  //Penny
    
    //Initialize coins.
    int coins = 0;

    //Prompt user to input change. If the user inputs a negative number, we will prompt again until we receive a positive one.
    
    do{
        cash = get_float("Change owed\n");
    } while (cash < 0);

    //Convert dollars to cents.
    
    int cents = round(cash * 100);
    
    //We need to check how many of each coin we'll give back as change.
    
    //How many quarters?
    while (cents >= qt){
        coins++;
        (cents -= qt);
    } 

    //How many dimes?
    while (cents >= dm){
        coins++;
        (cents -= dm);
    }
    
    //How many nickels?
    while (cents >= nk){
        coins++;
        (cents -= nk);
    } 
    
    //How many pennies?
    while (cents >= pn){
        coins++;
        (cents -= pn);
    }
    
    //We finally print the minimum amount of coins we give back as change. 
    printf("Coins returned: %i\n", coins);
}