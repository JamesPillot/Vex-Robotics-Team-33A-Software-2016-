void fbp_and_stay() //stay where pile is we collect
{
	switch(a) //looking at this one for NDP
	{
		default:
		a = 0;
		break;

		case 0: //shoot
		speed_choice = full_field;
		a++;
		break;

		case 1: //wait for empty
		wait(6500);
		break;

		case 2: //turn to another preload and cut gun off
		speed_choice = off;
		TurnPID(-12);
		break;

		case 3: //drive to front of stack right in front and cut collector on, but not on stack yet
		collect_curr_state = suck;
		DriveStraight(9,22,23); //accel, vel, pos
		break;

		case 4: //creep up on stack
		DriveStraight(6,10,16);
		break;

		case 5: //wait for settling
		wait(100);
		break;

		case 6: //turn back to goal
		TurnPID(11);
		break;

		case 7: //shoot again and put on brakes
		user_brake_request = true;
		speed_choice = auton_shot;
		//collect_curr_state = collect_off;
		break;
	}
}
////////////////////////////////////////////////////////////////////////////
void fbp_backup() //go to pile then back away, using full field shot whole time
{
	switch(a) //ran at Haslett
	{
		default:
		a = 0;
		break;

		case 0: //shoot
		speed_choice = full_field;
		a++;
		break;

		case 1: //wait for empty
		wait(6500);
		break;

		case 2: //turn to another preload and cut gun off
		speed_choice = off;
		TurnPID(-8);
		break;

		case 3: //drive to stack right in front and cut collector on
		collect_curr_state = suck;
		DriveStraight(8,22,39);
		break;

		case 4: //back up
		DriveStraight(10,21,-37);
		break;

		case 5:
		TurnPID(9);
		break;

		case 6: //shoot again
		speed_choice = full_field;
		user_brake_request = true;
		//collect_curr_state = collect_off;
		break;
	}
}
