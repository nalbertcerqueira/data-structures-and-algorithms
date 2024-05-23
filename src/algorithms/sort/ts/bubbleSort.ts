export function bubbleSort(values: number[]): void {
    let isSorted = false

    while (!isSorted) {
        isSorted = true

        for (let j = 0; j < values.length - 1; j++) {
            if (values[j] > values[j + 1]) {
                const temp = values[j]
                values[j] = values[j + 1]
                values[j + 1] = temp

                isSorted = false
            }
        }
    }
}
