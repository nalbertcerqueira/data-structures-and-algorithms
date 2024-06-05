import { INode } from "./types"
import { EmptyStackError } from "./utils"

export class Node<Type> implements INode<Type> {
    constructor(
        public value: Type,
        public next: INode<Type> | null
    ) {}
}

export class DynamicStack<Type> {
    private head: INode<Type> | null

    constructor() {
        this.head = null
    }

    public push(value: Type): void {
        if (this.head === null) {
            this.head = new Node(value, null)
        } else {
            this.head = new Node(value, this.head)
        }
    }

    public pop(): Type {
        if (this.head === null) {
            throw new EmptyStackError()
        }

        const value = this.head.value
        this.head = this.head.next

        return value
    }

    public peek(): Type {
        if (this.head === null) {
            throw new EmptyStackError()
        }
        return this.head.value
    }

    public isEmpty(): boolean {
        return this.head === null
    }

    public print(): void {
        if (this.isEmpty()) {
            throw new EmptyStackError()
        }

        let output = ""
        let current = this.head

        while (current !== null) {
            output += `[ ${current.value} ]\n`
            current = current.next
        }

        console.log(output)
    }
}
