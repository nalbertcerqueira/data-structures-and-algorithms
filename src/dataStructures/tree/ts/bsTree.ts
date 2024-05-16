import { BinaryTree, INode, TraverseStrategy } from "./types"
import { EmptyTreeError, NotFoundError, RepeatedNodeError } from "./utils"

export class Node<Type> implements INode<Type> {
    public id: number
    public data: Type
    public left: INode<Type> | null
    public right: INode<Type> | null

    constructor(id: number, data: Type) {
        this.id = id
        this.data = data
        this.left = null
        this.right = null
    }
}

export class BinarySearchTree<Type> implements BinaryTree<Type> {
    protected root: INode<Type> | null

    constructor() {
        this.root = null
    }

    public insert(id: number, data: Type): void {
        const newNode = new Node(id, data)

        if (this.root === null) {
            this.root = newNode
            return
        }

        const leaf = this.search(id, this.root)

        if (id > leaf.id) {
            leaf.right = newNode
        } else if (id < leaf.id) {
            leaf.left = newNode
        } else {
            throw new RepeatedNodeError(id)
        }
    }

    public find(id: number): Pick<INode<Type>, "id" | "data"> {
        if (this.root === null) {
            throw new EmptyTreeError()
        }

        const foundNode = this.search(id, this.root)

        if (foundNode.id !== id) {
            throw new NotFoundError(id)
        }

        return { id: foundNode.id, data: foundNode.data }
    }

    public delete(id: number): void {
        if (this.root === null) {
            throw new EmptyTreeError()
        }

        this.root = this.deleteNode(this.root, id)
    }

    public update(id: number, data: Type): Pick<INode<Type>, "id" | "data"> {
        if (this.root === null) {
            throw new EmptyTreeError()
        }

        const foundNode = this.search(id, this.root)

        if (id !== foundNode.id) {
            throw new NotFoundError(id)
        }

        foundNode.data = data
        return { id, data }
    }

    public traverse(strategy: TraverseStrategy): void {
        if (this.root === null) {
            throw new EmptyTreeError()
        }

        if (strategy === "level") {
            this.levelTraversal(this.root)
        } else {
            this.depthTraversal(this.root, strategy)
        }
    }

    public min(): Pick<INode<Type>, "id" | "data"> {
        if (this.root === null) {
            throw new EmptyTreeError()
        }

        let current = this.root

        while (current.left !== null) {
            current = current.left
        }

        return { id: current.id, data: current.data }
    }

    public max(): Pick<INode<Type>, "id" | "data"> {
        if (this.root === null) {
            throw new EmptyTreeError()
        }

        let current = this.root

        while (current.right !== null) {
            current = current.right
        }

        return { id: current.id, data: current.data }
    }

    public print(): void {
        console.log(JSON.stringify(this.root, null, 2))
    }

    public isEmpty(): boolean {
        return this.root === null
    }

    private search(id: number, root: INode<Type>): INode<Type> {
        if (id > root.id) {
            return root.right === null ? root : this.search(id, root.right)
        } else if (id < root.id) {
            return root.left === null ? root : this.search(id, root.left)
        } else {
            return root
        }
    }

    private depthTraversal(root: INode<Type>, strategy: TraverseStrategy): void {
        if (strategy === "preOrder") {
            console.log(JSON.stringify({ id: root.id, data: root.data }))
        }
        root.left && this.depthTraversal(root.left, strategy)
        if (strategy === "inOrder") {
            console.log(JSON.stringify({ id: root.id, data: root.data }))
        }
        root.right && this.depthTraversal(root.right, strategy)
        if (strategy === "postOrder") {
            console.log(JSON.stringify({ id: root.id, data: root.data }))
        }
    }

    private levelTraversal(root: INode<Type>): void {
        const queue: INode<Type>[] = [root]
        let currentNode = root
        let pointer = 0

        while (pointer < queue.length) {
            console.log({ id: queue[pointer].id, data: queue[pointer].data })

            currentNode.left && queue.push(currentNode.left)
            currentNode.right && queue.push(currentNode.right)

            pointer += 1
            currentNode = queue[pointer]
        }
    }

    private deleteNode(root: INode<Type> | null, id: number): INode<Type> | null {
        if (root === null) {
            throw new NotFoundError(id)
        }

        if (id < root.id) {
            root.left = this.deleteNode(root.left, id)
        } else if (id > root.id) {
            root.right = this.deleteNode(root.right, id)
        } else {
            if (!root.left && !root.right) {
                return null
            } else if (!(root.right && root.left)) {
                return root.right || root.left
            } else {
                const { data, id } = this.max.call({ root: root.left })
                root.left = this.deleteNode(root.left, id)
                root.id = id
                root.data = data
            }
        }

        return root
    }
}
