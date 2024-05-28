export function quickSort(values: number[]): void {
    if (values.length <= 1) {
        return
    }
    partition(values, 0, values.length - 1)
}

function partition<T>(values: T[], begin: number, end: number): void {
    if (end <= begin) {
        return
    }

    const pivotIndex = end
    let i = begin

    for (let j = begin; j < end; j++) {
        if (values[j] < values[pivotIndex]) {
            swap(values, i, j)
            i++
        }
    }
    swap(values, i, pivotIndex)
    partition(values, begin, i - 1)
    partition(values, i + 1, end)
}

function swap<T>(values: T[], i: number, j: number): void {
    if (i !== j) {
        const temp = values[j]
        values[j] = values[i]
        values[i] = temp
    }
}
