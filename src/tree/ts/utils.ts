export class RepeatedNodeError extends Error {
    constructor(id: number) {
        super()
        this.message = `Node with id '${id}' already exists`
        this.name = "RepeatedNodeError"
    }
}

export class EmptyTreeError extends Error {
    constructor() {
        super()
        this.message = "Tree is empty"
        this.name = "EmptyTreeError"
    }
}

export class NotFoundError extends Error {
    constructor(id: number) {
        super()
        this.message = `Node with id '${id}' not found`
        this.name = "NotFoundError"
    }
}
