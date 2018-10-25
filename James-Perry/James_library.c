signed int limit_motor(signed int value) //caps motor output
{
	if(value > 127)
	{
		value = 127;
	}
	if(value < -127)
	{
		value = -127;
	}

	return value;
}

signed int ramp_pwm(int input, int output, int ramp_step)
{
	if(input >= (output + ramp_step))
	{
		output = output + ramp_step;
	}
	else if (input <= (output - ramp_step))
	{
		output = output - ramp_step;
	}
	else
	{
		output = input;
	}
	return limit_motor(output);
}

bool falling_edge(bool in_signal, bool last_in_signal)
{
	if(!in_signal && last_in_signal)
	{
		return true;
	}
	else
	{
		return false;
	}
}
