// // const player = "Nidal"
// // const opponent = "Per"
// // const game = "AmazingFighter"
// // let points = 0
// // let hasWon = false

// // points += 100
// // hasWon = true

// // if (hasWon) {
// //     console.log(`${player} got ${points} points and won the ${game} game!`)
// // } else {
// //     console.log("The winner is " + opponent + "!" + player + " lost the game")
// // }

// // let myCourses = ["Learn CSS Animations", "UI Design Fundamentals", "Intro to Clean Code"]

// // function logCourses(arr) {
// //     for (let i = 0; i < arr.length; i++ ) {
// //         console.log(arr[i])
// //     }
// // }

// // logCourses(myCourses)

// // let item = ["lol"]

// // localStorage.setItem("items", JSON.stringify(item))

// // let itemsFromLocalStorage = JSON.parse(localStorage.getItem("items"))

// // console.log(itemsFromLocalStorage)


// // let data = [
// //     {
// //         player: "Jane",
// //         score: 52
// //     },
// //     {
// //         player: "Mark",
// //         score: 41
// //     }
// // ]

// // const buttonEl = document.getElementById("button-el")

// // buttonEl.addEventListener("click", function() {
// //     console.log(data[0].score)
// // })

// function generateSentence(desc, arr) {
//     let baseString = `The ${arr.length} ${desc} are `
//     const lastIndex = arr.length - 1
//     for (let i = 0; i < arr.length; i++) {
//         if ( i === lastIndex) {
//             baseString += arr[i]
//         } else {
//             baseString += arr[i] + ", "
//         }   
//     }
//     return baseString
// }

// const sentence = generateSentence("largest countries", ["China", "USA", "India"] )
// console.log(sentence)

const imgs = [
    "assets/hip1.jpg",
    "assets/hip2.jpg",
    "assets/hip3.jpg"
]

const container = document.getElementById("container")

function renderImg() {
    let imageHolder = ""
    for (let i = 0; i < imgs.length; i++) {
        imageHolder += `<img src="${imgs[i]}" class="team-img">`
    }
    container.innerHTML = imageHolder
}

renderImg(imgs)