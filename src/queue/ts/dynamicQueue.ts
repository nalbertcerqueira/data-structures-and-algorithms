import { INode } from "./types"
import { EmptyQueueError } from "./utils"

class Node<Type> implements INode<Type> {
    constructor(
        public value: Type,
        public next: INode<Type> | null
    ) {}
}

export class DynamicQueue<Type> {
    private head: INode<Type> | null

    constructor() {
        this.head = null
    }

    public enqueue(value: Type): void {
        const node = new Node(value, null)

        if (this.head === null) {
            this.head = node
        } else {
            let current = this.head
            while (current.next !== null) {
                current = current.next
            }
            current.next = node
        }
    }

    public dequeue(): Type {
        if (this.head === null) {
            throw new EmptyQueueError()
        }

        const value = this.head.value
        this.head = this.head.next
        return value
    }

    public peek(): Type {
        if (this.head === null) {
            throw new EmptyQueueError()
        }
        return this.head?.value
    }

    public print(): void {
        if (this.isEmpty()) {
            throw new EmptyQueueError()
        }

        let current = this.head
        let output = ""

        while (current !== null) {
            output += `(${current.value})-`
            current = current.next
        }

        console.log(output.slice(0, -1))
    }

    public isEmpty(): boolean {
        return this.head === null
    }
}
