export interface StackProps<Type> {
    values: Type[]
    size: number
}

export interface INode<Type> {
    value: Type
    next: INode<Type> | null
}
