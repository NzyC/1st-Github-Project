function showRating(rating) {
    let ratings = ""
    for (let i = 0; i < Math.floor(rating); ++i) {
        ratings += "*"
        if (i !== Math.floor(rating) - 1) {
            ratings += " "
        }
    }
    if (rating > Math.floor(rating)) {
        ratings += " ."
    }
    return ratings
} 

console.log(showRating(3.5));