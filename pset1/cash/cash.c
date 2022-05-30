#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    float cash = 0.0;
    
    //Coins
    int qt = 25; //Quarter
    int dm = 10; //Dime
    int nk = 5;  //Nickel     
    int pn = 1;  //Penny
    
    int coins = 0;

    //Prompt user to input change
    
    do{
        cash = get_float("Change owed\n");
    } while (cash < 0);

    //Convert dollars to cents
    
    int cents = round(cash * 100);
  
    //Change in quarters
    while (cents >= qt){
        coins++;
        (cents -= qt);
    } 

    //Change in dimes
    while (cents >= dm){
        coins++;
        (cents -= dm);
    }
    
    //Change in nickels
    while (cents >= nk){
        coins++;
        (cents -= nk);
    } 
    
    //Change in pennies
    while (cents >= pn){
        coins++;
        (cents -= pn);
    }
    
    printf("Coins returned: %i\n", coins);
}
