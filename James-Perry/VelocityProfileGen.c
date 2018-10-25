void vel_mp_gen(float max_a, float target_v)
{

	if(target_v != old_target_v && target_v > old_target_v) //checks to see if target is same or if new profile needed
	{
		vel_mp_curr_state = v_accel;
		vel_target_change = true;
	}
	if(target_v != old_target_v && target_v < old_target_v)
	{
		vel_mp_curr_state = v_naccel;
		vel_target_change = true;
	}
	if(target_v == 0) //dont go anywhere if there is no target
	{
		max_a = 0;
		vel_mp_curr_state = v_rest;
	}
	if(target_v != 0)
	{
		max_a = max_a;
	}

switch(vel_mp_curr_state) //state machine to handle which equations to use
{
	default: //if not sure what to do , do nothing


	break;

	case v_accel: //accelerate to cruise

	if(v_mp_vel >= target_v) //once at target velocity, stop accelerating
	{
		vel_mp_curr_state = v_cruise;
	}

	v_mp_vel += max_a; //equation

	break;

	case v_naccel:
	if(v_mp_vel <= target_v)
	{
		vel_mp_curr_state = v_cruise;
	}
	v_mp_vel -= max_a;
	break;

	case cruise: //no acceleration,cruise at cruise velocity
	v_mp_vel = v_mp_vel; //equation
	break;

	case rest: //done

	v_mp_vel = 0;

	break;
}//end state machine

old_target_v = target_v;
last_vel_mp_state = vel_mp_curr_state;

}
