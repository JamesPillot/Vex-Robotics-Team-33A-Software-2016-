void pid_ff(); //james-perry copy

#define I_CAP 10

float output, P,I,D,V, error, last_error, dist_tra;//dist_tra is actual distance covered by machine
float
kp,
ki,
kd,
kv; //kv is (127/max_velocity device can do)
