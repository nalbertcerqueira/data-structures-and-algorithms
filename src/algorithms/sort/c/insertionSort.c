#include <stdio.h>

int insertionSort(int *arr, int arrLength) {
    if(arrLength <= 0){
        printf("Array length must be greater than 0");
        return -1;
    } else if (arrLength == 1){
        return 0;
    }

    for (int i = 1; i < arrLength; i++) {
        int valueToInsert = arr[i];
        int j = i -1 ;

        while(j >= 0 && valueToInsert < arr[j]){
            arr[j + 1] = arr[j];
            j -= 1;
        }

        arr[j+1] = valueToInsert;
    }

    return 0;
}
