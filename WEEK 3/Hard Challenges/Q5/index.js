async function postsByUser(uid) {
    let promise = await fetch('https://jsonplaceholder.typicode.com/posts');

    const res = await promise.json()
    
    const posts = res.filter(elem => elem.userId === uid)
    console.log(posts)
}

postsByUser(7)