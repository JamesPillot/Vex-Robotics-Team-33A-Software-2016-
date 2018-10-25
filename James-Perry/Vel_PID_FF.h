void r_vel_pid_ff(float r_setpoint, float r_process_var); //james-perry copy
void l_vel_pid_ff(float l_setpoint, float l_process_var);

#define V_I_CAP 20

float r_vel_output, rvP,rvI,rvD,rvV, rv_error, r_last_v_error, r_old_setpoint, //rs variables

l_vel_output, lvP,lvI,lvD,lvV, lv_error, l_last_v_error, l_old_setpoint; //ls variables

float
vkp = .3,
vki = .035,
vkd,
vkv = .031479; //kv is (127/max_velocity device can do)- was .055579
