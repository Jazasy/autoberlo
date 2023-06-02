#ifndef MENU_HPP_INCLUDED
#define MENU_HPP_INCLUDED
#include "widget.hpp"
#include "graphics.hpp"
#include <vector>
#include <string>

class Menu : public Widget
{
private:
    std::vector<std::string> opciok;
    int kezdoindex;
    int elozokijeloltindex;
    int kijeloltindex;
    bool felette;
    int kijelzettsorokszama;
public:
    Menu(int _x, int _y, int _sx, int _sy, int _kijelzettsorokszama, std::vector<std::string> _opciok);
    void kirajzol(genv::event ev);
    int sxmeghat();
    int symeghat();
    void keret();
    void vonalak();
    void szovegkiir();
    void gorget(genv::event);
    void szovegkijelol(int i);
    void kivalaszt(genv::event ev);
    void alap();
    std::string visszaadstring();
    std::string visszaadstringvalt();
    void valtozasf();
    int betumeretmeghat();
    void opcioksetter(std::vector<std::string> _opciok);
    int kijeloltindexgetter();
    void kijeloltindexsetter(int _kijeloltindex);
    void kezdoindexsetter(int _kezdoindex);
};


#endif // MENU_HPP_INCLUDED
