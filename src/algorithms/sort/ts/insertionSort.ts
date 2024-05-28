export function insertionSort(values: number[]): void {
    if (values.length <= 1) {
        return
    }

    for (let i = 1; i < values.length; i++) {
        let indexToInsert = i
        const valueToInsert = values[i]

        for (let j = i - 1; j >= 0; j--) {
            if (valueToInsert < values[j]) {
                values[j + 1] = values[j]
                indexToInsert = j
            } else {
                break
            }
        }

        values[indexToInsert] = valueToInsert
    }
}
