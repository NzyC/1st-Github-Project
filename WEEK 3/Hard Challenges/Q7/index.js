function calcTime(time) {
    let seconds = time % 60
    let minutes = Math.floor(time / 60)

    if (minutes.toString().length === 1) {
        minutes = '0' + minutes
    }
    return minutes + ':' + seconds

}

console.log(calcTime(1300));