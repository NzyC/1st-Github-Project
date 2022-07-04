// function convertToZeros(arr) {
//     for (let i = 0; i < arr.length; i++) {
//         arr[i] = 0
//     }
//     return arr
// }

// console.log(convertToZeros([9, 7]));

function convertToZeros(arr) {
    return arr.map(elem => 0)
}

console.log(convertToZeros([9, 4, 1, 5]));