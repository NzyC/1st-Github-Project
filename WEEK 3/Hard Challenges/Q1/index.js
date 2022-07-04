// function showRating(rating) {
//     let ovrRating = ''
//     for (let i = 0; i < Math.floor(rating); i++) {
//         ovrRating = ovrRating + '*'
//         if (i !== Math.floor(rating) - 1) {    
//             ovrRating = ovrRating + ' '
//         }
//     }
//     if (!Number.isInteger(rating)) {
//         ovrRating = ovrRating + ' .'
//     }
//     return ovrRating
// }

// console.log(showRating(109.5));

function showRating(rating) {
    let ovrRating = ''
    for (let i = 0; i < Math.floor(rating); i++) {
        ovrRating += '*'
        if (i !== Math.floor(rating)) {
            ovrRating += " "
        }
    }
    if (!Number.isInteger(rating)) {
        ovrRating += "."
    }
    return ovrRating
}

console.log(showRating(1.5));