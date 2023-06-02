#include "autoberlo.hpp"

int main()
{
    const int XX = 800;
    const int YY = 600;
    Autoberlo* autoberlo = new Autoberlo(XX,YY);
    autoberlo->master();
    delete autoberlo;
}
