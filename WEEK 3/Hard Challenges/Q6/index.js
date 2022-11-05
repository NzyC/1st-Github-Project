async function firstSixIncomplete() {
    const todos = await fetch('https://jsonplaceholder.typicode.com/todos')

    const res = await todos.json()
    
    let data = res.filter(elem => !elem.completed).slice(0, 6)

    console.log(data);
}

firstSixIncomplete()