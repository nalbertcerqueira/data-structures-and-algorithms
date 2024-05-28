#include <stdio.h>

static void swap(int *values, int i, int j){
    if (i != j){
        int temp = values[i];
        values[i] = values[j];
        values[j] = temp;
    }
}

static void partition1(int *values, int start, int end){
    if (end <= start){
        return;
    }

    int i = start;

    for (int j = start; j < end; j++){
        if (values[j] < values[end]){
            swap(values, i, j);
            i += 1;
        }
    }

    swap(values, i, end);
    partition1(values, start, i-1);
    partition1(values, i+1, end);
}

static void partition2(int *values, int start, int end){
    if (end <= start) {
        return;
    }

    int ref = values[start];
    int left = start + 1;
    int right = end;

    while (left <= right) {
        if (values[left] > ref && values[right] < ref) {
            swap(values, left, right);
        }

        if (values[left] <= ref) {
            left += 1;
        }

        if (values[right] >= ref) {
            right -= 1;
        }
    }

    int pivotIndex = right;
    swap(values, pivotIndex, start);

    partition2(values, start, pivotIndex - 1);
    partition2(values, pivotIndex + 1, end);
}


int quickSort1(int *arr, int arrLength){
    if (arrLength <= 0){
        printf("Array length must be greater than 0");
        return -1;
    } else if (arrLength == 1){
        return 0;
    }

    partition1(arr, 0, arrLength - 1);
    return 0;
}

int quickSort2(int *arr, int arrLength){
    if (arrLength <= 0){
        printf("Array length must be greater than 0");
        return -1;
    } else if (arrLength == 1){
        return 0;
    }

    partition2(arr, 0, arrLength - 1);
    return 0;
}


