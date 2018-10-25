#define AUTO_TIME 15
#define SHUT_DOWN_TIME 2.5

void auton_exec();
void auton_init();

void calc_auto_time_left();
void wait(unsigned int how_long);

void fb(); //four ball
void fbp_backup(); //four ball plus and back up to shoot
void fbp_and_stay(); //four ball plus and stay near pile to shoot
void fb_interrupt(); //four ball and mess with other teams' hoarding path

short step, last_step, auto_time_left;
unsigned int auton_time_elapsed, counter;
bool almost_out_of_time, stop_intake;
