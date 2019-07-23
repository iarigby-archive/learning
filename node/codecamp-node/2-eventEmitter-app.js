const EventEmitter = require('events')
const eventEmitter = new EventEmitter()

eventEmitter.on('tutorial', (num1, num2) => console.log(num1 + num2))

eventEmitter.emit('tutorial', 1, 2)

class Person extends EventEmitter {
    constructor(name) {
        super()
        this._name = name;
    }

    get name() {
        return this._name
    }
}

let pedro = new Person('Pedro')
let christina = new Person('Christima')
christina.on('name', () => console.log('my name is ' + christina._name))
pedro.on('name', () => console.log('my name is ' + pedro._name))

pedro.emit('name')
christina.emit('name')