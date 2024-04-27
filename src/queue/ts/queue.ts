import { CircularQueueProps } from "./types"
import { EmptyQueueError, FullQueueError } from "./utils"

export class CircularQueue<Type> {
    private props: CircularQueueProps<Type>

    constructor(size: number) {
        if (typeof size !== "number") {
            throw new Error("Size must be a number")
        } else if (size <= 0) {
            throw new Error("Size must be greater then 0")
        }

        this.props = {
            end: 0,
            begin: 0,
            size,
            items: [],
            itemCount: 0
        }
    }

    public enqueue(value: Type): void {
        if (this.isFull()) {
            throw new FullQueueError()
        }

        this.props.items[this.props.end] = value
        this.props.end = (this.props.end + 1) % this.props.size
        this.props.itemCount += 1
    }

    public dequeue(): Type {
        if (this.isEmpty()) {
            throw new EmptyQueueError()
        }

        const value = this.props.items[this.props.begin]
        this.props.itemCount -= 1
        this.props.begin = (this.props.begin + 1) % this.props.size

        return value
    }

    public peek(): Type {
        if (this.isEmpty()) {
            throw new EmptyQueueError()
        }
        return this.props.items[this.props.begin]
    }

    public print(): void {
        if (this.isEmpty()) {
            throw new EmptyQueueError()
        }

        let output = ""
        for (let i = 0; i < this.props.itemCount; i++) {
            const index = (this.props.begin + i) % this.props.size
            output += `(${JSON.stringify(this.props.items[index])})-`
        }

        console.log(output.slice(0, -1))
    }

    public isEmpty(): boolean {
        return this.props.itemCount === 0
    }

    public isFull(): boolean {
        return this.props.itemCount === this.props.size
    }
}
