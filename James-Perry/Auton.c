
void auton_init()
{
	step = last_step = auton_time_elapsed = a = 0;
	pick_auton();
	pick_color();
}

void calc_auto_time_left()
{
	auton_time_elapsed += loop_time;
	auto_time_left = AUTO_TIME - auton_time_elapsed;
	if(abs(auto_time_left) <= SHUT_DOWN_TIME)
	{
		almost_out_of_time = true;
	}
	if(abs(auto_time_left) > SHUT_DOWN_TIME)
	{
		almost_out_of_time = false;
	}
}

void wait(int how_long)
{
	counter += 25;
	if(counter > how_long)
	{
		a++;
	}
	if(counter < how_long)
	{
		a = a;
	}
}

void auton_exec()
{
	if(red)
	{
		if(four_ball)
		{
			fb();
		}
		if(four_ball_plus)
		{
			fb_interrupt();
		}
	}

	if(blue)
	{
		if(four_ball)
		{
			fb();
		}
		if(four_ball_plus)
		{
			fbp_and_stay();
		}
	}
	last_step = step;
}
