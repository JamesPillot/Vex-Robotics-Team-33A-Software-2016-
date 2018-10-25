void mp_gen(float max_a, float max_v, float target);

float mp_vel, mp_pos, old_target, accel_dist, mp_error;
bool mp_forward,target_change = true;

typedef enum{
	accel,
	cruise,
	deccel,
	rest
}mp_states;

mp_states mp_curr_state, last_mp_state;
