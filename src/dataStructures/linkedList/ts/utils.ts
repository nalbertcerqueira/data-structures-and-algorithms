export class InvalidFieldError extends Error {
    constructor(name: string) {
        super()
        this.message = `${name} must be a number`
        this.name = "InvalidFieldError"
    }
}

export class EmptyLinkedListError extends Error {
    constructor() {
        super()
        this.message = "Linked list is empty"
        this.name = "EmptyLinkedListError"
    }
}

export class NotFoundError extends Error {
    constructor() {
        super()
        this.message = "Node not found"
        this.name = "NotFoundError"
    }
}
