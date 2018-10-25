#pragma platform(VEX)

//Competition Control and Duration Settings
#pragma competitionControl(Competition)
#pragma autonomousDuration(0)
#pragma userControlDuration(60)

int a = 0;

#include "Vex_Competition_Includes.c"   //Main competition background code...do not modify!
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
/////////////////////////////////////////////////////////////////////////////////////////
//
//                         Driver Skills Template
//
// This is a template for the driver skills competition. It is identical in structure to
// the standard competition template except that the two "#pragma' statements above (and
// copied below) adjust the time limits for the competition.
//				#pragma autonomousDuration(0)
//				#pragma userControlDuration(60)
// The autonomous duration for "Driver Skills" is zero; i.e. there is no autonomous phase.
// The user control duration is 60 seconds
//
// NOTE: The above two pragmas only impact the Crystal implementation. For systems using
//       VEXNET, the VEXNET system ignores these statements as it has the durations
//       for the competition built-in.
//
// Whenever this user program is run, the duration is automatically sent to the VEX master
// processor. The master CPU will only accept these commands once per power=on cycle. So, it's
// best to power cycle your VEX to ensure that they get recognized in case you were
// previously running a standard competition program with different durations.
//
// Testing Via Crystals:
// ====================
//
// The procedure to test a Driver Skills program using the crystals is as follows:
//
// 1. Turn off power to the Crystal transmitter/joysticks.
//
// 2. Turn on your VEX so that the Driver Skills program is running.
//
// 3. Driver skills program segment of your program will start running. At the end of 60
//    seconds the VEX Master CPU will turn off the motors.
//
// 4. Repeat the above sequence
//
//
// Testing Via VEXNET Using VEXNET Competition Switch
// ==================================================
//
// The procedure to test a Driver Skills program using VEXNET Competition Switch is as follows:
//
// 1. Set the two switches on the Competition switch to "DISABLE" and "USER CONTROL"
//
// 2. Start the Driver skills program
//
// 3. Set Switch to ENABLE from DISABLE
//
// 4. You need to manually time the 60 second duration.
//
// 5. Set Switch to DISABLE
//
// 6. Repeat from step (3) to run subsequent test runs. There's no need to reset the VEX or
//    restart your user program.
//
//
// Testing Via VEXNET Using ROBOTC IDE
// ==================================================
//
// It is not necessary to own a VEXNET switch. ROBOTC has a test window that allows the same functionality.
// The test window has three buttons for "DISABLE", "AUTONOMOUS", "USER CONTROL".
//
// 1. Open the ROBOTC Debugger. Then open the "Competition Control" Debugger window.
//
// 2. Start your Driver Skills program running.
//
// 3. Click the "DISABLED" button on the "Competition Control" window.
//
// 4. Click the "USER CONTROL" button on the "Competition Control" window.
//
// 5. You need to manually time the 60 second duration.
//
// 6. Click the "DISABLED" button on the "Competition Control" window.
//
// 7. Repeat from step (4) to run subsequent test runs. There's no need to reset the VEX or
//    restart your user program.
//
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
//
//                          Pre-Autonomous Functions
//
// You may want to perform some actions before the competition starts. Do them in the
// following function.
//
/////////////////////////////////////////////////////////////////////////////////////////

void pre_auton()
{
  // Set bStopTasksBetweenModes to false if you want to keep user created tasks running between
  // Autonomous and Tele-Op modes. You will need to manage all user created tasks if set to false.
  bStopTasksBetweenModes = true;

  in_auton = false;

	SensorType[in1] = sensorNone; //Gyro Initialization
	wait1Msec(1000);
	SensorType[in1] = sensorGyro;
	wait1Msec(2000);

  dt_init();//init drivetrain
	intake_init();//init intake system
	shooter_init();//init shooter

	// All activities that occur before the competition starts
	// Example: clearing encoders, setting servo positions, ...
}

/////////////////////////////////////////////////////////////////////////////////////////
//
//                                 Autonomous Task
//
// The "Driver Skills" competition has no autonomous phase. Simply leave the following
// placeholder.
//
/////////////////////////////////////////////////////////////////////////////////////////

task autonomous()
{
	in_auton = true;
	auton_init();
	while(1)
	{
		//process data
  	input_proc();
  	calc_auto_time_left();
  	//auton
		auton_exec();
  	//Control
		choice_to_speed();
		collect_value = collect_power[collect_curr_state];
		conveyor_state_machine(vexRT[Btn6D]);//hold 6D to control conveyor with collector
		//Write Motors
		Output();
		wait1Msec(25);
	}
}

/////////////////////////////////////////////////////////////////////////////////////////
//
//                                 User Control Task
//
// This task is used to control your robot during the user control phase of a VEX Competition.
// You must modify the code to add your own robot specific commands here.
//
/////////////////////////////////////////////////////////////////////////////////////////

task usercontrol()
{
	dt_init();//init drivetrain
	intake_init();//init intake system
	shooter_init();//init shooter
	in_auton = false;

	while (true)
	{
		//process data
		input_proc();
		//HMI
		CII(vexRT[Ch3], vexRT[Ch1],vexRT[Btn6U]);//ch3 is wheel, ch1 is throttle,6u is for brakes
		collector(vexRT[Btn5U], vexRT[Btn5D]);//suck - blow
		shot_choice(vexRT[Btn8U], vexRT[Btn8R], vexRT[Btn8D],vexRT[Btn8L]);//choose shooting power
		//Control
		choice_to_speed();
		conveyor_state_machine(vexRT[Btn6D]);//hold 6D to control conveyor with collector
		//Write Motors
		Output();
		wait1Msec(25);
	}
}
