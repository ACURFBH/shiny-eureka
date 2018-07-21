#include "predatorPrey.h"
#include "shotingBullet.h"
#include "newtonLawOfCooling.h"
#include <iostream>
using namespace std;
int main(void){
    std::cout << "assignment 3" << std::endl;
    newtonLawOfCooling nlc;// call the default constructor
    shotingBullet sb;// call the default constructor
    predatorPrey pp;// call the default constructor

    // each default constructor has the initial values of the problems from the assignment
    // #3.1
    std::cout << "\n\n3.1" << std::endl;
    std::cout << "the bullet was in the air for "<< sb.get_air_time() << " minutes, traveling a total distance of " << (2 * sb.get_height()) << std::endl;

    // #3.2
    std::cout << "\n3.2" << std::endl;
    std::cout << "The person died " << nlc.getTimeOfDeath() << " minutes before being found" << std::endl;// result is 0, cuz it calculates h_0 - h_0
    std::cout << "The corpse temperature will reach " << 44.44 << " after " << nlc.timeAtTemp(44.44) << " minutes" << std::endl;

    // #3.3
    std::cout << "\n3.3" << std::endl;
    std::cout << "The stock value at t = " << 11 << " is " << pp.stockAt(11) << std::endl;// result infinite
    std::cout << "The first instance the y is greater than x is when t = " << pp.get_t_when_y_is_greater_than_x() << std::endl;

    return 0;

}
