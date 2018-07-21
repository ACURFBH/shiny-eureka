#include "NormalDistr.h"
#include "RiverCrossing.h"

int main(void)
{
    // PART 1
    NormalDistr nd1(1000000, 0.001949, 0.002018);
    //NormalDistr nd2(1000000, -0.001989, 0.006464);
    nd1.graph(260);
    std::cout << "After 260 trading days the portfolio value is " << nd1.get_t() << " for graph 1" << std::endl;
    //nd2.graph();
    //cout << "After 260 trading days the portfolio value is " << nd1.get_t() << " for graph 1" << endl;

    // PART 3
    RiverCrossing rc1(1000, 5, 10);
    //RiverCrossing rc2(1000, 10, 10);
    //RiverCrossing rc3(1000, 15, 10);
    rc1.graph();
    //rc2.graph();
    //rc3.graph();

    return 0;
}
