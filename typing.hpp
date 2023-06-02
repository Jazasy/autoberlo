#ifndef TYPING_HPP_INCLUDED
#define TYPING_HPP_INCLUDED
#include "widget.hpp"
#include "graphics.hpp"

class Typing : public Widget
{
    int kurzorx;
    int kurzory;
    std::string szoveg;
    std::string elozoszoveg;
    int meghivasszamlalo;
public:
    Typing(int _x, int _y, int _sx, int _sy);
    void kirajzol(genv::event ev);
    void alap();
    void keret();
    void kurzor(genv::event ev);
    void type(genv::event ev);
    void torol(genv::event ev);
    std::string visszaadstringvalt();
    std::string visszaadstring();
    void valtozasf();
    void szovegsetter(std::string _szoveg);
};


#endif // TYPING_HPP_INCLUDED
