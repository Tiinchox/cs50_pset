#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

bool check_valid_key(string s);

// Since we are working with command line arguments we don't use void, instead argc and argv

int main(int argc, string argv[]){

// If the user don't write anything or if the key is invalid we're going to show a message

    if(argc != 2 || !check_valid_key(argv[1])){

        printf("Usage: ./caesar key\n");

        return 1;
    }

    //This is the KEY the user inputs so we can cipher the message
    
    int key = atoi(argv[1]); // atoi() converts an ASCII into an integer

// We prompt the user to input some text
    string plaintext = get_string("plaintext: ");

    printf("ciphertext: ");
    
// And now we want to cipher that text

    for(int i = 0, n = strlen(plaintext); i < n; i++){

        char c = plaintext[i]; // We'll check one character at the time

        if(isalpha(c)){

        char m = 'A'; // We don't start from 0, but from "A" (65)

        if(islower(c)){

        m = 'a'; 
        }
        
        /*  The original formula is ci = (pi + k) % 26, however for the formula to work we want pi == 0.
            Since in ASCII "A" is 65, we want to substract "m" to "c" and at the end we want to add "m" again.
            It's kinda tricky to explain but... it works!
        */
        printf("%c", (c - m + key) % 26 + m);

        }

        // If the character is not alphabetic we just print it without any change
        
        else {

            printf("%c",c);

        }
    }

    // Let's print a new line
    
    printf("\n");

}

// Checks if the user's key is a decimal digit

bool check_valid_key(string s){

    for(int i = 0, n = strlen(s); i < n; i++){

        if(!isdigit(s[i])){

            return false;
        }

    }

    return true;

}