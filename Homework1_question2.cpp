#include <iostream>
#include "RootFindingMethods.h"
#include <cstdlib>
//Anfernee Rodriques
//110025971
int main(void){
    std::cout << "Homework 1, question 2" << std::endl;

    RootFindingMethods method;
    double answer = method.bisection(0, 1, 4);//root = 1.625 recursively and root = 1.50012 iteratively

    std::cout << "The number of iterations for the bisection method is " << method.getIter() << " and the root is " << method.getRoot() << " or " << answer << std::endl;
    //answer = method.newton(2);//when does this method stop???
    //std::cout << "The number of iterations for Newton's method is: " << method.getIter() << " and the root is " << answer << std::endl;

    return EXIT_SUCCESS;
}
