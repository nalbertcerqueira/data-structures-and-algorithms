int* bubbleSort(int *arr, int arrLength) {
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
        if(isSorted){
            break;
        }
    }

    return arr;
}
