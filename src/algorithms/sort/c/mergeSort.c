#include <stdio.h>
#include <stdlib.h>

static void merge(int *arr, int start, int middle, int end){
    int leftSize = middle - start + 1;
    int rightSize = end - middle;

    int *leftArray = malloc(sizeof(int) * leftSize);
    int *rightArray = malloc(sizeof(int) * rightSize);

    for (int i=0; i<leftSize; i++){
        leftArray[i] = arr[i+start];
    }

    for (int j=0; j<rightSize; j++){
        rightArray[j] = arr[j + middle + 1];
    }

    int i = 0;
    int j = 0;
    int currIndex = start;

    while (i < leftSize || j < rightSize){
        if (i < leftSize  && j < rightSize){
            if (leftArray[i] < rightArray[j]){
                arr[currIndex] = leftArray[i];
                i += 1;
            } else {
                arr[currIndex] = rightArray[j];
                j += 1;
            }
        } else {
            if (i < leftSize){
                arr[currIndex] = leftArray[i];
                i += 1;
            }
            if (j < rightSize){
                arr[currIndex] = rightArray[j];
                j += 1;
            }
        }
        currIndex += 1;
    }

    free(leftArray);
    free(rightArray);
}

static void partition(int *arr, int start, int end){
    if (end <= start){
        return;
    }

    int middle = (start + end)/2;
    partition(arr, start, middle);
    partition(arr, middle + 1, end);
    merge(arr, start, middle, end);
}

int mergeSort(int *arr, int arrLength){
    if (arrLength <= 0){
        printf("Array length must be greater than 0");
        return -1;
    } else if(arrLength == 1){
        return 0;
    }

    partition(arr, 0, arrLength - 1);
    return 0;
}
