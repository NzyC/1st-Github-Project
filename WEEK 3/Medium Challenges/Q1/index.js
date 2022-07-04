function filterOutFalsy(val1, val2) {
    if (val1) {
        return val2
    }
    return val1
}

console.log(filterOutFalsy(true, 0));