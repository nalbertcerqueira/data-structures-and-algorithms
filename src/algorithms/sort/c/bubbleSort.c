#include <stdio.h>

int bubbleSort(int *arr, int arrLength) {
    if (arrLength <= 0){
        printf("Array length must be greater than 0");
        return -1;
    } else if (arrLength == 1){
        return 0;
    }

    int temp;

    for (int i=0; i<arrLength - 1; i++){
        int isSorted = 1;

        for (int j = 0; j < arrLength -i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                isSorted = 0;
            }
        }
        if (isSorted){
            break;
        }
    }

    return 0;
}
