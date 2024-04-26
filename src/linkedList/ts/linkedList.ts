import { INode } from "./types"
import { EmptyLinkedListError, IvalidFieldError, NotFoundError } from "./utils"

export class Node implements INode {
    constructor(
        public id: number,
        public value: number,
        public next: INode | null
    ) {}
}

export class LinkedList {
    private nextId: number = 0
    private head: INode | null

    constructor() {
        this.head = null
    }

    public addFirst(value: number): number {
        if (typeof value !== "number") {
            throw new IvalidFieldError("Value")
        }

        this.nextId += 1
        const node = new Node(this.nextId, value, null)

        if (this.head === null) {
            this.head = node
        } else {
            node.next = this.head
            this.head = node
        }

        return node.id
    }

    public addLast(value: number): number {
        if (typeof value !== "number") {
            throw new IvalidFieldError("Value")
        }

        this.nextId += 1
        const node = new Node(this.nextId, value, null)

        if (this.head === null) {
            this.head = node
        } else {
            let current = this.head
            while (current?.next !== null) {
                current = current?.next
            }
            current.next = node
        }

        return node.id
    }

    public addAfter(value: number, targetId: number): number {
        if (typeof value !== "number") {
            throw new IvalidFieldError("Value")
        } else if (typeof targetId !== "number") {
            throw new IvalidFieldError("TargetId")
        } else if (this.head === null) {
            throw new EmptyLinkedListError()
        }

        this.nextId += 1
        let current = this.head

        while (current.id !== targetId) {
            if (current.next === null) {
                throw new NotFoundError()
            }
            current = current.next
        }

        const node = new Node(this.nextId, value, current.next)
        current.next = node

        return node.id
    }

    public addBefore(value: number, targetId: number): number {
        if (typeof value !== "number") {
            throw new IvalidFieldError("Value")
        } else if (typeof targetId !== "number") {
            throw new IvalidFieldError("TargetId")
        } else if (this.head === null) {
            throw new EmptyLinkedListError()
        }

        this.nextId += 1
        let previous = null
        let current = this.head

        while (current.id !== targetId) {
            if (current.next === null) {
                throw new NotFoundError()
            }
            previous = current
            current = current.next
        }

        const node = new Node(this.nextId, value, current)
        previous ? (previous.next = node) : (this.head = node)

        return node.id
    }

    public remove(targetId: number): void {
        if (typeof targetId !== "number") {
            throw new IvalidFieldError("TargetId")
        } else if (this.head === null) {
            throw new EmptyLinkedListError()
        }

        let previous = null
        let current = this.head

        while (current.id !== targetId) {
            if (current.next === null) {
                throw new NotFoundError()
            }
            previous = current
            current = current.next
        }

        if (previous) {
            previous.next = current.next
        } else {
            this.head = current.next
        }
    }

    public update(targetId: number, value: number): void {
        if (this.head === null) {
            throw new EmptyLinkedListError()
        }

        let current = this.head

        while (current.id !== targetId) {
            if (current.next === null) {
                throw new NotFoundError()
            }
            current = current.next
        }

        current.value = value
    }

    public isEmpty(): boolean {
        return this.head === null
    }

    public find(targetId: number): Pick<Node, "id" | "value"> {
        if (typeof targetId !== "number") {
            throw new IvalidFieldError("TargetId")
        } else if (this.head === null) {
            throw new EmptyLinkedListError()
        }

        let current = this.head
        while (current.id !== targetId) {
            if (current.next === null) {
                throw new NotFoundError()
            }
            current = current.next
        }

        return { id: current.id, value: current.value }
    }

    public print(): void {
        console.log(JSON.stringify(this.head, null, 2))
    }
}
