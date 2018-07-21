#include "NormalDistr.h"
#include <random>// gives access to using the normal distribution
#include <iostream>
#include <fstream>// give access to file stream
using namespace std;

NormalDistr::NormalDistr(double init, double mu, double s)// standard normal distribution has mean = 0 and standard distribution = 1
:investment(init) ,mean(mu),sd(s)
{
    t = 0;
    y = init;
}

NormalDistr::NormalDistr(NormalDistr& nd)// copy constructor
{
    setInvestment(nd.investment);
    setMean(nd.mean);
    setSd(nd.sd);
}

NormalDistr::~NormalDistr()// destructor
{
    //dtor
}

/** \brief generates a normally distributed random variable given the classes mean and standard deviation
 *
 * \param no parameters
 * @param none
 * \return normally distributed random variable
 *
 */
double NormalDistr::N()// Normal distribution
{
    default_random_engine generator;
    normal_distribution<double> x(mean, sd);
    return x(generator);
}

/** \brief print all the points of a graph that would be used to plot a graph
 *
 * \param amount of time that passes
 *
 * \return no return
 *
 */
void NormalDistr::graph(int timer)// output to console the points of the graph
{
    t = 0;
    double x = 0;
    y = investment;
    while(t < timer){
        cout << "(" << t << "," << y << ")" << endl;
        t+=1;
        x = N();
        y += x;// investment value changes as time time passes
        if(x>0) y -= (y * 0.003333);// these people take 0.3333% of the total investment if investment increases
    }
}

/** \brief the rate of change of the graph is normally distributed
 *
 * \param amount of time t that has passed
 *
 * \return investment value at time t
 *
 */
double NormalDistr::f(int timer)// just give the possible value at the point
{
    t = 0;// time that will pass
    double x = 0;// normally distributed random variable
    double y = investment;// investment value as time passes
    while(t < timer){
        t+=1;
        x = N();
        y += x;// investment value changes as time passes
        if(x>0) y -= (y * 0.003333);// these people take 0.3333% of the total investment if investment increases
    }
    return y;
}

void NormalDistr::setMean(double m)
{
    mean = m;
}

void NormalDistr::setSd(double s)
{
    sd = s;
}

void NormalDistr::setInvestment(double i)
{
    investment = i;
}

ostream& operator<<(ostream& out, NormalDistr& norm)
{
    out << "(" << norm.t << "," << norm.y << ")";
    return out;
}

void NormalDistr::writeToCSV(string filename, int timer)// write all points to a file, for graphing
{
    // open the file with the given file name
    filename.append(".csv");
    ofstream myFile;
    myFile.open(filename);
    if(!myFile.is_open()){// exit if there is any problem
        cerr << "file unavailable" << endl;
        return;
    }
    myFile << "time,value" << endl;// write the top line of the CSV file
    // do the same thing as the graph() function, but write to the file also
    t = 0;
    double x = 0;
    y = investment;
    while(t < timer){
        cout << "(" << t << "," << y << ")" << endl;// to console
        myFile << t << "," << y << endl;// to file
        t+=1;
        x = N();
        y += x;// investment value changes as time time passes
        if(x>0) y -= (y * 0.003333);// these people take 0.3333% of the total investment if investment increases
    }
    myFile.close();
}

int NormalDistr::get_t()
{
    return t;
}
