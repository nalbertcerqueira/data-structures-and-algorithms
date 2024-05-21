export function bSearch(values: number[], target: number): number {
    let leftINdex = 0
    let rightIndex = values.length - 1

    while (leftINdex <= rightIndex) {
        const middleIndex = Math.trunc((rightIndex + leftINdex) / 2)
        const pivot = values[middleIndex]

        if (pivot === target) {
            return middleIndex
        }

        if (target > pivot) {
            leftINdex = middleIndex + 1
        } else {
            rightIndex = middleIndex - 1
        }
    }

    return -1
}
