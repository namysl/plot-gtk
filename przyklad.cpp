#include <iostream>
#include <sstream>
#include "rownania.h"
using namespace std;

int main()
{
    int ilosc;
    cout<<"Ile linijek ma twoje rownanie? ";
    cin>>ilosc;
    Rownania rownania(ilosc);
    rownania.pokaz();
    rownania.rozwiaz();
    rownania.pokaz();
    return 0;
}
