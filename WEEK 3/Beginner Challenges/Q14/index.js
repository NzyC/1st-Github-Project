function isLoggedInAndSubscribed (a, b) {
    return( a === "LOGGED_IN") || (b === "SUBSCRIBED")
}

console.log(isLoggedInAndSubscribed('LOGGED_IN', 'UNSUBSCRIBED'));