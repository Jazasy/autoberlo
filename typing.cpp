#include "typing.hpp"
#include "graphics.hpp"
#include <string>
#include <iostream>

using namespace genv;

Typing::Typing(int _x, int _y, int _sx, int _sy) : Widget(_x, _y, _sx, _sy)
{
    betumeret = sy-10;
    kurzorx = x+10;
    kurzory = y+sy-((sy-betumeret)/2);
    szoveg = "";
}

void Typing::kirajzol(event ev)
{
    posxy(ev);
    keret();
    fokuszf(ev);
    fokuszkeret();
    alap();
    kurzor(ev);
    type(ev);
    valtozasf();
    meghivasszamlalo+=1;
}

void Typing::alap()
{
    gout<<move_to(x,y)<<color(255,255,170)<<box(sx,sy);
}

void Typing::keret()
{
    gout<<move_to(x-2, y-2)<<color(0,150,255)<<box(sx+2*2, sy+2*2);
}

void Typing::kurzor(event ev)
{
    if(ev.type!=ev_mouse && ev.type!=ev_key)
    {
        gin.timer(300);
        if(fokusz && meghivasszamlalo%2==0)
            gout<<move_to(kurzorx, kurzory)<<color(0,0,0)<<line(0,-betumeret);
    }
}

void Typing::type(event ev)
{
    gout<<font("LiberationSans-Regular.ttf",betumeret);
    if(fokusz)
    {
        elozoszoveg=szoveg;
        szoveg+=ev.keyutf8;
        gout<<move_to(x+10, y)<<color(0,150,255)<<text(szoveg);
        kurzorx=x+10+gout.twidth(szoveg);
        torol(ev);
    }
    gout<<move_to(x+10, y)<<color(0,150,255)<<text(szoveg);
}

void Typing::torol(event ev)
{
    if(ev.keycode == key_backspace)
    {
        if(szoveg.length()>0)
        {
        szoveg.pop_back();
        kurzorx=x+10+gout.twidth(szoveg);
        }
    }
}

std::string Typing::visszaadstringvalt()
{
    std::string ures = "nincs valtozas :/";
    if(valtozas)
        return szoveg;
    else
        return ures;
}

std::string Typing::visszaadstring()
{
    if(szoveg=="")
        return "";
    return szoveg;
}

void Typing::szovegsetter(std::string _szoveg)
{
    szoveg = _szoveg;
}

void Typing::valtozasf()
{
    if(elozoszoveg!=szoveg)
        valtozas=true;
    else
        valtozas=false;
}

