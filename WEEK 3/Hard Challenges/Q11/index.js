function removeApples(arr) {
    return arr.filter(elem => elem !== 'Apple')
}

console.log(removeApples(['Banana', 'Apple', 'Mango', 'Kiwi']));