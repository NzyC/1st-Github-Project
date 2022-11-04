// function reverseString(str) {
//     let stringName = ''
//     for (let i = str.length - 1; i >= 0; --i) {
//         stringName = stringName + str[i];
//     }
//     return stringName
// }

// console.log(reverseString('Nidal'))

function reverseString(str) {
    return str.split('').reverse().join('')
}

console.log(reverseString('Nidal'));