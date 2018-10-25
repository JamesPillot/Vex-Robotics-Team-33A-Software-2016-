//this is the four ball auto, just shoot what we have
void fb()
{
	switch(a)
	{
		default:
		a = 0;
		break;

		case 0: //cut gun on
		speed_choice = full_field;
		a++;
		break;

		case 1: //if almost out of time cut gun off and let shooter wind down
		//if(almost_out_of_time)
		//{
		//	speed_choice = off;
		//}
		break;
	}
}
