
#include "Robot.h"

void Robot::RobotInit() {
  motorRightFront.ConfigSelectedFeedbackSensor(FeedbackDevice::CTRE_MagEncoder_Relative, 0, 10);
  motorRightBack.ConfigSelectedFeedbackSensor(FeedbackDevice::CTRE_MagEncoder_Relative, 0, 10);
  motorLeftFront.ConfigSelectedFeedbackSensor(FeedbackDevice::CTRE_MagEncoder_Relative, 0, 10);
  motorRightBack.ConfigSelectedFeedbackSensor(FeedbackDevice::CTRE_MagEncoder_Relative, 0, 10);

  motorRightFront.SetSelectedSensorPosition(0);
  motorRightBack.SetSelectedSensorPosition(0);
  motorLeftFront.SetSelectedSensorPosition(0);
  motorLeftBack.SetSelectedSensorPosition(0);
}

void Robot::RobotPeriodic() {}

void Robot::AutonomousInit() {

}

void Robot::AutonomousPeriodic() {

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
  
  fwd = Deadzone(joy.GetRawAxis(1));
  turn = Deadzone(joy.GetRawAxis(4));

  leftThrot = turn - fwd;
  rightThrot = turn + fwd;

  motorLeftFront.Set(ControlMode::PercentOutput, leftThrot);
  motorLeftBack.Set(ControlMode::PercentOutput, leftThrot);
  motorRightFront.Set(ControlMode::PercentOutput, 1);
  motorRightBack.Set(ControlMode::PercentOutput, rightThrot);
}

void Robot::TestPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>(); }
#endif
