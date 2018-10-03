#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {
    p_error = 1.0;
    i_error = 1.0;
    d_error = 1.0;
}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
    this->Kp = Kp;
    this->Ki = Ki;
    this->Kd = Kd;
}

void PID::UpdateError(double cte) {

    p_error = cte;
    d_error = cte - prev_error;   // TBD: Here should consider the delta t
    i_error += cte; // incrase the summation of cte

    prev_error = cte; // update previous cte
    

}

double PID::TotalError() {
    // Steering angle in this case
    return -(Kp * p_error + Kd * d_error + Ki * i_error);

}

