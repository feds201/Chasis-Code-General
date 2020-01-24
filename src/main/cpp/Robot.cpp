
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
  motorRightFront.Set(ControlMode::PercentOutput, rightThrot);
  motorRightBack.Set(ControlMode::PercentOutput, rightThrot);

  std::cout << "Right Front's Position " << motorRightFront.GetSelectedSensorPosition() << std::endl;
  std::cout << "Left Front's Position " << motorLeftFront.GetSelectedSensorPosition() << std::endl;
  std::cout << "Right Back's Position " << motorRightBack.GetSelectedSensorPosition() << std::endl;
  std::cout << "Left Back's Position " << motorLeftBack.GetSelectedSensorPosition() << std::endl;

  std::cout << "Right Front's Velocity " << motorRightFront.GetSelectedSensorVelocity() << std::endl;
  std::cout << "Left Front's Velocity " << motorLeftFront.GetSelectedSensorVelocity() << std::endl;
  std::cout << "Right Back's Velocity " << motorRightBack.GetSelectedSensorVelocity() << std::endl;
  std::cout << "Left Back's Velocity " << motorLeftBack.GetSelectedSensorVelocity() << std::endl;

  /*std::cout << "Rev Motor1's Position " << motor1Encoder.GetPosition() << std::endl;
  std::cout << "Rev Motor2's Position " << motor2Encoder.GetPosition() << std::endl;

  std::cout << "Rev Motor1's Velocity " << motor1Encoder.GetVelocity() << std::endl;
  std::cout << "Rev Motor2's Velocity " << motor1Encoder.GetVelocity() << std::endl;*/
}

void Robot::TestPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>(); }
#endif
