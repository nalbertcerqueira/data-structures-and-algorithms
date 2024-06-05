#include <stdio.h>

int selectionSort(int *arr, int arrLength){
    if (arrLength <= 0 ){
        printf("Array length must be greater than 0");
        return -1;
    } else if (arrLength == 1){
        return 0;
    }

    for (int i=0; i<arrLength - 1; i++){
        int selectedIndex = i;

        for (int j=i+1; j<arrLength; j++){
            if (arr[j] < arr[selectedIndex]){
                selectedIndex = j;
            }
        }

        int temp = arr[i];
        arr[i] = arr[selectedIndex];
        arr[selectedIndex] = temp;
    }

    return 0;
}
