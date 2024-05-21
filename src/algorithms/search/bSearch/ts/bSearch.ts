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

export function recursiveBSearch(values: number[], target: number) {
    return main(0, values.length - 1, values)

    function main(lIndex: number, rIndex: number, values: number[]) {
        const middleIndex = Math.floor((lIndex + rIndex) / 2)
        const pivot = values[middleIndex]

        if (lIndex > rIndex) {
            return -1
        }

        if (target > pivot) {
            return main(middleIndex + 1, rIndex, values)
        } else if (target < pivot) {
            return main(lIndex, middleIndex - 1, values)
        }

        return middleIndex
    }
}
