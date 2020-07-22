#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int main(void){
    
    //These are our main variables.
    int letters = 0;
    int words = 1; //
    int sentences = 0;
    
    //Prompt user to input a text.
    string text = get_string("Insert text: ");
    
    //Calculate the string's length needed for the loop.
    int length = strlen(text);
    
    //Strings are arrays of characters. 
    //We are going to loop for every character of the string to identify if we have a letter, a space or a punctuation mark.
    for(int i = 0; i < length; i++){
        
        //We count the letters
        if((text[i] >= 'a' && text[i]<= 'z') || (text[i] >= 'A' && text[i]<= 'Z')){
            
            letters++;
            
        //We count words for every space we find.
        } if(text[i] == ' '){
            
            words++;
        //We count the sentences. The sentences usually ends with '.','?' or '!'.
        } if(text[i] == '.' || text[i] == '?' || text[i] == '!'){
            
            sentences ++;
        }
        
    }
    
    //Average number of letters per 100 words in the text.
    float L = (float) letters / (float) words * 100;
    //Average number of sentences per 100 words in the text.
    float S = (float) sentences / (float) words * 100;
    
    //The Coleman-Liau formula.
    float index = 0.0588 * L - 0.296 * S - 15.8;
    
    //We want an integer as a grade, so we round the index.
    int grade = round(index);
    
    
    //Print the grade.
    if(grade < 1){                  //If the grade number is less than 1 we are going to display "Before Grade 1"
        printf("Before Grade 1\n"); 
    } else if(grade > 16){          //If the grade number is greater than 16 we are going to display "Grade 16+"
        printf("Grade 16+\n");
    } else{                         //Else we will display "Grade " followed by the grade number.    
        printf("Grade %i\n",grade);
    }
    
    
}

