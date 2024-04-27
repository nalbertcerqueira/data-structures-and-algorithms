export class EmptyStackError extends Error {
    constructor() {
        super()
        this.message = "The stack is empty!"
        this.name = "EmptyStackError"
    }
}

export class FullStackError extends Error {
    constructor() {
        super()
        this.message = "The stack is full!"
        this.name = "FullStackError"
    }
}
