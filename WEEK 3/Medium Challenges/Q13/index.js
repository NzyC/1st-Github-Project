function convertToBoolean(arr) {
  return arr.map(elem => !!elem)
}

console.log(convertToBoolean([2, 0, [], '']));