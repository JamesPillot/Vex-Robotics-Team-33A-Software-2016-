void shooter_init()
{
	speed_choice = off;
	pre_shooter_value = right_shooter_value = left_shooter_value = off;
	gun_on = false;
	deflect_value = 0;
	SHOOTER_ENC_RESET
}
void shot_choice(char d, char e, char f, char g)
{
	if(d)
	{
		speed_choice = off;
	}
	if(e)
	{
		speed_choice = short_shot;
	}
	if(f)
	{
		speed_choice = half_field;
	}
	if(g)
	{
		speed_choice = full_field;
	}
	else
	{
		speed_choice = speed_choice;
	}
	last_speed_choice = speed_choice;

	if(speed_choice != short_shot) //deflecter choice based on shot choice
	{
		deflect_value = 0;
	}
	if(speed_choice == short_shot)
	{
		deflect_value = 1;
	}
	else
	{
		deflect_value = deflect_value;
	}
}

void choice_to_speed()
{
	des_speed = shooter_speed[speed_choice]; //pick rpm value from LUT

	if(speed_choice == off) //ramp down when turning off
	{
		gun_on = false;
		pre_shooter_value = off;
		right_shooter_value = ramp_pwm(pre_shooter_value, right_shooter_value, SHOOTER_OFF_RAMP);//control ramp up and down
		left_shooter_value = ramp_pwm(pre_shooter_value, left_shooter_value, SHOOTER_OFF_RAMP);
	}
	if(speed_choice != off)
	{
		gun_on = true;

		vel_mp_gen(SHOOTER_RAMP, des_speed); //make profile for shooter

		r_vel_pid_ff(des_speed, right_gun_speed); //feedback on right
		l_vel_pid_ff(des_speed, left_gun_speed); //feedback on left

		right_shooter_value = r_vel_output; //output on right
		left_shooter_value = l_vel_output; //output on left

		rs_pwr_diff = des_speed - right_gun_speed; //check margin of error
		ls_pwr_diff = des_speed - left_gun_speed;
	}

	if(speed_choice == full_field)
	{
		shot_thresh = LONG_SHOT_ERROR_THRESH;
	}
	else
	{
		shot_thresh = SHOT_ERROR_THRESH;
	}
	if(abs(rs_pwr_diff) < shot_thresh && abs(ls_pwr_diff) < shot_thresh && speed_choice != off)
	{
		gun_at_speed = true;
	}
	if(speed_choice == off)
	{
		gun_at_speed = false;
	}
	if(abs(rs_pwr_diff) > shot_thresh && abs(ls_pwr_diff) > shot_thresh)
	{
		gun_at_speed = false;
	}

}
