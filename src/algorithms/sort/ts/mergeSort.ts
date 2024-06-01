export function mergeSort(values: number[]): void {
    partition(values, 0, values.length - 1)
}

function partition(values: number[], start: number, end: number): void {
    if (end <= start) {
        return
    }

    const middle = Math.floor((start + end) / 2)
    partition(values, start, middle)
    partition(values, middle + 1, end)
    merge(values, start, middle, end)
}

function merge(values: number[], start: number, middle: number, end: number): void {
    const leftArray = []
    const rightArray = []

    for (let i = 0; i < middle - start + 1; i++) {
        leftArray[i] = values[i + start]
    }

    for (let j = 0; j < end - middle; j++) {
        rightArray[j] = values[j + middle + 1]
    }

    let i = 0
    let j = 0
    let currIndex = start

    while (i < leftArray.length || j < rightArray.length) {
        if (leftArray[i] !== undefined && rightArray[j] !== undefined) {
            if (leftArray[i] < rightArray[j]) {
                values[currIndex] = leftArray[i]
                i += 1
            } else {
                values[currIndex] = rightArray[j]
                j += 1
            }
        } else {
            if (leftArray[i] !== undefined) {
                values[currIndex] = leftArray[i]
                i += 1
            }
            if (rightArray[j] !== undefined) {
                values[currIndex] = rightArray[j]
                j += 1
            }
        }
        currIndex += 1
    }
}
