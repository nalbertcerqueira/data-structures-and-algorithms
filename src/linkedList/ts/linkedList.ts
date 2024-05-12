import { INode } from "./types"
import { EmptyLinkedListError, InvalidFieldError, NotFoundError } from "./utils"

export class Node<Type> implements INode<Type> {
    constructor(
        public readonly id: number,
        public value: Type,
        public next: INode<Type> | null
    ) {}
}

export class LinkedList<Type> {
    private nextId: number = 0
    private head: INode<Type> | null

    constructor() {
        this.head = null
    }

    public addFirst(value: Type): number {
        this.nextId += 1
        const node = new Node(this.nextId, value, null)

        if (this.head !== null) {
            this.head = node
        } else {
            node.next = this.head
            this.head = node
        }

        return node.id
    }

    public addLast(value: Type): number {
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

    public addAfter(value: Type, targetId: number): number {
        if (typeof targetId !== "number") {
            throw new InvalidFieldError("TargetId")
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

        const node = new Node<Type>(this.nextId, value, current.next)
        current.next = node

        return node.id
    }

    public addBefore(value: Type, targetId: number): number {
        if (typeof targetId !== "number") {
            throw new InvalidFieldError("TargetId")
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

        const node = new Node<Type>(this.nextId, value, current)
        previous ? (previous.next = node) : (this.head = node)

        return node.id
    }

    public remove(targetId: number): Type {
        if (typeof targetId !== "number") {
            throw new InvalidFieldError("TargetId")
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

        return current.value
    }

    public update(targetId: number, value: Type): Pick<INode<Type>, "id" | "value"> {
        const foundNode = this.search(targetId)
        foundNode.value = value
        return { id: foundNode.id, value: foundNode.value }
    }

    public reverse(): void {
        let current = this.head
        let previous = null

        while (current) {
            const next = current.next
            current.next = previous

            previous = current
            current = next
        }

        this.head = previous
    }

    public isEmpty(): boolean {
        return this.head === null
    }

    public find(targetId: number): Pick<INode<Type>, "id" | "value"> {
        const foundNode = this.search(targetId)
        return { id: foundNode.id, value: foundNode.value }
    }

    public print(): void {
        console.log(JSON.stringify(this.head, null, 2))
    }

    private search(targetId: number): INode<Type> {
        if (typeof targetId !== "number") {
            throw new InvalidFieldError("TargetId")
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

        return current
    }
}
