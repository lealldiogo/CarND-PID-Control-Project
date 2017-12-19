#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {

  this->Kp = Kp;
  this->Ki = Ki;
  this->Kd = Kd;

  p_error = 0;
  i_error = 0;
  d_error = 0;

}

void PID::UpdateError(double cte) {

  d_error = cte - p_error;
  p_error = cte;
  i_error += cte;

}

double PID::TotalError() {
  return Kp*p_error + Ki*i_error + Kd*d_error;
}


// it = 0
// if (sum(dp) > 0.2) {
//     print("Iteration {}, best error = {}".format(it, best_err))
//     for i in range(len(p)):
//         p[i] += dp[i]
//         robot = make_robot()
//         x_trajectory, y_trajectory, err = run(robot, p)

//         if err < best_err:
//             best_err = err
//             dp[i] *= 1.1
//         else:
//             p[i] -= 2 * dp[i]
//             robot = make_robot()
//             x_trajectory, y_trajectory, err = run(robot, p)

//             if err < best_err:
//                 best_err = err
//                 dp[i] *= 1.1
//             else:
//                 p[i] += dp[i]
//                 dp[i] *= 0.9
//     it += 1
// }

// err = 0;
// for (int i = 0; i < 2*n; i++){
//   if (i >= n){
//     err += cte ** 2;
//   }
// }
// err/n
