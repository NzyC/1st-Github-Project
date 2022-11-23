// MOVIE API = https://www.omdbapi.com/?i=tt3896198&apikey=5d41d2f2&s=${}
const filmCardContainerEl = document.querySelector(".film__card--container")
const searchInput = document.getElementById("searchInput")
const searchBtnEl = document.querySelector('.fa-solid')
const loadingEl = document.querySelector('.loading')
const initLandingEl = document.querySelector('.initial__landing')
const topLandingEl = document.querySelector('.top__landing')

async function main() {
  searchBtnEl.addEventListener('click', a => {
    renderMovies()
  })
  searchInput.addEventListener('keypress', e => {
    if (e.key === 'Enter') {

      renderMovies()
    }
  })
}

function lol() {
  console.log('hi')
}

async function renderMovies() {
  loadingEl.classList.remove('dontShow')
  initLandingEl.classList += ' dontShow'
  topLandingEl.classList += ' dontShow'
  const movies = await fetch(`https:www.omdbapi.com/?i=tt3896198&apikey=5d41d2f2&s=${searchInput.value}`)
  const moviesData = await movies.json()
  loadingEl.classList += ' dontShow'
  topLandingEl.classList.remove('dontShow')
  filmCardContainerEl.innerHTML = moviesData.Search.map((e) => filmHTML(e)).slice(0, 6).join('')
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