#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0; i < height; i++){

        for(int j = 0; j < width; j++){

            // For a grayscale filter all RGB values should be the same, so we want to calculate the average and then round it
            int avg = round((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0);

            // We assign the new values for the grayscale filter
            image[i][j].rgbtBlue = avg;
            image[i][j].rgbtGreen = avg;
            image[i][j].rgbtRed = avg;
        }

    }


    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{

    for(int i = 0; i < height; i++){

        for(int j = 0; j < width; j++){

            // Variables for original colors
            int originalRed = image[i][j].rgbtRed;
            int originalGreen = image[i][j].rgbtGreen;
            int originalBlue = image[i][j].rgbtBlue;
    
            // We paste the formula for the sepia filter and then we use round to convert it to an int
            int sepiaRed = round(.393 * originalRed + .769 * originalGreen + .189 * originalBlue);
            int sepiaGreen = round(.349 * originalRed + .686 * originalGreen + .168 * originalBlue);
            int sepiaBlue = round(.272 * originalRed + .534 * originalGreen + .131 * originalBlue);
            
            // We assign the new values for the sepia filter
            image[i][j].rgbtRed = (sepiaRed > 255) ? 255 : sepiaRed;        // If the value it's greater than 255 we'll overflow and will get an error
            image[i][j].rgbtGreen = (sepiaGreen > 255) ? 255 : sepiaGreen;  // so we use a formula so that we cannot go past 255
            image[i][j].rgbtBlue = (sepiaBlue > 255) ? 255 : sepiaBlue;
        
            
        }

    }


    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    
    for(int i = 0; i < height; i++){
        
        for(int j = 0; j < (width / 2); j++){
            
            int red = image[i][j].rgbtRed;
            int green = image[i][j].rgbtGreen;
            int blue = image[i][j].rgbtBlue;
            
            image[i][j].rgbtRed = image[i][width - j - 1].rgbtRed;
            image[i][j].rgbtGreen = image[i][width - j - 1].rgbtGreen;
            image[i][j].rgbtBlue = image[i][width - j - 1].rgbtBlue;
            
            image[i][width - j - 1].rgbtRed = red;
            image[i][width - j - 1].rgbtGreen = green;
            image[i][width - j - 1].rgbtBlue = blue;
            
            
            
        }
        
    }
    
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    
    RGBTRIPLE temp[height][width];
   
    for(int i = 0; i < height; i++){
        
        for(int j = 0; j < width; j++){
            
            int sumRed = 0;
            int sumGreen = 0;
            int sumBlue = 0;
            float counter = 0.00;
            
            for(int k = -1; k < 2; k++){
                
                for(int l = -1; l < 2; l++){
                    
                    if(i + k < 0 || i + k > height - 1 || j + l < 0 || j + l > width - 1){
                        
                        continue;
                        
                    }
                    
                    sumRed += image[i + k][j + l].rgbtRed;
                    sumGreen += image[i + k][j + l].rgbtGreen;
                    sumBlue += image[i + k][j + l].rgbtBlue;
                    
                    counter++;
                }
                
            }
            
            temp[i][j].rgbtRed = round(sumRed / counter);
            temp[i][j].rgbtGreen = round(sumGreen / counter);
            temp[i][j].rgbtBlue = round(sumBlue / counter);
        }
        
    } 

    for(int i = 0; i < height; i++){
        
        for(int j = 0; j < height; j++){
            
            image[i][j].rgbtRed = temp[i][j].rgbtRed;
            image[i][j].rgbtGreen = temp[i][j].rgbtGreen;
            image[i][j].rgbtBlue = temp[i][j].rgbtBlue;
        }
        
    }
    
    return;
}
