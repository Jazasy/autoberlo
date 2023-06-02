#ifndef NUMDISP_HPP_INCLUDED
#define NUMDISP_HPP_INCLUDED
#include "widget.hpp"
#include "graphics.hpp"

class Numdisp : public Widget
{
private:
    int elozonum;
    int num;
    int nummax;
    int nyilsx;
    int nyilsy;
    int nyilkoordx;
    int nyilkoordy;
public:
    Numdisp(int _x, int _y, int _sx, int _sy, int _nummax);
    void kirajzol(genv::event ev);
    void nyilfel(genv::event ev);
    void nyille(genv::event ev);
    void numchange(genv::event ev);
    void keret();
    bool kattintfel(genv::event ev);
    bool kattintle(genv::event ev);
    void alap();
    void szamkiir();
    void haromszogfel();
    void haromszogle();
    int visszaadint();
    int visszaadintvalt();
    void valtozasf();

};



#endif // NUMDISP_HPP_INCLUDED
