import { StackProps } from "./types"
import { EmptyStackError, FullStackError } from "./utils"

export class Stack<Type> {
    private props: StackProps<Type>

    constructor(stackSize: number) {
        if (typeof stackSize !== "number") {
            throw new Error("The size of the stack must be a number")
        } else if (stackSize <= 0) {
            throw new Error("The size of the stack must be greater than 0")
        }

        this.props = {
            size: stackSize,
            values: []
        }
    }

    public push(value: Type): void {
        if (this.isFull()) {
            throw new FullStackError()
        }

        const stackPointer = this.props.values.length
        this.props.values[stackPointer] = value
    }

    public pop(): Type {
        if (this.isEmpty()) {
            throw new EmptyStackError()
        }

        const stackPointer = this.props.values.length - 1
        const poppedValue = this.props.values[stackPointer]
        this.props.values.length -= 1

        return poppedValue
    }

    public peek(): Type {
        if (this.isEmpty()) {
            throw new EmptyStackError()
        }
        return this.props.values[this.props.values.length - 1]
    }

    public isEmpty(): boolean {
        return this.props.values.length === 0
    }

    public isFull(): boolean {
        return this.props.values.length === this.props.size
    }

    public print(): void {
        if (this.isEmpty()) {
            throw new EmptyStackError()
        }

        let output = ""
        for (let i = this.props.values.length - 1; i >= 0; i--) {
            output += `[ ${JSON.stringify(this.props.values[i])} ]\n`
        }

        console.log(output)
    }
}
