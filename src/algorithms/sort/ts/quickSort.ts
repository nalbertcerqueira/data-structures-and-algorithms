export function quickSort1(values: number[]): void {
    if (values.length <= 1) {
        return
    }
    partition1(values, 0, values.length - 1)
}

export function quickSort2(values: number[]): void {
    if (values.length <= 1) {
        return
    }
    partition2(values, 0, values.length - 1)
}

function partition1<T>(values: T[], start: number, end: number): void {
    if (end <= start) {
        return
    }

    const pivotIndex = end
    let i = start

    for (let j = start; j < end; j++) {
        if (values[j] < values[pivotIndex]) {
            swap(values, i, j)
            i++
        }
    }
    swap(values, i, pivotIndex)
    partition1(values, start, i - 1)
    partition1(values, i + 1, end)
}

function partition2<T>(values: T[], start: number, end: number): void {
    if (end <= start) {
        return
    }

    const ref = values[start]
    let left = start + 1
    let right = end

    while (left <= right) {
        if (values[left] > ref && values[right] < ref) {
            swap(values, left, right)
        }

        if (values[left] <= ref) {
            left += 1
        }

        if (values[right] >= ref) {
            right -= 1
        }
    }

    const pivotIndex = right
    swap(values, pivotIndex, start)

    partition2(values, start, pivotIndex - 1)
    partition2(values, pivotIndex + 1, end)
}

function swap<T>(values: T[], i: number, j: number): void {
    if (i !== j) {
        const temp = values[j]
        values[j] = values[i]
        values[i] = temp
    }
}
