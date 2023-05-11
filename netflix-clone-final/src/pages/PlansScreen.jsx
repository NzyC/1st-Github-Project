import React from "react";
import "./PlansScreen.css";
import Plan from "../components/Plan";

export default function PlansScreen() {

  return <div className="plansScreen">
    <Plan name="Premium" description="4K + HDR" />
    <Plan name="Basic" description="720p" />
    <Plan name="Standard" description="1080p" />
  </div>;
}
