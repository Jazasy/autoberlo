#include "autoberlo.hpp"
#include "graphics.hpp"
#include "widget.hpp"
#include "menu.hpp"
#include "typing.hpp"
#include "gomb.hpp"
#include <vector>
#include <string>
#include <iostream>

Autoberlo::Autoberlo(int _XX, int _YY) : XX(_XX), YY(_YY)
{
   autokvektor = {"VW Golf", "VW Passat", "Opel Astra", "Suzuki Swift", "Fiat Punto", "Seat Ibiza", "Toyota Hi-Ace", "Opel Grandland"};
   autok = new Menu(10, 10, 200, 200, 7, autokvektor);
   kibereltautopluszberlonevvektor = {};
   kibereltautopluszberlonev = new Menu(XX-410, 10, 400, 10, 6, kibereltautopluszberlonevvektor);
   ugyfelekvektor = {};
   ugyfelek = new Menu(10, YY/2, 200, 200, 6, ugyfelekvektor);
   gepelobox = new Typing(10, YY-60, 400, 50);
   hozzaadgomb = new Gomb(420, YY-60, 50, 50, "+");
   berlogomb = new Gomb(XX-160-10-100, YY-60, 100, 50, "berel");
   visszahozgomb = new Gomb(XX-160, YY-60, 150, 50, "visszahoz");
   appelemek.push_back(autok);
   appelemek.push_back(kibereltautopluszberlonev);
   appelemek.push_back(ugyfelek);
   appelemek.push_back(gepelobox);
   appelemek.push_back(berlogomb);
   appelemek.push_back(hozzaadgomb);
   appelemek.push_back(visszahozgomb);
}

Autoberlo::~Autoberlo()
{
   delete autok;
   delete ugyfelek;
   delete kibereltautopluszberlonev;
   delete gepelobox;
   delete berlogomb;
   delete visszahozgomb;
   delete hozzaadgomb;
}

void Autoberlo::master()
{
    ablak();
    appeventloop();
}

void Autoberlo::ablak()
{
    genv::gout.open(XX,YY);
}

void Autoberlo::appeventloop()
{
    for(Widget* wi : appelemek)
        wi->kirajzol(ev);
    genv::gout<<genv::refresh;
    while(genv::gin>>ev && ev.keycode != genv::key_escape)
    {
        genv::gout<<genv::move_to(0,0)<<genv::color(0,0,0)<<genv::box(XX,YY);
        for(Widget * wi : appelemek)
        {
            wi->kirajzol(ev);
        }
        if((hozzaadgomb->visszaadbool() || ev.keycode == genv::key_enter) && gepelobox->visszaadstring() != "")
        {
            ugyfelekvektor.push_back(gepelobox->visszaadstring());
            ugyfelek->opcioksetter(ugyfelekvektor);
            gepelobox->szovegsetter("");
        }
        if(berlogomb->visszaadbool() && ugyfelek->kijeloltindexgetter() != -1 && autok->kijeloltindexgetter() != -1)
        {
            kibereltautopluszberlonevvektor.push_back(ugyfelekvektor[ugyfelek->kijeloltindexgetter()]+": "+autokvektor[autok->kijeloltindexgetter()]);
            kibereltautopluszberlonev->opcioksetter(kibereltautopluszberlonevvektor);
            autokvektor.erase(autokvektor.begin() + autok->kijeloltindexgetter());
            ugyfelekvektor.erase(ugyfelekvektor.begin() + ugyfelek->kijeloltindexgetter());
            autok->opcioksetter(autokvektor);
            autok->kijeloltindexsetter(-1);
            autok->kezdoindexsetter(0);
            ugyfelek->opcioksetter(ugyfelekvektor);
            ugyfelek->kijeloltindexsetter(-1);
            ugyfelek->kezdoindexsetter(0);
            gepelobox->szovegsetter("");
        }
        if(visszahozgomb->visszaadbool() && kibereltautopluszberlonev->kijeloltindexgetter() != -1)
        {
            int kettospontindex = kibereltautopluszberlonevvektor[kibereltautopluszberlonev->kijeloltindexgetter()].find(":");
            autokvektor.push_back(kibereltautopluszberlonevvektor[kibereltautopluszberlonev->kijeloltindexgetter()].substr(kettospontindex+2,kibereltautopluszberlonevvektor[kibereltautopluszberlonev->kijeloltindexgetter()].size()));
            ugyfelekvektor.push_back(kibereltautopluszberlonevvektor[kibereltautopluszberlonev->kijeloltindexgetter()].substr(0, kettospontindex));
            kibereltautopluszberlonevvektor.erase(kibereltautopluszberlonevvektor.begin() + kibereltautopluszberlonev->kijeloltindexgetter());
            kibereltautopluszberlonev->opcioksetter(kibereltautopluszberlonevvektor);
            autok->opcioksetter(autokvektor);
            ugyfelek->opcioksetter(ugyfelekvektor);
            kibereltautopluszberlonev->kijeloltindexsetter(-1);
            kibereltautopluszberlonev->kezdoindexsetter(0);
        }
        genv::gout<<genv::refresh;
    }
}
