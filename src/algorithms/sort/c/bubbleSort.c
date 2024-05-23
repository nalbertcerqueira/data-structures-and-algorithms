int* bubbleSort(int *arr, int arrLength) {
    int isSorted = 0;

    while(!isSorted){
        isSorted = 1;

        for (int j = 0; j < arrLength - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                isSorted = 0;
            }
        }
    }

    return arr;
}
