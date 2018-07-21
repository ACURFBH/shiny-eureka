#include "Problem.h"
#include "math.h"
Problem::Problem()
{
    //ctor
}

Problem::~Problem()
{
    //dtor
}
double f(double x){
   return cos(x)/x - sin(x)/pow(x, 2);
}
double bisect_rec(double a, double b, double e){
    double c = (a+b)/2;//midpoint
    if(abs(a-b)<e) return c;
    double fc = f(c);
    if(fc == 0) return c;
    else if(fc<0) return  bisect_rec(a,c,e);
    else return bisect_rec(c,b,e);
}
double bisection_method(double a, double b){
    double fa = f(a),fb = f(b);
    if(fa == 0) return a; if(fb == 0) return b;
    if(fa*fb>0) return 0;
    if(fa>0){
        double temp = a;
        a = b;
        b = temp;
    }
    bisect_rec(a, b, 0.0001);
}


