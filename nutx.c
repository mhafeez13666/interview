
#include <stdio.h>

// Program to print a given positive integer into thousands, millions, billions
// separated by commas

int main() {
    
    long int number = 1012223034045;
    long int scale  = 1000;
    
    //Find the maximum scale to divide the integer
    while (number > 0){
        if (number/scale < 1000) break;
        else {
            scale *= 1000;
        }
    }
    //Scale will now have the highest multiplication factor
    
    //Holder for each 3 digit number
    long int digitSlot;
    digitSlot = number/scale;

    //If it is less than 1000 then just print and leave
    if (number <= 999){
        printf("%ld",number);
    }
    else {
        //Print the first slot
        printf("%ld",digitSlot);
        
        //Loop till the last thousand
        while (number >= 1000){
            number = number - digitSlot*scale;
            scale /= 1000;
            digitSlot = number/scale;
            printf(",%03ld",digitSlot);

        }
    }
    
    printf("\n");
    
    return 0;
}