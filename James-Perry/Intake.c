void intake_init()
{
	conveyor_value = collect_value = 0;
	conveyor_curr_state = manual;
	fire_curr_state = clear;
}

void collector(char a, char b)
{
		collect_value = 0;

		if(a)
		{
			collect_value = 127;
		}
		if(b)
		{
			collect_value = -127;
		}
}

void conveyor_state_machine(char c)
{
	switch(conveyor_curr_state)
	{
		default:
		conveyor_curr_state = manual;
		break;

		case manual: //make intake do what collector is doing

		if(at_bottom || at_top || at_middle) //if hit limit switch, index up unless told not to
		{
			if(c)
			{
				conveyor_curr_state = manual;
			}
			else
			{
				conveyor_curr_state = index_up;
			}
		}
		if(gun_on)
		{
			if(c)
			{
				conveyor_curr_state = manual;
			}
			else
			{
				conveyor_curr_state = send_to_gun;
			}
		}
		conveyor_value = collect_value;
		break;

		case index_up:

		if(at_bottom && !at_top) //if ball at bottom, convey
		{
			conveyor_value = 127;
		}
		if(at_middle && !at_top)
		{
			conveyor_value = 127;
		}
		if(at_bottom && at_top) //if ball at top switch, stop moving and check for gun on
		{
			conveyor_value = 0;
			conveyor_curr_state = freeze;
		}
		if(at_middle && at_top)
		{
			conveyor_value = 0;
			conveyor_curr_state = freeze;
		}
		if(at_top)
		{
			conveyor_value = 0;
			conveyor_curr_state = freeze;
		}
		if(gun_on) //if gun at full power (send to gun)
		{
			conveyor_value = 0;
			conveyor_curr_state = send_to_gun;
		}
		if(!at_bottom && !at_top && !at_middle) //if no balls, don't convey
		{
			conveyor_value = 0;
		}
		if(c)
		{
			conveyor_curr_state = manual;
		}

		else
		{
			conveyor_curr_state = conveyor_curr_state;
		}

		break;

		case freeze: //do nothing, and look at conditions

		if(!at_top && at_bottom)
		{
			conveyor_curr_state = index_up;
		}
		if(!at_top)
		{
			conveyor_curr_state = index_up;
		}
		if(gun_on)
		{
			conveyor_curr_state = send_to_gun;
		}
		if(c)
		{
			conveyor_curr_state = manual;
		}
		else
		{
			conveyor_curr_state = conveyor_curr_state;
		}

		break;

		case send_to_gun:

		if(c)
		{
			conveyor_curr_state = manual;
		}
		if(!gun_on)
		{
			conveyor_curr_state = index_up;
		}

			switch(fire_curr_state)//fire shot state machine
			{
				default:
				fire_curr_state = clear;
				break;

				case clear: //fire init state
				time_passed = conveyor_value = 0;
				fire_curr_state = prep_fire;
				break;

				case prep_fire: //prepare to fire
				if(gun_at_speed)
				{
					fire_curr_state = fire;
				}
				if(!gun_at_speed)
				{
					fire_curr_state = prep_fire;
				}
				break;

				case fire: //only shoot when at speed
				conveyor_value = 127;

				if(!gun_at_speed)
				{
					conveyor_value = 0;
					fire_curr_state = prep_fire;
				}
				break; //end case
				fire_curr_state = fire_last_state;
			}//end fire sequence state machine

		break;//end fire case in conveyor state machine

	}//end conveyor state machine
	conveyor_last_state = conveyor_curr_state;


	if(in_auton) //autonomous ovverride of conveyor output
	{
		if(stop_intake)
		{
			conveyor_value = 0;
		}
		if(!stop_intake)
		{
			conveyor_value = conveyor_value;
		}
	}

}//end function
