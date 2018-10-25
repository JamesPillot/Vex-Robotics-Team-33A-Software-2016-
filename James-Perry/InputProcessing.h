//ENC_CPIs
#define DRIVE_ENC_CPI 107.54 //135.96 - old number
#define GUN_ENC_CPI 42
#define DEGREE 10
//function prototype
void input_proc();
void pick_color();
void pick_auton();
void sample_gun_speed();
//variables
bool at_bottom, at_top, at_middle, finish, last_at_top;
bool red, blue, four_ball, four_ball_plus;
float left_gun_speed, left_gun_rotations, right_gun_speed, right_gun_rotations,old_rgr,old_lgr,
drive_distance, total_time, curr_heading, loop_time = .025, shooter_battery;
