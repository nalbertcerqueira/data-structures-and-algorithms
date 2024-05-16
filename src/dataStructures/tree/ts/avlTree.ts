import { INodeAVL } from "./types"
import { BinarySearchTree } from "./bsTree"
import { EmptyTreeError, NotFoundError, RepeatedNodeError } from "./utils"

export class AVLNode<Type> implements INodeAVL<Type> {
    public id: number
    public height: number
    public data: Type
    public left: INodeAVL<Type> | null
    public right: INodeAVL<Type> | null

    constructor(id: number, data: Type) {
        this.id = id
        this.height = 0
        this.data = data
        this.left = null
        this.right = null
    }
}

export class AVLTree<Type> extends BinarySearchTree<Type> {
    protected root: INodeAVL<Type> | null

    constructor() {
        super()
        this.root = null
    }

    public insert(id: number, data: Type): void {
        this.root = this.insertAndBalance(id, data, this.root)
    }

    public delete(id: number): void {
        if (this.root === null) {
            throw new EmptyTreeError()
        }

        this.root = this.deleteAndBalance(id, this.root)
    }

    private insertAndBalance(
        id: number,
        data: Type,
        root: INodeAVL<Type> | null
    ): INodeAVL<Type> {
        if (root === null) {
            return new AVLNode(id, data)
        }

        if (id > root.id) {
            root.right = this.insertAndBalance(id, data, root.right)
        } else if (id < root.id) {
            root.left = this.insertAndBalance(id, data, root.left)
        } else {
            throw new RepeatedNodeError(id)
        }

        root.height = this.getNodeHeight(root)
        return this.rebalanceNode(root)
    }

    private deleteAndBalance(id: number, root: INodeAVL<Type> | null): INodeAVL<Type> | null {
        if (root === null) {
            throw new NotFoundError(id)
        }

        if (id < root.id) {
            root.left = this.deleteAndBalance(id, root.left)
        } else if (id > root.id) {
            root.right = this.deleteAndBalance(id, root.right)
        } else {
            if (!root.left && !root.right) {
                return null
            } else if (!(root.right && root.left)) {
                return root.right || root.left
            } else {
                const { data, id } = this.max.call({ root: root.left })
                root.left = this.deleteAndBalance(id, root.left)
                root.id = id
                root.data = data
            }
        }

        root.height = this.getNodeHeight(root)
        return this.rebalanceNode(root)
    }

    private rebalanceNode(node: INodeAVL<Type>): INodeAVL<Type> {
        const nodeBalanceFactor = this.getBalanceFactor(node)

        if (nodeBalanceFactor > 1) {
            const leftBalanceFactor = this.getBalanceFactor(node.left)
            return leftBalanceFactor < 0 ? this.rotateLR(node) : this.rotateRR(node)
        } else if (nodeBalanceFactor < -1) {
            const rightBalanceFactor = this.getBalanceFactor(node.right)
            return rightBalanceFactor > 0 ? this.rotateRL(node) : this.rotateLL(node)
        }

        return node
    }

    private getBalanceFactor(node: INodeAVL<Type> | null): number {
        if (!node) {
            return 0
        }

        const leftTreeHeight = node.left?.height ?? -1
        const rightTreeHeight = node.right?.height ?? -1

        return leftTreeHeight - rightTreeHeight
    }

    private getNodeHeight(node: INodeAVL<Type> | null): number {
        if (!node) {
            return -1
        }

        const leftHeight = node.left?.height ?? -1
        const rightHeight = node.right?.height ?? -1

        return Math.max(leftHeight, rightHeight) + 1
    }

    private rotateLL(node: INodeAVL<Type>): INodeAVL<Type> {
        const right = node.right

        if (right) {
            node.right = node.right ? node.right.left : null
            right.left = node
            right.left.height = this.getNodeHeight(right.left)
            right.height = this.getNodeHeight(right)
            return right
        }

        return node
    }

    private rotateRR(node: INodeAVL<Type>): INodeAVL<Type> {
        const left = node.left

        if (left) {
            node.left = node.left ? node.left.right : null
            left.right = node
            left.right.height = this.getNodeHeight(left.right)
            left.height = this.getNodeHeight(left)
            return left
        }

        return node
    }

    private rotateRL(node: INodeAVL<Type>): INodeAVL<Type> {
        if (node.right) {
            node.right = this.rotateRR(node.right)
        }

        return this.rotateLL(node)
    }

    private rotateLR(node: INodeAVL<Type>): INodeAVL<Type> {
        if (node.left) {
            node.left = this.rotateLL(node.left)
        }

        return this.rotateRR(node)
    }
}
