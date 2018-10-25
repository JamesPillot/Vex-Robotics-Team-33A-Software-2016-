signed int limit_motor(signed int value);
signed int ramp_pwm(int input, int output, int ramp_step);
bool falling_edge(bool in_signal, bool last_in_signal);
bool in_auton;
//ramp pwm
#define THROTTLE_STEP 25 //used with arcade drive function
#define WHEEL_STEP 30

//resets all the drivetrain encoders
#define DT_ENC_RESET SensorValue[dgtl11] = 0;
#define SHOOTER_ENC_RESET SensorValue[dgtl1] = SensorValue[dgtl9] = 0;
