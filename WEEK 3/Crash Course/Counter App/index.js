// document.getElementById("count-el").innerText = 5

function increment() {
    console.log("The button was clicked")
}

let countEl = document.getElementById("count-el")

let saveEl = document.getElementById("save-el")

let count = 0

function increment() {
    count += 1
    countEl.innerText = count
    console.log(count)
}

function save() {
    countStr = count + " - "
    saveEl.textContent += countStr
    console.log(count)
    countEl.textContent = 0
    count = 0
}

