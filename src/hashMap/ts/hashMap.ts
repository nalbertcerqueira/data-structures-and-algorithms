export class HashMap<Type extends Record<string, any>> {
    private values: Array<Array<[keyof Type, Type[keyof Type]]> | undefined>
    private size: number

    constructor(size: number) {
        this.size = size
        this.values = new Array(size)
    }

    private hash(key: keyof Type): number {
        const keyAsString = new String(key)
        let charSum = 0

        if (typeof key === "number" && key >= 0) {
            return key % this.size
        }

        //Multiplicar por 2^i cria um peso para cada posição. Isso
        //resulta em uma soma diferente se a ordem dos caracteres for alterada
        for (let i = 0; i < keyAsString.length; i++) {
            charSum += keyAsString.charCodeAt(i) * Math.pow(2, i)
        }

        return charSum % this.size
    }

    public set<K extends keyof Type>(key: K, value: Type[K]): void {
        const index = this.hash(key)
        const bucket = this.values[index]

        if (!bucket) {
            this.values[index] = [[key, value]]
        } else {
            const foundPair = bucket.find((pair) => pair[0] === key)
            if (foundPair) {
                foundPair[1] = value
            } else {
                bucket.push([key, value])
            }
        }
    }

    public remove<K extends keyof Type>(key: K): void {
        const index = this.hash(key)
        const bucket = this.values[index]

        if (bucket) {
            const pairIndex = bucket.findIndex((pair) => pair[0] === key)
            if (pairIndex >= 0 && bucket.length === 1) {
                this.values[index] = undefined
            } else if (pairIndex >= 0) {
                bucket.splice(pairIndex, 1)
            }
        }
    }

    public get<K extends keyof Type>(key: K): Type[K] | undefined {
        const index = this.hash(key)
        const bucket = this.values[index]

        if (bucket) {
            const foundPair = bucket.find((pair) => pair[0] === key)
            return foundPair ? foundPair[1] : undefined
        }

        return undefined
    }

    public print(): void {
        console.log("{")
        for (const index in this.values) {
            const bucket = this.values[index]
            if (bucket) {
                bucket.forEach((pair) => {
                    const key = new String(pair[0])
                    const value = typeof pair[1] === "string" ? `'${pair[1]}'` : pair[1]
                    console.log(`  ${key}:`, value)
                })
            }
        }
        console.log("}")
    }
}
