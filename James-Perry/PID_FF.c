void pid_ff() //james-perry copy
{
	error = mp_pos - dist_tra;

	if(target_change) //reset I and last_error when given a new setpoint
	{
		I = last_error = 0;
	}

	P = kp * error;
	I += (ki * error);
	if(abs(I) > I_CAP)
	{
		if(I > 0)
		{
			I = I_CAP;
		}
		if(I < 0)
		{
			I = (-1 * I_CAP);
		}
	}
	D = (error - last_error) * kd;
	V = kv * mp_vel;

	output = P + I + D + V;

	if(output > 127)
	{
		output = 127;
	}
	if(output < -127)
	{
		output = -127;
	}
	last_error = error;
}
