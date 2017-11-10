#include <iostream>
#include "tools.h"


using Eigen::VectorXd;
using Eigen::MatrixXd;
using std::vector;

Tools::Tools() {}

Tools::~Tools() {}

VectorXd Tools::CalculateRMSE(const vector<VectorXd> &estimations, const vector<VectorXd> &ground_truth)
{

    //calculate rmse

    VectorXd rmse(4);
    rmse << 0,0,0,0;

    if(estimations.size() != ground_truth.size() || estimations.size() == 0)
    {
        return rmse;
    }

    for(unsigned int i=0; i < estimations.size(); ++i)
    {
        VectorXd residual = estimations[i] - ground_truth[i];

        residual = residual.array()*residual.array();
        rmse += residual;
    }

    rmse = rmse/estimations.size();
    rmse = sqrt(rmse.array());

    return rmse;

}

MatrixXd Tools::CalculateJacobian(const VectorXd& x_state)
{

  //Calculate Jacobian Hj.

    MatrixXd Hj(3,4);


    float px = x_state(0);
    float py = x_state(1);
    float vx = x_state(2);
    float vy = x_state(3);

    float calc1 = px*px+py*py;

    //Avoid division by 0
    if(calc1 < 0.00001)
    {
        px += 0.001;
        py += 0.001;
        calc1 = px * px + py * py;
    }

    float calc2 = sqrt(calc1);
    float calc3 = calc1 * calc2;


    Hj << px/calc2, py/calc2, 0, 0,
            -(py/calc1), px/calc1, 0, 0,
            py*(vx*py-vy*px)/calc3, px*(vx*py-vy*px)/calc3, px/calc2, py/calc2;

    return Hj;


}
