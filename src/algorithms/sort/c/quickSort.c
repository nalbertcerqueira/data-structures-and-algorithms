#include <stdio.h>

static void swap(int *values, int i, int j){
    if (i != j){
        int temp = values[i];
        values[i] = values[j];
        values[j] = temp;
    }
}

static void partition(int *values, int begin, int end){
    if (end <= begin){
        return;
    }

    int i = begin;

    for (int j = begin; j < end; j++){
        if (values[j] < values[end]){
            swap(values, i, j);
            i += 1;
        }
    }

    swap(values, i, end);
    partition(values, begin, i-1);
    partition(values, i+1, end);
}

int quickSort(int *arr, int arrLength){
    if (arrLength <= 0){
        printf("Array length must be greater than 0");
        return -1;
    } else if (arrLength == 1){
        return 0;
    }

    partition(arr, 0, arrLength - 1);
    return 0;
}
