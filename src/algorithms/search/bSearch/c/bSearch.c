#include <stdio.h>

int bSearch(int *arr, int arrLength, int target){
    int leftIndex = 0;
    int rightIndex = arrLength - 1;

    while(leftIndex <= rightIndex){
        int middleIndex = (leftIndex + rightIndex) / 2;
        int pivot = arr[middleIndex];

        if (pivot == target){
            return middleIndex;
        }

        if (target> pivot){
            leftIndex = middleIndex + 1;
        } else{
            rightIndex = middleIndex - 1;
        }
    }

    return -1;
}
