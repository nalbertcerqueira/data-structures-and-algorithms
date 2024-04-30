import { IDoubleNode } from "./types"
import { EmptyLinkedListError, NotFoundError, InvalidFieldError } from "./utils"

export class DoubleNode<Type> implements IDoubleNode<Type> {
    public readonly id: number
    public value: Type
    public prev: IDoubleNode<Type> | null
    public next: IDoubleNode<Type> | null

    constructor({ id, value, next, prev }: IDoubleNode<Type>) {
        this.id = id
        this.value = value
        this.prev = prev
        this.next = next
    }
}

export class DoubleLinkedList<Type> {
    private nextId: number
    private head: IDoubleNode<Type> | null
    private tail: IDoubleNode<Type> | null

    constructor() {
        this.nextId = 0
        this.head = null
        this.tail = null
    }

    public addFirst(value: Type): number {
        this.nextId += 1
        const node = new DoubleNode({ id: this.nextId, value, prev: null, next: null })

        if (this.head === null) {
            this.head = node
            this.tail = node
        } else {
            this.head.prev = node
            node.next = this.head
            this.head = node
        }

        return node.id
    }

    public addLast(value: Type): number {
        this.nextId += 1
        const node = new DoubleNode({ id: this.nextId, value, next: null, prev: null })

        if (this.head === null) {
            this.head = node
            this.tail = node
        } else {
            if (this.tail) {
                this.tail.next = node
            }
            node.prev = this.tail
            this.tail = node
        }

        return node.id
    }

    public addAfter(targetId: number, value: Type): number {
        const foundNode = this.search(targetId)
        const nextNode = foundNode.next
        this.nextId += 1
        const node = new DoubleNode({ id: this.nextId, value, prev: null, next: null })

        node.prev = foundNode
        node.next = foundNode.next
        foundNode.next = node

        if (nextNode) {
            nextNode.prev = node
        } else {
            this.tail = node
        }

        return node.id
    }

    public addBefore(targetId: number, value: Type): number {
        const foundNode = this.search(targetId)
        const previousNode = foundNode.prev
        this.nextId += 1
        const node = new DoubleNode({ id: this.nextId, value, prev: null, next: null })

        node.next = foundNode
        foundNode.prev = node

        if (previousNode) {
            previousNode.next = node
            node.prev = previousNode
        } else {
            this.head = node
        }

        return node.id
    }

    public remove(targetId: number): Type {
        const foundNode = this.search(targetId)

        const previousNode = foundNode.prev
        const nextNode = foundNode.next

        if (previousNode) {
            previousNode.next = foundNode.next

            if (nextNode) nextNode.prev = previousNode
            else this.tail = previousNode
        } else {
            this.head = foundNode.next

            if (!nextNode) this.tail = null
            if (this.head) this.head.prev = null
        }

        return foundNode.value
    }

    public update(targetId: number, value: Type): Pick<IDoubleNode<Type>, "id" | "value"> {
        const foundNode = this.search(targetId)
        foundNode.value = value
        return { id: foundNode.id, value: foundNode.value }
    }

    public isEmpty(): boolean {
        return this.head === null || this.tail === null
    }

    public find(targetId: number): Pick<IDoubleNode<Type>, "id" | "value"> {
        const foundNode = this.search(targetId)
        return { id: foundNode.id, value: foundNode.value }
    }

    public print(): void {
        let current = this.head

        console.log(`-> head: [id: ${current?.id || null}, value: ${current?.value || null}]`)
        while (current !== null) {
            console.log(
                `[ id: ${current.id},`,
                `value: ${current.value},`,
                `prev: ${current.prev?.value || null},`,
                `next: ${current.next?.value || null}]`
            )
            current = current.next
        }
        console.log(
            `<- tail: [id: ${this.tail?.id || null}, value: ${this.tail?.value || null}]\n`
        )
    }

    private search(targetId: number): IDoubleNode<Type> {
        if (typeof targetId !== "number") {
            throw new InvalidFieldError("TargetId")
        } else if (this.head === null || this.tail === null) {
            throw new EmptyLinkedListError()
        }

        let frontNode = this.head
        let backNode = this.tail

        while (frontNode.id !== targetId && backNode.id !== targetId) {
            if (frontNode === backNode) {
                throw new NotFoundError()
            }
            frontNode = frontNode.next as DoubleNode<Type>
            backNode = backNode.prev as DoubleNode<Type>
        }

        const foundNode = frontNode?.id === targetId ? frontNode : backNode
        return foundNode
    }
}
