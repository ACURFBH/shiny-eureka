#ifndef PREDATORPREY_H_INCLUDED
#define PREDATORPREY_H_INCLUDED
#include <iostream>
double A = 0.222, B = -0.0011, C = -1.999, E = 0.01;

class predatorPrey{
public:
    predatorPrey(double, double, double);
    //predatorPrey();// MAY NOT NEED
    ~predatorPrey();
    double stockAt(double);
    double get_t_when_y_is_greater_than_x();
private:
    double x_0;
    double y_0;
    double dt;
    double t_when_y_is_greater_than_x;
};

predatorPrey::predatorPrey(double initialX = 199, double initialY = 21, double delta = 0.0001)// x = 199, y = 21, dt = 0.0001
:x_0(initialX),y_0(initialY), dt(delta)
{
    // use the forward Euler method
    double t = 0;
    double x1, y1;
    double x2 = x_0;
    double y2 = y_0;
    do{
        x1 = x2;
        y1 = y2;
        x2 += dt * (A * x1 - B * x1 * y1);
        y2 += dt * (-C * y1 + E * y1 * x1);
        t += dt;
    }while(x2 > y2);

    this->t_when_y_is_greater_than_x = t;
}

double predatorPrey::stockAt(double timer)// NEED TO FIX RETURN VALUE AND BOOLEAN CONDITION
{
    // use the forward Euler method
    double t = 0;
    double x1, y1;
    double x2 = x_0;
    double y2 = y_0;
    do{
        x1 = x2;
        y1 = y2;
        x2 += dt * (A * x1 - B * x1 * y1);
        y2 += dt * (-C * y1 + E * y1 * x1);
        t += dt;
    }while(t < timer);// this probably runs forever, find different boolean
    return y2;// return wrong thing maybe?
}

predatorPrey::~predatorPrey(){}

double predatorPrey::get_t_when_y_is_greater_than_x()
{
    return t_when_y_is_greater_than_x;
}

#endif // PREDATORPREY_H_INCLUDED
