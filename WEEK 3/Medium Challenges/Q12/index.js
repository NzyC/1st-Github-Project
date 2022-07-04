// function filterOutFalsy(arr) {
//     return arr.filter(elem => !!elem === true)
// }

// console.log(filterOutFalsy(["", [], null, undefined, "0"]));

function filterOutFalsy(arr) {
    let truthyArray = []
    for (let i = 0; i < arr.length; i++) {
        if (!!arr[i] === true) {
            
        truthyArray.push(arr[i])
        }
    }
    return truthyArray
}

console.log(filterOutFalsy(["", [], null, undefined, "0"]));