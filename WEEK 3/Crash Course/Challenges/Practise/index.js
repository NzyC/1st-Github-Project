// const player = "Nidal"
// const opponent = "Per"
// const game = "AmazingFighter"
// let points = 0
// let hasWon = false

// points += 100
// hasWon = true

// if (hasWon) {
//     console.log(`${player} got ${points} points and won the ${game} game!`)
// } else {
//     console.log("The winner is " + opponent + "!" + player + " lost the game")
// }

// let myCourses = ["Learn CSS Animations", "UI Design Fundamentals", "Intro to Clean Code"]

// function logCourses(arr) {
//     for (let i = 0; i < arr.length; i++ ) {
//         console.log(arr[i])
//     }
// }

// logCourses(myCourses)

let item = ["lol"]

localStorage.setItem("items", JSON.stringify(item))

let itemsFromLocalStorage = JSON.parse(localStorage.getItem("items"))

console.log(itemsFromLocalStorage)
