#include <iostream>
#include "matfun.h"
using namespace std;

int main()
{
    float a,b,x_min,x_max,jump;
    cout<<"Podaj a: ";
    cin>>a;
    cout<<"Podaj b: ";
    cin>>b;
    cout<<"Podaj dolny zakres x: ";
    cin>>x_min;
    cout<<"Podaj górny zakres x: ";
    cin>>x_max;
    cout<<"Podaj wielkość kroku: ";
    cin>>jump;
    LinearFunction liniowa(a,b,x_min,x_max,jump);
  
    liniowa.wynik();
    liniowa.wypisz();
   
    return 0;
}