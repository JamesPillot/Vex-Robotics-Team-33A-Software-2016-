void DriveStraight(unsigned int accel,unsigned int velocity, signed int goal_position);
void DriveGainScheduler();

float //gains for driving straigt
DriveKp = 3,
DriveKi = 2,
DriveKd,
DriveKv = 5.5217;

signed int last_goal_position, move_on_dist;
unsigned int quit_timer;

float
headingKp = 15;

float heading_sp,heading_error,heading_output;
