#include "numdisp.hpp"
#include "graphics.hpp"

using namespace genv;

Numdisp::Numdisp(int _x, int _y, int _sx, int _sy, int _nummax) : Widget(_x, _y, _sx, _sy)
{
    elozonum = 0;
    num = 0;
    nyilsx = 30;
    nyilsy = sy/2-8;
    nyilkoordx = x+sx-6;
    nyilkoordy = y+sy/2;
    nummax = _nummax;
    betumeret = sy-2;
};

void Numdisp::kirajzol(event ev)
{
    posxy(ev);
    keret();
    fokuszf(ev);
    fokuszkeret();
    alap();
    numchange(ev);
    valtozasf();
    szamkiir();
    nyilfel(ev);
    nyille(ev);
}

int Numdisp::visszaadintvalt()
{
    if(valtozas)
        return num;
    else
        return 9999;
}

int Numdisp::visszaadint()
{
    return num;
}

void Numdisp::valtozasf()
{
    if(elozonum!=num)
        valtozas=true;
    else
        valtozas=false;
}

void Numdisp::szamkiir()
{
    gout<<font("LiberationSans-Regular.ttf",betumeret);
    gout<<move_to(x+5,y+sy/2-(gout.cascent()+gout.cdescent())/2);
    gout<<color(0,0,0)<<text(std::to_string(num));
}

void Numdisp::alap()
{
    gout<<move_to(x,y)<<color(0,255,255)<<box(sx,sy);
}

void Numdisp::keret()
{
    gout<<move_to(x-2, y-2)<<color(255,255,100)<<box(sx+2*2, sy+2*2);
}

void Numdisp::nyilfel(event ev)
{
    if(kattintfel(ev))
        gout<<move_to(nyilkoordx+3, nyilkoordy)<<color(255,0,0)<<box(-nyilsx-6, -nyilsy-6);
    gout<<move_to(nyilkoordx, nyilkoordy-3);
    gout<<color(255,255,0)<<box(-nyilsx,-nyilsy);
    haromszogfel();
    if(!kattintfel(ev))
        gout<<color(0,0,0)<<move_to(nyilkoordx, nyilkoordy-3)<<line(0,-nyilsy)<<line(-nyilsx,0)<<line(0,nyilsy)<<line(nyilsx,0);

}

void Numdisp::nyille(event ev)
{
    if(kattintle(ev))
        gout<<move_to(nyilkoordx+3, nyilkoordy)<<color(255,0,0)<<box(-nyilsx-6, nyilsy+6);
    gout<<move_to(nyilkoordx, nyilkoordy+3);
    gout<<color(255,255,0)<<box(-nyilsx,nyilsy);
    haromszogle();
    if(!kattintle(ev))
        gout<<color(0,0,0)<<move_to(nyilkoordx, nyilkoordy+3)<<line(0,nyilsy)<<line(-nyilsx,0)<<line(0,-nyilsy)<<line(nyilsx,0);
}

void Numdisp::haromszogfel()
{
    gout<<move_to(nyilkoordx-5, nyilkoordy-3-5)<<color(0,0,0)<<line(-nyilsx/2+5, -nyilsy+2*5);
    gout<<line(-nyilsx/2+5, nyilsy-2*5);
    gout<<line(nyilsx-2*6,0);
}

void Numdisp::haromszogle()
{
    gout<<move_to(nyilkoordx-5, nyilkoordy+3+5)<<color(0,0,0)<<line(-nyilsx/2+5, nyilsy-2*5);
    gout<<line(-nyilsx/2+5, -nyilsy+2*5);
    gout<<line(nyilsx-2*6,0);
}

bool Numdisp::kattintfel(event ev)
{
    bool ih=false;
    if(mx>nyilkoordx-nyilsx && mx<nyilkoordx && my<nyilkoordy-3 && my>nyilkoordy-nyilsy-3 && ev.button==btn_left)
        ih=true;
    return ih;
}

bool Numdisp::kattintle(event ev)
{
    bool ih=false;
    if(mx>nyilkoordx-nyilsx && mx<nyilkoordx && my>nyilkoordy+3 && my<nyilkoordy+nyilsy+3 && ev.button==btn_left)
        ih=true;
    return ih;
}

void Numdisp::numchange(event ev)
{
    elozonum=num;
    if(mx>nyilkoordx-nyilsx && mx<nyilkoordx && fokusz)
    {
        if(my<nyilkoordy-3 && my>nyilkoordy-nyilsy-3 && ev.button==btn_left && num<nummax)
            num++;
        if(my>nyilkoordy+3 && my<nyilkoordy+nyilsy+3 && ev.button==btn_left && num>-nummax)
            num--;
    }
    if(ev.keycode==key_up && num<nummax && fokusz)
        num++;
    if(ev.keycode==key_down && num>-nummax && fokusz)
        num--;
    if(ev.keycode==key_pgup && num+10<=nummax && fokusz)
        num+=10;
    if(ev.keycode==key_pgdn && num-10>=-nummax && fokusz)
        num-=10;
}


