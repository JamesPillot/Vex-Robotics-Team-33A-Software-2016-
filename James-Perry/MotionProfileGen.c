void mp_gen(float max_a, float max_v, float target)
{
	mp_error = target - mp_pos; //used in cruise state

	if(target != old_target) //checks to see if target is same or if new profile needed
	{
		mp_curr_state = accel;
		mp_pos = mp_vel = 0;
		target_change = true;
	}
	if(target == 0) //dont go anywhere if there is no target
	{
		max_a = 0;
	}
	if(target > 0) //determines direction of travel, true if going forward, false if not
	{
		mp_forward = true;
		max_a = max_a;
	}
	if(target < 0)
	{
		mp_forward = false;
		max_a = max_a;
	}
	if(abs(mp_vel) >= max_v && mp_curr_state != deccel)//if max_v reached, stop accelerating
	{
		mp_curr_state = cruise;
	}
	if(mp_curr_state == cruise && last_mp_state == accel)//if we just hit max velocity, lock in the distance it took to accelerate there
	{
		accel_dist = mp_pos;
	}

switch(mp_curr_state) //state machine to handle which equations to use
{
	default: //same as accel, we accelerate by default

		if(abs((target/2)) > abs(mp_pos)) //deccelerate if half of distance used to accelerate,skip cruise
		{
			mp_curr_state = deccel;
		}
		if(mp_forward) //determine acceleration based on direction of travel
		{
			max_a = max_a;
		}
		if(!mp_forward)
		{
			max_a = (-1 * max_a);
		}

		mp_vel += ((max_a/1000) * 25); //equations
		mp_pos += ((mp_vel/1000) * 25);

	break;

	case accel: //accelerate to cruise

		if(abs(mp_pos) > abs((target/2))) //deccelerate if half of distance used to accelerate,skip cruise
		{
			mp_curr_state = deccel;
		}
		if(mp_forward) //determine acceleration based on direction of travel
		{
			max_a = max_a;
		}
		if(!mp_forward)
		{
			max_a = (-1 * max_a);
		}

		mp_vel += (max_a/1000) * 25; //equations
		mp_pos += (mp_vel/1000) * 25;

	break;

	case cruise: //no acceleration,cruise at cruise velocity

		if(mp_forward) //decide when to deccelerate based on direction of travel
		{
			if(mp_error <= accel_dist)
			{
				mp_curr_state = deccel;
			}
		}
		if(!mp_forward)
		{
			if(mp_error >= accel_dist)
			{
				mp_curr_state = deccel;
			}
		}

		mp_pos += ((mp_vel/1000) * 25); //equation


	break;

	case deccel: //deccelerate to stop

		if(mp_forward) //if going forward, cant have velocity below 0
		{
			max_a = (-1 * max_a);

			if(mp_vel < 0)
			{
				mp_curr_state = rest;
			}
		}
		if(!mp_forward) //if going backward, cant have velocity above 0
		{
			max_a = max_a;

			if(mp_vel > 0)
			{
				mp_curr_state = rest;
			}
		}
		mp_vel += (max_a/1000) * 25; //equations
		mp_pos += (mp_vel/1000) * 25;

	break;

	case rest: //done

		mp_vel = 0;
		mp_pos = mp_pos;

	break;
}//end state machine

old_target = target;
last_mp_state = mp_curr_state;

}//end function, everything in inches/second, inches, inches/second^2
