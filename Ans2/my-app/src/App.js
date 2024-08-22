import React from "react";
import SemiCircleProgressBar from "react-progressbar-semicircle";
import "./App.css";

const App = () => {
  return (
    <div className="app-container">
      <div className="header">
        <button className="back-button">←</button>
        <h2>View patient</h2>
      </div>

      <div className="patient-info">
        <h3>S.Meena, F/23</h3>
        <p>Patient ID : 87 20200727153457</p>
        <div className="profile-picture">
          <span className="icon">👤</span>
        </div>
      </div>

      <div className="goal-container">
        <h4>Goal reached</h4>
        <div className="progress-semi-circle">
          <SemiCircleProgressBar percentage={40} showPercentValue />
        </div>
        <div className="graph-indicators">
          <div className="emg">
            <span>EMG</span>
            <div className="graph-line"></div>
          </div>
          <div className="rom">
            <span>ROM</span>
            <div className="graph-line1"></div>
          </div>
        </div>
      </div>

      <div className="contact-info">
        <p>
          <b>Phone no.</b>: 8022334455
        </p>
        <p>
          <b>Mail ID</b>: meenarabinsachin2@gmail.com
        </p>
        <p>
          <b>Affected side</b>: Bilateral
        </p>
        <p>
          <b>Condition</b>: Ortho
        </p>
        <p>
          <b>Speciality</b>: Osteoarthritis
        </p>
      </div>

      <div className="medical-history">
        <h4>Medical history</h4>
        <p>Hypertension, DM, Hypothyroidism</p>
      </div>
    </div>
  );
};

export default App;
