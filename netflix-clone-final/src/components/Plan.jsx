import React from "react";
import "./Plan.css";

export default function Plan({ name, description }) {
  return (
    <div className="plan">
      <div className="plan__info">
        <h5>
          <span className="plan__info--title">{name}</span>
          <br />
          {description}
        </h5>
      </div>

      <button>Subscribe</button>
    </div>
  );
}
