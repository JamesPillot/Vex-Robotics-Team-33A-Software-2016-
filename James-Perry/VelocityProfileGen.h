void vel_mp_gen(float max_a, float target_v);

float v_mp_vel, old_target_v;
bool vel_target_change = true;

typedef enum{
	v_accel,
	v_naccel, //negative acceleration for ramp down
	v_cruise,
	v_rest
}vel_mp_states;

vel_mp_states vel_mp_curr_state, last_vel_mp_state;
