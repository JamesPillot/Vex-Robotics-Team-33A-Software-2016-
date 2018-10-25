#pragma config(Sensor, in1,    Gyro,           sensorGyro)
#pragma config(Sensor, in2,    ColorSwitch,    sensorPotentiometer)
#pragma config(Sensor, in3,    AutonSwitch,    sensorPotentiometer)
#pragma config(Sensor, in4,    PowerExpander,  sensorAnalog)
#pragma config(Sensor, dgtl1,  RightShooter,   sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  TopLimit,       sensorTouch)
#pragma config(Sensor, dgtl4,  BottomLimit,    sensorTouch)
#pragma config(Sensor, dgtl5,  Brakes,         sensorDigitalOut)
#pragma config(Sensor, dgtl6,  ShotDeflect,    sensorDigitalOut)
#pragma config(Sensor, dgtl8,  MiddleLimit,    sensorTouch)
#pragma config(Sensor, dgtl9,  LeftShooter,    sensorQuadEncoder)
#pragma config(Sensor, dgtl11, LeftDriveEncoder, sensorQuadEncoder)
#pragma config(Motor,  port1,           BackRightDrive, tmotorVex393_HBridge, openLoop, reversed)
#pragma config(Motor,  port2,           FrontRightDrive, tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port3,           Intake,        tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           ConveyorMotors, tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port5,           ShooterRight,  tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           ShooterMidRight, tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port7,           ShooterLeft,   tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           ShooterMidLeft, tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port9,           LeftBackDrive, tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port10,          LeftFrontDrive, tmotorVex393_HBridge, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//
int a = 0;
#include "James_library.h"
#include "SensorSetup.h"
#include "InputProcessing.h"
#include "arcade_drive.h"
#include "Shooter.h"
#include "Intake.h"
#include "Output.h"
#include "MotionProfileGen.h"
#include "VelocityProfileGen.h"
#include "PID_FF.h"
#include "Vel_PID_FF.h"
#include "DriveStraight.h"
#include "Turn.h"
#include "Auton.h"
#include "James_library.c"
#include "InputProcessing.c"
#include "arcade_drive.c"
#include "Shooter.c"
#include "Intake.c"
#include "Output.c"
#include "MotionProfileGen.c"
#include "VelocityProfileGen.c"
#include "PID_FF.c"
#include "Vel_PID_FF.c"
#include "DriveStraight.c"
#include "Turn.c"
#include "Fourballauto.c"
#include "Fourballautoplus.c"
#include "Auton.c"
int x = 0;


task main()
{
	SensorType[in1] = sensorNone; //Gyro Initialization
	wait1Msec(1000);
	SensorType[in1] = sensorGyro;
	wait1Msec(2000);

	dt_init();//init drivetrain
	intake_init();//init intake system
	shooter_init();//init shooter
	in_auton = false;
	while (true)
	{
		//process data
		input_proc();
		//HMI
		speed_choice = full_field;
		//Control
		choice_to_speed();
		conveyor_state_machine(vexRT[Btn6D]);//hold 6D to control conveyor with collector
		//Write Motors
		Output();
		wait1Msec(25);
	}
}