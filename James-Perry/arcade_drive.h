void CII(signed char x,signed char y,signed char s);
void dt_init();
void stable();

bool user_brake_request;
signed int right_total, left_total, wheel, throttle, quickturn;
signed int stable_point, stable_error, stable_p;
signed int arcade_throttle, arcade_wheel, tank_throttle;
signed int right_output, left_output;
unsigned short brake_value;
float stable_kp = .5;
