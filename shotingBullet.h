#ifndef SHOTINGBULLET_H_INCLUDED
#define SHOTINGBULLET_H_INCLUDED
#include <iostream>
double G = 9.8, K = 0.00911, M = 0.1;//constants for gravity, air resistance, mass; respectively


class shotingBullet{
public:
    //shotingBullet();// MAY NOT NEED AS DEFAULT CONSTRUCTOR
    shotingBullet(double, double);
    ~shotingBullet();
    double get_height();
    double get_air_time();
    void RungeKutta(double, double, double);
    void RungeKuttaDuo(double, double, double);

private:
    double v_0;// initial velocity
    double m;// mass
    double height;// calculated using the calculateTotals function
    double timeTot;// calculated using the calculateTotals function
    double f(double t, double y){
        return -t*(G + (K/M)*y);
    }
    double g(double t, double y){
        return t*(G - (K/M)*y);
    }
    void calculateTotals(double dt);
};

shotingBullet::shotingBullet(double mass = 0.1, double initialVelocity = 300)// mass of 0.1 and v_0 of 300
{
    this ->v_0 = initialVelocity;
    this->m = mass;
    calculateTotals(1);//let the change in t be 1 minute
}
shotingBullet::~shotingBullet(){}

double shotingBullet::get_air_time(){
    return this->timeTot;
}

double shotingBullet::get_height(){
    return this ->height;
}

void shotingBullet::calculateTotals(double dt){
    //use the Runge-Kutta to solve
    RungeKuttaDuo(0,0,1); // initial time, initial height, and time interval; respectively
}
void shotingBullet::RungeKutta(double y, double t, double dt){
    //run rungeKutta
    double k_1, k_2, k_3, k_4, dy=y;
    while(dy > 0){
        //do stuff
        k_1 = dt * f(t,y);
        k_2 = dt * f(t + (dt / 2), y + (dt * k_1/2) );
        k_3 = dt * f(t + (dt / 2), y + (dt * k_2/2));
        k_4 = dt * f(t + dt, y + dt * k_3);
        dy = y;
        y += (dt/6)*(k_1+2*k_2+2*k_3+k_4);
        dy = y - dy;
        t += dt;
    }
    this->height = y;
}

void shotingBullet::RungeKuttaDuo(double y, double t, double dt){// expands on the Runge Kutta
    double k_1, k_2, k_3, k_4;
    double kk_1, kk_2, kk_3, kk_4;
    double v=this->v_0, dv=this->v_0, dy;
    if(v < 0){
        std::cerr << "velocity cannot be negative" << std::endl;
        return;
    }
    // calculate the bullet going up
    do{
        // for the height y, Runge Kutta
        k_1 = dt*f(t,y);
        k_2 = dt*f(t + (dt/2), y + (dt*k_1/2) );
        k_3 = dt*f(t + (dt/2), y + (dt*k_2/2));
        k_4 = dt*f(t + dt, y + dt*k_3);
        dy = y;
        y += (dt/6)*(k_1+2*k_2+2*k_3+k_4);
        dy = y - dy;// the value of the change in y
        t += dt;// the value of the change in t
        // for the velocity v, Runge Kutta
        kk_1 = dy*f(y,v);
        kk_2 = dy*f(y + (dy/2), v + (dy*kk_1/2) );
        kk_3 = dy*f(y + (dy/2), v + (dy*kk_2/2));
        kk_4 = dy*f(y + dy, v + dy*kk_3);
        dv = v;
        v += (dy/6) * (kk_1+2*kk_2+2*kk_3+kk_4);
        dv = v - dv;// the value of the change in v
    }while(dv >= 0);
    // once the change in velocity has reached 0 or below, the max height has been reached
    this->height = y;

    //calculate the bullet falling
    double x = y, dx;
    do{
        //Runge Kutta
        k_1 = dt* g(t, x);
        k_2 = dt * g(t + (dt/2), x + (dt*k_1/2));
        k_3 = dt * g(t + (dt/2), x + (dt*k_2/2));
        k_4 = dt * g(t + dt, x + dt*3);
        dx = x;
        x += (dt/6)*(k_1+2*k_2+2*k_3+k_4);
        dx = x - dt;
        t += dt;
        //Runge Kutta again
        kk_1 = dx*g(x, v);
        kk_2 = dx*g(x + (dx/2), v + (dx*kk_1/2));
        kk_3 = dx*g(x + (dx/2), v + (dx*kk_2/2));
        kk_4 = dx*g(x + dx, v + dx*kk_3);
        dv = v;
        v += (dx/6) * (kk_1+2*kk_2+2*kk_3+kk_4);
        dv = v - dv;// change in v
    }while(x > 0);
    this->timeTot = t;
}

#endif // SHOTINGBULLET_H_INCLUDED
