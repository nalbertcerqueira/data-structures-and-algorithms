export class EmptyQueueError extends Error {
    constructor() {
        super()
        this.message = "The queue is empty!"
        this.name = "EmptyQueueError"
    }
}

export class FullQueueError extends Error {
    constructor() {
        super()
        this.message = "The queue is full!"
        this.name = "FullQueueError"
    }
}
