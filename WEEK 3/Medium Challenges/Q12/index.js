function filterOutFalsy(arr) {
    return arr.filter(elem => !!elem == true)
}

console.log(filterOutFalsy(["n", [], 0, null, '0']))