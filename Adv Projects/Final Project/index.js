// MOVIE API = https://www.omdbapi.com/?i=tt3896198&apikey=5d41d2f2&s=${}
const filmCardContainerEl = document.querySelector(".film__card--container")
const searchInputValue = document.getElementById("searchInput").value

async function main() {
  const movies = await fetch(`https:www.omdbapi.com/?i=tt3896198&apikey=5d41d2f2&s=harry`)
  const moviesData = await movies.json()
  const moviesNewData = moviesData.Search
  filmCardContainerEl.innerHTML = moviesNewData.map((e) => filmHTML(e)).slice(0, 6).join('')
  console.log(moviesData);
}

main()

function filmHTML(film) {
  return `
  <div class="film__card">
    <img src="${film.Poster}" class="film__poster">
    <h1 class="film__title">${film.Title}</h1>
    <p class="film__release">Year: ${film.Year}</p>
    <p class="film__type">Type: ${film.Type}</p>
    <p class="film__type">IMDB ID: ${film.imdbID}</p>
  </div>
  `
} 