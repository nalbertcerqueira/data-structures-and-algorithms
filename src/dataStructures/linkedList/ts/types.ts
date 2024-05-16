export interface INode<Type> {
    readonly id: number
    value: Type
    next: INode<Type> | null
}

export interface IDoublyNode<Type> {
    readonly id: number
    value: Type
    prev: IDoublyNode<Type> | null
    next: IDoublyNode<Type> | null
}
