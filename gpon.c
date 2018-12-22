
#include <stdio.h>
#include <stdbool.h>

int main(){

    int array[]       = {1,2,3,4,5,6,30,29,11,10,9,7};
    int lengthOfArray = sizeof(array)/sizeof(array[0]);

    int  largestNumber = array[0];
    int  peakIndex     = 0;
    bool isPyramid    = true;

    for (int index = 1;index < (lengthOfArray-1);index++){

        //Loop till you get the largest number in the array
        if (array[index] > largestNumber){
            largestNumber = array[index];
        }
        else {
            peakIndex = index;
            break;
        }

    }

    printf("The peak index is %d and largest number is %d\n", peakIndex, largestNumber);

    for (int index = peakIndex; index < lengthOfArray;index++){

        if (array[index] > array[index-1]){
            isPyramid = false;
            break;
        }
        else {
            continue;
        }
    }

    if (isPyramid){
        printf("Given array is a Pyramid\n");
    }
    else {
        printf("Given array is not a Pyramid\n");

    }
    return 1;
}