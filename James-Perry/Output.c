void Output()
{
	DRIVE_RIGHT(right_output);
	DRIVE_LEFT(left_output);
	COLLECTOR(collect_value);
	CONVEYOR(conveyor_value);
	SHOOTER_RS(right_shooter_value);
	SHOOTER_LS(left_shooter_value);
	DEFLECTOR(deflect_value);
	BRAKES(brake_value);
}
