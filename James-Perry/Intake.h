#define FIRE_TIME 400 //neither in use, from old time based system
#define PAUSE_TIME 1000


void collector(char a, char b);
void conveyor_state_machine(char c);
void intake_init();

typedef enum{
	manual,
	index_up,
	send_to_gun,
	freeze
}conveyor_states;

typedef enum{
	clear,
	prep_fire,
	fire
}fire_states;

conveyor_states conveyor_curr_state, conveyor_last_state; //conveyor/fire states
fire_states fire_curr_state, fire_last_state;

signed int collect_value, conveyor_value;
bool done;
float time_passed;

typedef enum{
	collect_off,
	suck,
	blow
}collect_states;
collect_states collect_curr_state;

signed int collect_power[3] =
{
	0, //off
	127, //suck
	-127 //blow
};
