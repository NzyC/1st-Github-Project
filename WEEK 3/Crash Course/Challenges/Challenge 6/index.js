// let person = {
//     name: "Nidal",
//     age: 17,
//     country: "Australia"
// }

// function logData() {    
//     console.log(person.name + " is " + person.age + " years old and lives in " + person.country)
// }

// // logData()

// let age = 12

//     if (age < 6) {
//         console.log("free")
//     } else if (age < 18 ) {
//         console.log("child discount")
//     } else if (age < 27 ) {
// //         console.log("student discount")
// //     } else if (age < 67) {
// //         console.log("full price")
// //     } else {
// //         console.log("senior citizen discount")
// //     }

// let largeCountries = ["Tuvalu", "India", "USA", "Indonesia", "Monaco"]

// // console.log("The 5 largest countries in the world:")
// // for ( let i = 0; i < largeCountries.length; i++) {
// //     console.log("- " + largeCountries[i])
// // }

// largeCountries.pop()
// largeCountries.push("Pakistan")

// largeCountries.shift()
// largeCountries.unshift("China")

// console.log(largeCountries)

// let dayOfMonth = 13
// let weekday = "Friday"

// if (dayOfMonth === 13 && weekday === "Friday") {
//     console.log("😱")
// } else {
// }

// let hands = ["rock", "paper", "scissors"]
// function getHand() {
//     let randomIndex = Math.floor( Math.random() * 3 )
//     return hands [randomIndex]
// }

// console.log(getHand())

let fruit = [ "🍎",  "🍊", "🍎", "🍎", "🍊"]
let appleShelf = document.getElementById("apple-shelf")
let orangeShelf = document.getElementById("orange-shelf")

function sortFruit() {
    for (let i = 0; i < fruit.length; i++) {
        if (fruit[i] === "🍎") {
            appleShelf.textContent += "🍎"
        } else {
            orangeShelf.textContent += "🍊"
        }
    }
}

sortFruit()