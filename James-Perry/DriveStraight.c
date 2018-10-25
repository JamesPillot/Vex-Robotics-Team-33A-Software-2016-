void DriveGainScheduler()
{
	kp = DriveKp;
	ki = DriveKi;
	kd = DriveKd;
	kv = DriveKv;
}

void DriveStraight(unsigned int accel,unsigned int velocity, signed int goal_position)
{
	if(goal_position != last_goal_position) //if new instance, reset variables
	{
		LENC = quit_timer = 0;
		curr_heading = GYRO = heading_sp = 0;
	}

	dist_tra = drive_distance; //set up process variable

	mp_gen(accel, velocity, goal_position); //motion profile, gain scheduler, and follower
	DriveGainScheduler();
	pid_ff();

	heading_error = heading_sp - curr_heading; //difference controller
	heading_output = heading_error * headingKp;

	right_output = (output + heading_output); //output
	left_output = (output - heading_output);

	last_goal_position = goal_position;

	move_on_dist = goal_position - dist_tra;

	if(abs(move_on_dist) < 1)
	{
		right_output = left_output = heading_output = 0;
		a++;
	}
} //end function
