void TurnGainScheduler()
{
	kp = TurnKp;
	ki = TurnKi;
	kd = TurnKd;
	kv = TurnKv;
}

void Turn(unsigned int turn_accel,unsigned int turn_velocity, signed int goal_heading)
{
	if(goal_heading != last_goal_heading) //if new instance, reset variables
	{
		LENC = turn_quit_timer = 0;
		curr_heading = GYRO = heading_sp = 0;
	}
	if(error != last_error) //if advancing, don't think about quitting
	{
		turn_quit_timer = 0;
	}

	dist_tra = curr_heading;
	mp_gen(turn_accel, turn_velocity, goal_heading); //motion profile, gain scheduler, and follower
	TurnGainScheduler();
	pid_ff();

	right_output = output; //output
	left_output = (-1 * output);

	last_goal_heading = goal_heading;

	if(abs((goal_heading - curr_heading)) < 2) //2 degree of error allowance for exit
	{
		right_output = left_output = output = 0;
		a++;
	}
} //end function

/////////////////////////////////// Haslett tourney last minute below
void TurnPID(signed int turning_target)
{
	if(turning_target != last_turning_target)
	{
		curr_heading = 0;
	}

	tt_error = turning_target - curr_heading; //error calc

	TP = tt_error * simple_kp; //math
	TI += (tt_error * simple_ki);

	if(abs(TI) > TURN_I_CAP)//cap integral term
	{
		if(TI > 0)
		{
			TI = TURN_I_CAP;
		}
		if(TI < 0)
		{
			TI = (-1 * TURN_I_CAP);
		}
	}
	TD = (tt_error - last_tt_error) * kd; //end of math

	last_tt_error = tt_error; //remember last error

	t_output = TP + TI + TD; //sum

	if(t_output > 127) //cap output
	{
		t_output = 127;
	}
	if(t_output < -127)
	{
		t_output = -127;
	}

	right_output = t_output; //output
	left_output = (-1 * t_output);

	last_turning_target = turning_target;

	if(abs(tt_error) < 2) //2 degree of error allowance for exit
	{
		right_output = left_output = output = 0;
		a++;
	}
}
