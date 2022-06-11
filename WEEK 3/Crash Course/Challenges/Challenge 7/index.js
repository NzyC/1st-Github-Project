// let boxEl = document.getElementById("box-el")

// boxEl.addEventListener("click", function openRequest() {
//     console.log("I want to open the box!")
// })

const boxEl = document.getElementById("box-el")

boxEl.innerHTML = "<button onclick='buy()'>Buy!</button>"

function buy() {
    boxEl.innerHTML += "<p>Thank you for buying!</p>"
}