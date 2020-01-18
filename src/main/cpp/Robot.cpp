  #include "Robot.h"

#include <iostream>

#include <frc/smartdashboard/SmartDashboard.h>
#include "ctre/Phoenix.h"

void Robot::RobotInit() {
  m_chooser.SetDefaultOption(kAutoNameDefault, kAutoNameDefault);
  m_chooser.AddOption(kAutoNameCustom, kAutoNameCustom);
  frc::SmartDashboard::PutData("Auto Modes", &m_chooser);
}

void Robot::RobotPeriodic() {}

void Robot::AutonomousInit() {
  m_autoSelected = m_chooser.GetSelected();
  std::cout << "Auto selected: " << m_autoSelected << std::endl;

  if (m_autoSelected == kAutoNameCustom) {
    // Custom Auto goes here
  } else {
    // Default Auto goes here
  }
}

void Robot::AutonomousPeriodic() {
  if (m_autoSelected == kAutoNameCustom) {
    // Custom Auto goes here
  } else {
    // Default Auto goes here
  }
}

void Robot::TeleopInit() {}

float Robot::Deadzone(float input) {
  if (fabs(input) < .15) {
    input = 0.0;
  }
  else {
    if (input > 0) {
      input = (input - .15) / (1 - .15);
    }
    else {
      input = (input + .15) / (1 - .15);
    }
  }
  return input;
}

void Robot::TeleopPeriodic() {
  float left = Deadzone(joy.GetRawAxis(1));
  float right = Deadzone(joy.GetRawAxis(3));

  motorLeftFront.Set(ControlMode::PercentOutput, left);
  motorLeftBack.Set(ControlMode::PercentOutput, left);
  motorRightFront.Set(ControlMode::PercentOutput, right);
  motorRightBack.Set(ControlMode::PercentOutput, right);
}

void Robot::TestPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>(); }
#endif
