#include "RiverCrossing.h"
#include <iostream>
#include <cmath>
#include <fstream>

RiverCrossing::RiverCrossing(double riverWidth, double initialVelocity, double boatSpeed)
:a(riverWidth), v_0(initialVelocity), v_b(boatSpeed)
{
    //ctor
    RiverCrossing::dt = 0.0025
}

RiverCrossing::~RiverCrossing()
{
    //dtor
}

void RiverCrossing::graph(std::string filename)
{
    filename.append(".csv");
    std::ofstream myFile(filename);
    double x = a, y = 0, t = 0;
    double dx, dy;
    do{
        dx = v_b*f(x,y) * dt;
        dy = (v_b * f(y,x) * dt) + w(x);
        std::cout << "(" << x << "," << y << ")" << std::endl;
        myFile << "(" << x << "," << y << ")" << std::endl;
        y += dy;
        x -= dx;// moving left on the x axis
        t += dt;
    }while(x > 0);
}

double RiverCrossing::f(double x, double y)
{
    if(x*y <= 0) return 0;
    return x / sqrt(pow(x,2) + pow(y,2));
}

double RiverCrossing::w(double x)
{
    return 4 * v_0 * (x/a) * (1 - (x/a));
}
