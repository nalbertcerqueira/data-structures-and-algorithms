export type TraverseStrategy = "preOrder" | "inOrder" | "postOrder" | "level"

export interface INode<Type> {
    id: number
    data: Type
    left: INode<Type> | null
    right: INode<Type> | null
}

export interface INodeAVL<Type> extends INode<Type> {
    height: number
    left: INodeAVL<Type> | null
    right: INodeAVL<Type> | null
}

export interface BinaryTree<Type> {
    print(): void
    isEmpty(): boolean
    delete(id: number): void
    insert(id: number, data: Type): void
    traverse(strategy: TraverseStrategy): void
    find(id: number): Pick<INode<Type>, "id" | "data">
    update(id: number, data: Type): Pick<INode<Type>, "id" | "data">
    min(): Pick<INode<Type>, "id" | "data">
    max(): Pick<INode<Type>, "id" | "data">
}
