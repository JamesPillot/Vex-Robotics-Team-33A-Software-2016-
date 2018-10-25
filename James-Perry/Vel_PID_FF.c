void r_vel_pid_ff(float r_setpoint, float r_process_var)//james-perry copy
{
	rv_error = r_setpoint - r_process_var; //sp is in rpm and pv is measured shooter speed

	if(r_setpoint != r_old_setpoint) //reset I and last_error when given a new setpoint
	{
		rvI = r_last_v_error = 0;
	}
	if(rv_error > 0 && r_last_v_error < 0)
	{
		rvI = 0;
	}
	if(rv_error < 0 && r_last_v_error > 0)
	{
		rvI = 0;
	}

	rvP = vkp * rv_error;
	rvI += (vki * rv_error);
	if(abs(rvI) > V_I_CAP)
	{
		if(rvI > 0)
		{
			rvI = V_I_CAP;
		}
		if(rvI < 0)
		{
			rvI = (-1 * V_I_CAP);
		}
	}
	rvD = (rv_error - r_last_v_error) * vkd;
	rvV = vkv * v_mp_vel;

	if(vel_mp_curr_state != v_cruise)
	{
		rvP = rvI = rvD = 0;
	}
	if(rvP < 0)
	{
		rvP = 0;
	}
	r_vel_output = rvP + rvI + rvD + rvV;

	if(r_vel_output > 127)
	{
		r_vel_output = 127;
	}
	if(r_vel_output < -127)
	{
		r_vel_output = -127;
	}
	r_last_v_error = rv_error;
	r_old_setpoint = r_setpoint;
}
////////////////////////////////////////////// -- left side below
void l_vel_pid_ff(float l_setpoint, float l_process_var)//james-perry copy
{
	lv_error = l_setpoint - l_process_var; //sp is in rpm and pv is measured shooter speed

	if(l_setpoint != l_old_setpoint) //reset I and last_error when given a new setpoint
	{
		lvI = l_last_v_error = 0;
	}
	if(lv_error > 0 && l_last_v_error < 0)
	{
		lvI = 0;
	}
	if(lv_error < 0 && l_last_v_error > 0)
	{
		lvI = 0;
	}

	lvP = vkp * lv_error;
	lvI += (vki * lv_error);
	if(abs(lvI) > V_I_CAP)
	{
		if(lvI > 0)
		{
			lvI = V_I_CAP;
		}
		if(lvI < 0)
		{
			lvI = (-1 * V_I_CAP);
		}
	}
	lvD = (lv_error - l_last_v_error) * vkd;
	lvV = vkv * v_mp_vel;

	if(vel_mp_curr_state != v_cruise)
	{
		lvP = lvI = lvD = 0;
	}
	if(lvP < 0)
	{
		lvP = 0;
	}
	l_vel_output = lvP + lvI + lvD + lvV;

	if(l_vel_output > 127)
	{
		l_vel_output = 127;
	}
	if(l_vel_output < -127)
	{
		l_vel_output = -127;
	}
	l_last_v_error = lv_error;
	l_old_setpoint = l_setpoint;
}
