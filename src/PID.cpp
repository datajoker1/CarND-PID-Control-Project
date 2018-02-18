#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double p, double i, double d) {
  Kp = p;
  Ki = i;
  Kd = d;
  cte_prev = 0;
  cte_int = 0;
}

void PID::UpdateError(double cte) {
  cte_int += cte;
  p_error = Kp * cte;
  d_error = Kd * (cte - cte_prev);
  i_error = Ki * cte_int;

  cte_prev = cte;
}

double PID::TotalError() {
    return -(p_error + d_error + i_error);
}
