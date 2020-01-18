#pragma once

#include <string>
#include <iostream>
#include <frc/smartdashboard/SmartDashboard.h>
#include "ctre/Phoenix.h"
#include "frc/WPILib.h"
#include <frc/TimedRobot.h>
#include <frc/smartdashboard/SendableChooser.h>

class Robot : public frc::TimedRobot {
 public:
  void RobotInit() override;
  void RobotPeriodic() override;
  void AutonomousInit() override;
  void AutonomousPeriodic() override;
  void TeleopInit() override;
  void TeleopPeriodic() override;
  void TestPeriodic() override;
  float Deadzone(float);

 private:
  frc::SendableChooser<std::string> m_chooser;
  const std::string kAutoNameDefault = "Default";
  const std::string kAutoNameCustom = "My Auto";
  std::string m_autoSelected;

  float fwd, turn, leftThrot, rightThrot;

  frc::Joystick joy{1};
  
  WPI_TalonSRX motorLeftFront{0};
  WPI_TalonSRX motorLeftBack{1};
  WPI_TalonSRX motorRightFront{2};
  WPI_TalonSRX motorRightBack{3};
};
