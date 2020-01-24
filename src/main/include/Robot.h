#pragma once

#include <string>
#include <iostream>
#include <frc/smartdashboard/SmartDashboard.h>
#include "ctre/Phoenix.h"
#include "frc/WPILib.h"
#include <frc/TimedRobot.h>
#include <frc/smartdashboard/SendableChooser.h>
#include "rev/CANSparkMax.h"

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
  float fwd, turn, leftThrot, rightThrot;

  frc::Joystick joy{0};
  
  WPI_TalonSRX motorLeftFront{0};
  WPI_TalonSRX motorLeftBack{1};
  WPI_TalonSRX motorRightFront{2};
  WPI_TalonSRX motorRightBack{3};

  /*rev::CANSparkMax revMotor1{4, rev::CANSparkMax::MotorType::kBrushless};
  rev::CANSparkMax revMotor2{5, rev::CANSparkMax::MotorType::kBrushless};
    
  rev::CANEncoder motor1Encoder = revMotor1.GetEncoder();
  rev::CANEncoder motor2Encoder = revMotor2.GetEncoder();*/
};
