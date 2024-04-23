import { StackProps } from "./types"

export class Stack {
    private props: StackProps

    constructor(stackSize: number) {
        if (typeof stackSize !== "number") {
            throw new Error("The size of the stack must be a number")
        } else if (stackSize <= 0) {
            throw new Error("The size of the stack must be greater than 0")
        }

        this.props = {
            stackSize,
            values: [],
            stackPointer: -1
        }
    }

    public push(value: number): void {
        if (typeof value !== "number") {
            throw new Error("Value must be a number")
        } else if (this.props.stackPointer === this.props.stackSize - 1) {
            throw new Error("Stack is full")
        }

        this.props.stackPointer++
        this.props.values[this.props.stackPointer] = value
    }

    public pop(): number {
        if (this.props.stackPointer === -1) {
            throw new Error("Stack is empty")
        }

        const poppedValue = this.props.values[this.props.stackPointer]
        this.props.values.length -= 1
        this.props.stackPointer -= 1

        return poppedValue
    }

    public peek(): number {
        return this.props.values[this.props.stackPointer]
    }

    public isEmpty(): boolean {
        return this.props.stackPointer === -1
    }

    public isFull(): boolean {
        return this.props.stackPointer === this.props.stackSize - 1
    }

    public print(): void {
        if (this.isEmpty()) {
            throw new Error("Stack is empty")
        }

        let output = ""
        for (let i = this.props.values.length - 1; i >= 0; i--) {
            output += `[ ${this.props.values[i]} ]\n`
        }

        console.log(output)
    }
}
