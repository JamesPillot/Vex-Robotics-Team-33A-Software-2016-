void fb_interrupt() //4 ball plus and interrupt
{
	switch(a)
	{
		default:
		a = 0;
		break;

		case 0: //drive to middle and right in front of opposing alliance zone
		DriveStraight(9,22,65); //accel, vel, pos
		break;

		case 1: //turn to goal
		//TurnPID(11);
		a++;
		break;

		case 2: //shoot and put brakes on
		speed_choice = half_field;
		user_brake_request = true;
		a++;
		break;

		case 3: //shoot at least one before collecting anything there
		wait(1000);
		break;

		case 4: //for any remaining balls that may roll our way
		collect_curr_state = suck;
		break;
	}
}
