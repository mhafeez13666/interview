//
//  rollingHash.c
//  Rolling Hash function for rabinKarp Algorithm
//
//  Created by Mohamed Hafeez on 06/01/19.
//  Copyright © 2019 Mohamed Hafeez. All rights reserved.
//

#include <iostream>
#include <math.h>

//Define a prime number for the hash calculation
long prime_number = 101;

//To store the last character for which the hash was generated
char lastChar;

//To store the last calculated hash
unsigned long lastHash = 0;

//Function to generate the Hash using rolling method

unsigned long generateHash(char *str){
    
    unsigned long strLength = strlen(str);
    unsigned long hashValue = 0;
    unsigned long rollingHashValue = 0;

    //First time calculating hash
    if ( lastHash == 0 ) {
        for (int i=0;i<strLength;i++){
            hashValue += int(str[i]) * pow(prime_number,i);
        }
        lastChar = str[0];
        lastHash = hashValue;
        
        //Just to check. If this print happened more than once then the algorithm didn't work
        printf("Came only once\n");
        
        return hashValue;
    }
    
    //Find out the new character added
    char newAddedChar = str[strLength-1];
    
    rollingHashValue = lastHash - int(lastChar);
    rollingHashValue = rollingHashValue/prime_number;
    rollingHashValue = rollingHashValue + pow(prime_number, strLength - 1) * int(newAddedChar);
    
    //Store the last character
    lastChar = str[0];
    lastHash = rollingHashValue;
    
    return rollingHashValue;
}


int main(int argc, const char * argv[]) {
    
    printf ("Hash value is %ld\n", generateHash("abc"));
    printf ("Hash value is %ld\n", generateHash("bcd"));
    printf ("Hash value is %ld\n", generateHash("cde"));

    return 0;
}
