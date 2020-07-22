#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n; 

    do {
        n = get_int("Height: "); //We prompt the user the pyramid's height.
    } while (n < 1 || n > 8);    //It must be a number between 1 and 8, else we'll prompt again until we get it right.

    
    /*LOOP TIME!
        
     We'll begin printing the pyramid of hashes.    
    */
    
    // I == ROWS 
    
    for(int i = 1; i <= n; i++){    
        
    // J == SPACES
        for(int j = 1; j <= (n - i); j++){ // (HEIGHT - ROWS) = SPACES. We print the spaces before the hashes: the number is the opposite to the hashes of each row.
            printf(" ");
        }
    // K == HASH 
        for(int k = 0; k < i; k++){        //Now, we print the hashes for the current row.
            printf("#");                   
        }

        printf("  ");                       //Middle space
        
    // L == HASH 2: RELOADED    
        for(int l = 0; l < i; l++){        //We print hashes just like we did in K but now we don't have spaces at the beginning.     
            printf("#");
        }

        printf("\n");           //We start a new line.
    }
}