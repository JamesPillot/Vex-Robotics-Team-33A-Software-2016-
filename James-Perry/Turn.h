#define TURN_QUIT_TIME 2000 //if no delta in 2 seconds, we are not getting there
#define TURN_I_CAP 15

void Turn(unsigned int turn_accel,unsigned int turn_velocity, signed int goal_heading);
void TurnGainScheduler();

float
TurnKp = 5,
TurnKi = 1,
TurnKd = .5,
TurnKv = 2.1; //was .853722

signed int last_goal_heading;
unsigned int turn_quit_timer;

////////////////// this bottom part only last minute for Haslett Turnament
void TurnPID(signed int turning_target);

float
simple_kp = 10,
simple_ki ,
simple_kd;

signed int last_turning_target, tt_error, last_tt_error, TP, TI, TD,t_output;
