#ifndef WIDGET_HPP_INCLUDED
#define WIDGET_HPP_INCLUDED
#include "graphics.hpp"

class Widget
{
protected:
    int mx;
    int my;
    int x;
    int y;
    int sx;
    int sy;
    int betumeret;
    bool fokusz;
    bool valtozas;
public:
    Widget(int _x, int _y, int _sx, int _sy);
    virtual void kirajzol(genv::event ev);
    virtual int visszaadint() ;
    virtual std::string visszaadstring();
    virtual bool visszaadbool();
    virtual void keret();
    void posxy(genv::event ev);
    void fokuszf(genv::event ev);
    void fokuszkeret();
};

#endif // WIDGET_HPP_INCLUDED
