#ifndef AUTOBERLO_HPP_INCLUDED
#define AUTOBERLO_HPP_INCLUDED
#include "widget.hpp"
#include "graphics.hpp"
#include "menu.hpp"
#include "typing.hpp"
#include "gomb.hpp"
#include <vector>
#include <string>

class Autoberlo
{
    int XX;
    int YY;
    genv::event ev;
    std::vector<Widget*> appelemek;
    std::vector<std::string> autokvektor;
    std::vector<std::string> kibereltautopluszberlonevvektor;
    std::vector<std::string> ugyfelekvektor;
    Menu* autok;
    Menu* ugyfelek;
    Menu* kibereltautopluszberlonev;
    Typing* gepelobox;
    Gomb* berlogomb;
    Gomb* visszahozgomb;
    Gomb* hozzaadgomb;
public:
    Autoberlo(int _XX, int _YY);
    ~Autoberlo();
    void master();
    void ablak();
    void appeventloop();
};

#endif // AUTOBERLO_HPP_INCLUDED
