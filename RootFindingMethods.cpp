#include "RootFindingMethods.h"
#include <cmath>
double f(double);
double df(double);
double p(double x){
    return cos(x)/x - sin(x)/pow(x, 2);
}

void swapVal(double&, double&);


RootFindingMethods::RootFindingMethods()
{
    //ctor
}

RootFindingMethods::~RootFindingMethods()
{
    //dtor
}
int RootFindingMethods::getIter(){
    return this->iter;
}
double f(double x){
    //return pow(2.018, pow(-x,3))-pow(x,4)*sin(pow(x,3))-1.984;
    double result = pow(2.018, pow(-x, 3));
    result -= pow(x, 4)*sin(pow(x,3));
    result -= 1.984;
    return result;
}
double df(double x){
    return -2.10632*pow(2.018, pow(-x, 3))*pow(x,2) - 4*pow(x,3)*sin(pow(x,3)) - 3*pow(x,6)*cos(pow(x,3));
}
//finding roots
double RootFindingMethods::bisection(double x1, double x2, int sigfig){
    this->iter = 0;
    double fx1 = f(x1);
    double fx2 = f(x2);
    if(fx1==0) return x1; if(fx2==0) return x2;
    if(fx1*fx2 > 0) return 0;//error
    if(fx1>0){
        double temp = x1;
        x1 = x2;
        x2 = temp;
    }
    return bisect_rec(x1, x2, pow(10, -sigfig));//uses recursive method
}
double RootFindingMethods::bisect_rec(double x1, double x2, double eps){//helper methhod
    double mid = (x1+x2)/2;
    if( fabs(x1-x2) <eps ){
        this->root = mid;
        return mid;
    }
    double fx3 = f(mid);
    if(fx3 > 0){
        iterate();
        return bisect_rec(x1, mid, eps);
    }else if(fx3 < 0){
        iterate();
        return bisect_rec(mid, x2, eps);
    }
    return mid;
}
double RootFindingMethods::bisect_loop(double x1, double x2, double eps){//helper method
    double mid;
    double fx3;
    while( fabs(x1-x2)>eps){
        iterate();
        mid = (x1+x2)/2;
        fx3 = f(mid);
        if( fabs(mid-x1)<eps ){
            break;
        }else if(fx3>0){
            swapVal(mid, x2);
        }else{
            swapVal(mid, x1);
        }
    }
    this->root = mid;
    return mid;
}
double RootFindingMethods::newton(double x, int eps){
    this->iter = 0;
    double fx;
    do{
        fx = f(x);
        x-= (fx/df(x));
    }while(fx!=0);
    return x;
}
void RootFindingMethods::iterate(){
    this->iter++;
}
void swapVal(double &a, double &b){
    double temp = a;
    a = b;
    b = temp;
}
double RootFindingMethods::getRoot(){
    return this->root;
}
