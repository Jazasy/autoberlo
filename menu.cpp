#include "menu.hpp"
#include "graphics.hpp"
#include <iostream>
#include <vector>
#include <string>

using namespace genv;

Menu::Menu(int _x, int _y, int _sx, int _sy, int _kijelzettsorokszama, std::vector<std::string> _opciok) : Widget(_x, _y, _sx, _sy)
{
    opciok=_opciok;
    kezdoindex = 0;
    kijeloltindex = -1;
    kijelzettsorokszama = _kijelzettsorokszama;
    betumeret=30;//betumeretmeghat();
    sx=sxmeghat();                          // itt a betumeretmeghat és az sx  és sy meghat meglétével lehet játszani azon, hogy mihez igazodjanak a méretek.
    sy=symeghat();
};

void Menu::kirajzol(event ev)
{
    if(opciok.size()!=0)
    {
        posxy(ev);
        keret();
        fokuszf(ev);
        kivalaszt(ev);
        valtozasf();
        fokuszkeret();
        alap();
        gorget(ev);
        szovegkiir();
        sx = sxmeghat();
        sy = symeghat();
    }
}

std::string Menu::visszaadstringvalt()
{
    std::string ures = "nincs valtozas :/";
    if(valtozas)
        return opciok[kijeloltindex];
    else
        return ures;
}

std::string Menu::visszaadstring()
{
    if(kijeloltindex == -1)
        return "nincs kijelolve semmi";
    return opciok[kijeloltindex];
}

void Menu::valtozasf()
{
    if(elozokijeloltindex!=kijeloltindex)
        valtozas=true;
    else
        valtozas=false;
}

void Menu::alap()
{
    gout<<move_to(x,y)<<color(255,255,170)<<box(sx,sy);
}


void Menu::keret()
{
    gout<<move_to(x-2, y-2)<<color(0,150,255)<<box(sx+2*2, sy+2*2);
}

void Menu::vonalak()
{
    if(opciok.size()<kijelzettsorokszama)
    {
        for(int i=1; i<opciok.size(); i++)
        {
            gout<<move_to(x, y+double(sy)/double(opciok.size())*i)<<color(0,150,255)<<box(sx, 2);
        }
    }
    else
    {
        for(int i=1; i<kijelzettsorokszama; i++)
        {
            gout<<move_to(x, y+double(sy)/double(kijelzettsorokszama)*i)<<color(0,150,255)<<box(sx, 2);
        }
    }
}

void Menu::szovegkiir()
{
    gout<<font("LiberationSans-Regular.ttf",betumeret);
    if(opciok.size()<kijelzettsorokszama)
    {
        for(int i=0; i<opciok.size(); i++)
        {
            szovegkijelol(i);
            vonalak();
            gout<<move_to(x+10, y+double(sy)/double(opciok.size())*i)<<color(0,150,255)<<text(opciok[i+kezdoindex]);
        }
    }
    else
    {
        for(int i=0; i<kijelzettsorokszama; i++)
        {
            szovegkijelol(i);
            vonalak();
            gout<<move_to(x+10, y+double(sy)/double(kijelzettsorokszama)*i)<<color(0,150,255)<<text(opciok[i+kezdoindex]);
        }
    }
}

void Menu::szovegkijelol(int i)
{
    if(opciok.size()<kijelzettsorokszama)
    {
        if(i+kezdoindex == kijeloltindex)
        gout<<move_to(x,y+double(sy)/double(opciok.size())*i)<<color(255,255,50)<<box(sx,double(sy)/double(opciok.size()));
    }
    else
    {
        if(i+kezdoindex == kijeloltindex)
            gout<<move_to(x,y+double(sy)/double(kijelzettsorokszama)*i)<<color(255,255,50)<<box(sx,double(sy)/double(kijelzettsorokszama));
    }
}

void Menu::kivalaszt(event ev)
{
    elozokijeloltindex=kijeloltindex;
    if(opciok.size()<kijelzettsorokszama)
    {
        for(int i=0; i<opciok.size(); i++)
    {
        if(mx>x && mx<x+sx && my>y+double(sy)/double(opciok.size())*i && my<y+double(sy)/double(opciok.size())*(i+1) && ev.button == btn_left)
            kijeloltindex=i+kezdoindex;
    }
    }
    else
    {
        for(int i=0; i<kijelzettsorokszama; i++)
        {
            if(mx>x && mx<x+sx && my>y+double(sy)/double(kijelzettsorokszama)*i && my<y+double(sy)/double(kijelzettsorokszama)*(i+1) && ev.button == btn_left)
                kijeloltindex=i+kezdoindex;
        }
    }
}

void Menu::gorget(event ev)
{
    if(opciok.size()>=kijelzettsorokszama)
    {
        if(ev.button==btn_wheelup && kezdoindex!=0 && fokusz)
            kezdoindex--;
        if(ev.button==btn_wheeldown && kezdoindex!=opciok.size()-kijelzettsorokszama && fokusz)
            kezdoindex++;
    }
}

void Menu::opcioksetter(std::vector<std::string> _opciok)
{
    opciok = _opciok;
}

int Menu::kijeloltindexgetter()
{
    return kijeloltindex;
}

void Menu::kijeloltindexsetter(int _kijeloltindex)
{
    kijeloltindex = _kijeloltindex;
}

void Menu::kezdoindexsetter(int _kezdoindex)
{
    kezdoindex = _kezdoindex;
}

int Menu::betumeretmeghat()
{
    int betumeretf=0;
    if(opciok.size()<kijelzettsorokszama)
    {
        betumeretf = double(sy)/double(opciok.size())-3;
    }
    else
    {
        betumeretf = double(sy)/double(kijelzettsorokszama)-3;
    }
    return betumeretf;
}

int Menu::sxmeghat()
{
    gout<<font("LiberationSans-Regular.ttf",betumeret);
    int sxf=0;
    for(std::string s: opciok)
    {
        if(gout.twidth(s)>=sxf)
            sxf=gout.twidth(s);
    }
    if(sxf+20>=sx)
        return sxf+20;
    else
        return sx;
}

int Menu::symeghat()
{
    int syf=0;
    gout<<font("LiberationSans-Regular.ttf",betumeret);
    if(opciok.size()<kijelzettsorokszama)
    {
        if((gout.cascent()+gout.cdescent())*opciok.size()>=syf)
            syf=(gout.cascent()+gout.cdescent()+2)*opciok.size();
    }
    else
    {
        if((gout.cascent()+gout.cdescent())*kijelzettsorokszama>=syf)
            syf=(gout.cascent()+gout.cdescent()+2)*kijelzettsorokszama;
    }
    return syf;
}
