#include "pid.h"

float runPID(pid_context_t * p,float setpoint,float input){

    float error;
    float deriv;
    float output;

    error = setpoint - input;
    //use input instead of error to avoid derivative kick
    deriv = (input - p->prev_in) / p->dt;

    //intergal has already included ki part
    //to avoid sudden gain caused by changing ki 
    p->integral += p->ki * error * p->dt;

    if(p->integral > p->max){p->integral = p->max;}
    if(p->integral < p->min){p->integral = p->min;}

    p->prev_in = input;
    output =  error*p->kp + p->integral + deriv*p->kd;

    if(output > p->max){output = p->max;}     
    if(output < p->min){output = p->min;}
    return output;
}


void stablize_pid_init(pid_context_t *roll,pid_context_t *pitch,pid_context_t *yaw){
    roll->dt = 0.01666666666f;//60Hz
    roll->kp;
    roll->ki;
    roll->kd;
    roll->prev_in = 0.0f;
    roll->integral = 0.0f;
    roll->max;
    roll->min;

    pitch->dt = 0.01666666666f;
    pitch->kp;
    pitch->ki;
    pitch->kd;
    pitch->prev_in = 0.0f;
    pitch->integral = 0.0f;
    pitch->max;
    pitch->min;

    yaw->dt = 0.01666666666f;
    yaw->kp;
    yaw->ki;
    yaw->kd;
    yaw->prev_in = 0.0f;
    yaw->integral = 0.0f;
    yaw->max;
    yaw->min;
}


void rate_pid_init(pid_context_t *roll_r,pid_context_t *pitch_r,pid_context_t *yaw_r){
    roll_r->dt = 0.01666666666f;
    roll_r->kp;
    roll_r->ki;
    roll_r->kd;
    roll_r->prev_in = 0.0f;
    roll_r->integral = 0.0f;
    roll->max;
    roll->min;

    pitch_r->dt = 0.01666666666f;
    pitch_r->kp;
    pitch_r->ki;
    pitch_r->kd;
    pitch_r->prev_in = 0.0f;
    pitch_r->integral = 0.0f;
    pitch_r->max;
    pitch_r->min;

    yaw_r->dt = 0.01666666666f;
    yaw_r->kp;
    yaw_r->ki;
    yaw_r->kd;
    yaw_r->prev_in = 0.0f;
    yaw_r->integral = 0.0f;
    yaw_r->max;
    yaw_r->min;
}

