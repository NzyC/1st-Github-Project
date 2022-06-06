let firstCard = Math.floor((Math.random() * 11) + 1)
let secondCard = Math.floor((Math.random() * 11) + 1)
let cards = [firstCard, secondCard]
let hasBlackjack = false
let isAlive = true

let message = ""

let sum = firstCard + secondCard

let messageEl = document.getElementById("message-el")
let sumEl = document.getElementById("sum-el")
let cardsEl = document.getElementById("cards-el")

function startGame() {
    renderGame()
}

function renderGame() {
    sumEl.textContent = "Sum: " + sum
    cardsEl.textContent = "Cards: " + cards[0] + " " + cards[1]
    if (sum <= 20) {
        console.log(sum)
        message = "Do you want to draw a new card?"
    } else if (sum === 21) {
        console.log(sum)
        message = "BLACKJACK!"
        hasBlackjack = true
    } else {
        console.log(sum)
        message = "You're out of the game!"
        isAlive = false
    }
    
    messageEl.textContent = message

    console.log(message)
}

function newCard() {
    console.log("Drawing a new card from the deck!")
    let card = Math.floor((Math.random() * 11) + 1)
    sum += card
    cards.push (card)
    console.log(cards)
    renderGame()
}