export interface INode<Type> {
    readonly id: number
    value: Type
    next: INode<Type> | null
}
