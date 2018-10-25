#define SHOT_ERROR_THRESH 95 //in rpm
#define LONG_SHOT_ERROR_THRESH 100 //in rpm
#define SHOOTER_RAMP 35 //accel constant for velocity profile in rpm
#define SHOOTER_OFF_RAMP 2 //in power of motor (-127 to 127)
void shot_choice(char d, char e, char f, char g);
//void deflect_choice();
void choice_to_speed();
void shooter_init();

typedef enum
{
	off,
	short_shot,
	half_field,
	full_field,
	auton_shot
} shot_speeds;
shot_speeds speed_choice, last_speed_choice;

unsigned int shooter_speed[5] = //in rpm
{
	0, //off
	1510,//short shot - was power of 45
	1570,//half field - was power of 70
	1985,//full field - was power of 80
	1765 //close shot for four ball plus auto where we stay near pile
};

unsigned int right_shooter_value,left_shooter_value, pre_shooter_value, gun_delay,gun_delay_time,
last_pre_shooter_value, rs_pwr_diff, ls_pwr_diff, des_speed, shot_thresh;
unsigned short deflect_value;
bool gun_on, gun_at_speed;
