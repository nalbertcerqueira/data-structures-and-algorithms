export interface CircularQueueProps<Type> {
    end: number
    begin: number
    size: number
    items: Type[]
    itemCount: number
}

export interface INode<Type> {
    value: Type
    next: INode<Type> | null
}
