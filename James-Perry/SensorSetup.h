//actuators
#define DRIVE_RIGHT(value) motor[port4] = motor[port2] = (value)
#define DRIVE_LEFT(value)  motor[port9] = motor[port3] = (value)
#define COLLECTOR(value) motor[port1] = (value)
#define CONVEYOR(value) motor[port10] = (value)
#define SHOOTER_RS(value) motor[port7] = motor[port8] = (value)
#define SHOOTER_LS(value) motor[port5] = motor[port6] = (value)
/////////////////////////////////////////////////////////////////
#define DEFLECTOR(value) SensorValue[dgtl6] = (value)
#define BRAKES(value) SensorValue[dgtl5] = (value)
//sensors
#define GYRO SensorValue[in1]
#define COLOR_SWITCH SensorValue[in2]
#define AUTON_SWITCH SensorValue[in3]
#define PWR_EXPANDER SensorValue[in4]
///////////////////////////////////////////
#define LENC SensorValue[dgtl11]
#define TOP_SWITCH SensorValue[dgtl3]
#define BOTTOM_SWITCH SensorValue[dgtl4]
#define MIDDLE_SWITCH SensorValue[dgtl8]
#define L_GUN_ENC SensorValue[dgtl9]
#define R_GUN_ENC SensorValue[dgtl1]
