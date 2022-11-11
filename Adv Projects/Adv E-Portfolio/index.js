// template_fpp8gjk
// service_ninx7lp
// lPLZsiOp8f-EMujJl

function contact(event) {
  event.preventDefault();
  const loading = document.querySelector(".modal__overlay--loading");
  const success = document.querySelector(".modal__overlay--success");
  loading.classList += " modal__overlay--visible";
  emailjs
    .sendForm(
      'service_ninx7lp',
      'template_fpp8gjk',
      event.target,
      'lPLZsiOp8f-EMujJl'
    ).then(() => {
      loading.classList.remove("modal__overlay--visible")
      success.classList += " modal__overlay--visible"
    }).catch(() => {
      loading.classList.remove("modal__overlay--visible")
      alert(
        "The email service is temporary unavailable. Please contact me directly on nidal.chowdhury1@gmail.com"
      )
    })
}

function toggleModal() {
  // toggle modal
}