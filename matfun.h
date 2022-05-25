#ifndef MATFUN_H_INCLUDED
#define MATFUN_H_INCLUDED
#endif

#include <iostream>
using namespace std;

/*
    Klasy potzebują podania parametrów np. dla liniowej a i b, zakresu x (x_min,x_max) i kroku dla x
    Zwracana jest tablica ze złączonymi x i y a ich odczytanie objaśnione jest poniżej - patrz disclaimer
*/

class LinearFunction{
    public:
        float a,b,x_min,x_max,jump;
        int ilosc;
        float *lista;
        
        LinearFunction(float pa, float pb, float px_min, float px_max, float pjump){
            this->a = pa;
            this->b = pb;
            this->x_min = px_min;
            this->x_max = px_max;
            this->jump = pjump;
        }
        
        float* wynik(){
            int i=0;
            ilosc = (x_max-x_min)/jump; //ile wartosci x i y bedzie
            lista = new float[2*ilosc+2]; //Dwie zmienne - jedna tablica ... xd
            float y;
            float x = x_min; //pierwsze x to podane minimum
            while(x <= x_max){ //petla az x nie wyjdzie ponad max
                y = a*x + b; // y=ax+b
                lista[2*i] = x; //przypisanie x
                lista[2*i+1] = y; //przypisanie y
                x+=jump;
                i++;
                
            }
            return lista; 
            
            /* Disclaimer: lista jest jednowymiarowa więc: 
               Parzyste indexy {0,2,4...} to wartości x
               Nieparzyste indexy {1,3,5...} to wartości y
            */   
        }
        
        void wypisz(){
            cout<<"ilosc: "<<ilosc<<endl;
            for(int i=0; i<2*ilosc+2; i+=2){
                cout<<"x: "<<lista[i]<<" | y: "<<lista[i+1]<<endl;
            }
        }
};



