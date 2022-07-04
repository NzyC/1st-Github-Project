function sortHighToLow(arr) {
    return arr.sort((a, b) => b.price - a.price)
}

console.log(sortHighToLow(
    [{
        id: 1, price: 5
    },
    {
        id: 2, price: 980
    },
    {
        id: 3, price: 230
    }, 
    {
        id: 4, price: 40
    }, 
    {
        id: 5, price: 500
    }]
));