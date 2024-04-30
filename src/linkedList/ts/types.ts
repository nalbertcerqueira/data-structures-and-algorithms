export interface INode<Type> {
    readonly id: number
    value: Type
    next: INode<Type> | null
}

export interface IDoubleNode<Type> {
    readonly id: number
    value: Type
    prev: IDoubleNode<Type> | null
    next: IDoubleNode<Type> | null
}
