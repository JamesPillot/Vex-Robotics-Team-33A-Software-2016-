void dt_init()
{
	right_total = 0;
	left_total = 0;
	DT_ENC_RESET
}

//void stable()
//{
//	//stable_point = 0;
//	//stable_error = stable_point - LENC;//error
//	//stable_p = stable_error * stable_kp;//p
//	//stable_p = limit_motor(stable_p);//limit motor
//	//right_total = left_total = stable_p;//total
//}

void CII(signed char x,signed char y,signed char s)
{
	//ramp pwm period
	arcade_throttle = ramp_pwm(x, arcade_throttle, THROTTLE_STEP);
	arcade_wheel = ramp_pwm(y, arcade_wheel, WHEEL_STEP);
	tank_throttle = ramp_pwm (vexRT[Ch2], tank_throttle, THROTTLE_STEP);
	//start halo drive
	quickturn = 0;
	if(abs(arcade_wheel) > 30)
	{
		quickturn = 1;
	}

	if(quickturn) //works good for throttle = 0
	{
		wheel = arcade_wheel * 1.2;//was 1.5
		throttle = arcade_throttle;

		left_total = limit_motor((throttle + wheel));
		right_total = limit_motor((throttle - wheel));
	}

	else
	{
		throttle = arcade_throttle;
		float new_throttle = throttle;
		new_throttle /= 127;
		wheel = arcade_wheel * 1.4 * (float)new_throttle;


		left_total = limit_motor((throttle + wheel));
		right_total = limit_motor((throttle - wheel));
	}

	if(s)
	{
		user_brake_request = true;
	}
	if(!s)
	{
		user_brake_request = false;
	}
//outputs
	left_output = left_total;
	right_output = right_total;
}

//thank you palardy for the halo drive and the cheesy poofs for the original algorithm
