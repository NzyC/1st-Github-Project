// template_fpp8gjk
// service_ninx7lp
// lPLZsiOp8f-EMujJl

function contact(event) {
  event.preventDefault();
  // emailjs
  //   .sendForm(
  //     'service_ninx7lp',
  //     'template_fpp8gjk',
  //     event.target,
  //     'lPLZsiOp8f-EMujJl'
  //   ).then(() => {
  //     console.log('this worked1')
  //   })

  const loading = document.querySelector("modal__overlay--loading");
  const success = document.querySelector("modal__overlay--success");
  loading.classList += " modal__overlay--visible";
  setTimeout(() => {
    console.log('it worked 1')
  }, 500);

}