#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n; 

    do {
        n = get_int("Height: "); 
    } while (n < 1 || n > 8);  

    
    /*LOOP TIME!
     We'll begin printing the pyramid of hashes.    
    */
    
    // I == ROWS 
    
    for(int i = 1; i <= n; i++){    
        
    // J == SPACES
        for(int j = 1; j <= (n - i); j++){ 
            printf(" ");
        }
    // K == HASH 
        for(int k = 0; k < i; k++){       
            printf("#");                   
        }

        printf("  ");                       
        
    // L == HASH 2: RELOADED    
        for(int l = 0; l < i; l++){            
            printf("#");
        }

        printf("\n");           
    }
}
