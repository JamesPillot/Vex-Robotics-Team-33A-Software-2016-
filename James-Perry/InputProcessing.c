void sample_gun_speed()
{
	right_gun_rotations = R_GUN_ENC;
	left_gun_rotations = L_GUN_ENC;

	right_gun_speed = (((right_gun_rotations - old_rgr)/.025) * 60)/GUN_ENC_CPI;
	left_gun_speed = (((left_gun_rotations - old_lgr)/.025) * 60)/GUN_ENC_CPI;

	old_rgr = right_gun_rotations;
	old_lgr = left_gun_rotations;

}
void input_proc()
{
	drive_distance = LENC/DRIVE_ENC_CPI; //distance traveled in inches
	curr_heading = GYRO/DEGREE;
	at_bottom = BOTTOM_SWITCH;
	at_top = TOP_SWITCH;
	at_middle = MIDDLE_SWITCH;
	sample_gun_speed(); //returns speed of shooter

	//process voltage of power expander here
}
void pick_color()
{
	if(COLOR_SWITCH > 2048)
	{
		red = true;
	}
	if(COLOR_SWITCH < 2048)
	{
		blue = true;
	}
}
void pick_auton()
{
	if(AUTON_SWITCH > 2048)
	{
		four_ball_plus = true;
	}
	if(AUTON_SWITCH < 2048)
	{
		four_ball = true;
	}
}
