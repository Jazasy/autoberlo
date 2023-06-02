#include "widget.hpp"
#include "graphics.hpp"

Widget::Widget(int _x, int _y, int _sx, int _sy) : x(_x), y(_y), sx(_sx), sy(_sy) {fokusz=false;};

void Widget::kirajzol(genv::event ev){}

int Widget::visszaadint(){return 9999;}

std::string Widget::visszaadstring(){return "nem string widget";}

bool Widget::visszaadbool(){return fokusz;}

void Widget::posxy(genv::event ev)
{
    mx=ev.pos_x;
    my=ev.pos_y;
}

void Widget::fokuszf(genv::event ev)
{
    if(mx>x && mx<x+sx && my>y && my<y+sy && ev.button == genv::btn_left)
        fokusz = true;
    if((mx<x || mx>x+sx || my<y || my>y+sy) && ev.button == genv::btn_left)
        fokusz = false;
}

void Widget::fokuszkeret()
{
    if(fokusz)
        genv::gout<<genv::move_to(x-3, y-3)<<genv::color(255,0,0)<<genv::box(sx+2*3, sy+2*3);
    if(!fokusz)
    {
        genv::gout<<genv::move_to(x-3, y-3)<<genv::color(0,0,0)<<genv::box(sx+2*3, sy+2*3);
        keret();
    }
}

void Widget::keret(){}
