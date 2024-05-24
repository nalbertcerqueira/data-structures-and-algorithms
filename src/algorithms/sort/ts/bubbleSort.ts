export function bubbleSort(values: number[]): void {
    if (values.length <= 1) {
        return
    }

    for (let i = 0; i < values.length - 1; i++) {
        let isSorted = true

        for (let j = 0; j < values.length - i - 1; j++) {
            if (values[j] > values[j + 1]) {
                const temp = values[j]
                values[j] = values[j + 1]
                values[j + 1] = temp

                isSorted = false
            }
        }

        if (isSorted) {
            break
        }
    }
}
