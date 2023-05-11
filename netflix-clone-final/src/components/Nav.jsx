import React, { useEffect, useState } from "react";
import { useNavigate } from "react-router-dom";
import "./Nav.css";

export default function Nav() {
  const [show, handleShow] = useState(false);
  const navigate = useNavigate();

  function transitionNavBar() {
    if (window.scrollY > 100) {
      handleShow(true);
    } else {
      handleShow(false);
    }
  }

  useEffect(() => {
    window.addEventListener("scroll", transitionNavBar);
    return () => window.removeEventListener("scroll", transitionNavBar);
  }, []);

  return (
    <div className={`nav ${show && "nav__black"}`}>
      <div className="nav__content">
        <img
          className="nav__logo"
          src="https://www.edigitalagency.com.au/wp-content/uploads/netflix-logo-png-large.png"
          alt=""
          onClick={() => {
            navigate("/")
          }}
        />
        <img
          className="nav__avatar"
          src="https://upload.wikimedia.org/wikipedia/commons/0/0b/Netflix-avatar.png"
          alt=""
          onClick={() => {
            navigate("/profile");
          }}
        />
      </div>
    </div>
  );
}
