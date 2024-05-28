export function selectionSort(values: number[]): void {
    if (values.length <= 1) {
        return
    }

    for (let i = 0; i < values.length - 1; i++) {
        let selectedIndex = i

        for (let j = i + 1; j < values.length; j++) {
            if (values[j] < values[selectedIndex]) {
                selectedIndex = j
            }
        }

        const temp = values[i]
        values[i] = values[selectedIndex]
        values[selectedIndex] = temp
    }
}
