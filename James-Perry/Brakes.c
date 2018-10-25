void brake_decision()
{
	if(user_brake_request)
	{
		brake_value = 1;
	}
	if(!user_brake_request)
	{
		brake_value = 0;
	}
}
