#include <iostream>
#include "../mathfunctions.h"
using namespace std;

int main()
{
    cout<<"Test funkcji liniowej"<<endl;
    float a,b,c,x_min,x_max,jump;
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
    
    cout<<"\n===================="<<endl;
    cout<<"\nTest funkcji kwadratowej"<<endl;
    cout<<"Podaj a: ";
    cin>>a;
    cout<<"Podaj b: ";
    cin>>b;
    cout<<"Podaj c: ";
    cin>>c;
    cout<<"Podaj dolny zakres x: ";
    cin>>x_min;
    cout<<"Podaj górny zakres x: ";
    cin>>x_max;
    cout<<"Podaj wielkość kroku: ";
    cin>>jump;
    QuadraticFunction kwadratowa(a,b,c,x_min,x_max,jump);
  
    kwadratowa.wynik();
    kwadratowa.wypisz();
    
    cout<<"\n===================="<<endl;
    cout<<"\nTest rozkladu dwimianowego"<<endl;
    long double p;
    long int n;
    cout<<"Podaj liczbe prob: ";
    cin>>n;
    cout<<"Podaj prawdopodobienstwo sukcesu: ";
    cin>>p;

    BinomialDistribution dwumianowe(n,p);
  
    dwumianowe.wynik();
    dwumianowe.wypisz();
    
   
    return 0;
}
