let mongoose = require('mongoose')

const server = 'cluster0-fphqr.mongodb.net'
const database = 'rest-api-workshop'
const user = 'ia'
const password = 'iaia1234'

mongoose.set('useCreateIndex', true)
mongoose.connect(`mongodb+srv://${user}:${password}@${server}/${database}`, {useNewUrlParser: true})

let CustomerSchema = new mongoose.Schema({
    name: String,
    email: {
        type: String,
        required: true,
        unique: true
    }
})

module.exports = mongoose.model('Customer', CustomerSchema)
