#ifndef MATFUN_H_INCLUDED
#define MATFUN_H_INCLUDED
#endif

#include <iostream>
#include <cmath>
#include <string>
using namespace std;

/*
    Klasy potzebują podania parametrów np. dla liniowej a i b, zakresu x (x_min,x_max) i kroku dla x
    Zwracana jest tablica ze złączonymi x i y a ich odczytanie objaśnione jest poniżej - patrz disclaimer
*/

extern "C" {
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
		        if(jump==0){
		            ilosc = 1;
		        }
		        else{
		            ilosc = (x_max-x_min)/abs(jump); //ile wartosci x i y bedzie
		        }
		        lista = new float[2*ilosc+2]; //Dwie zmienne - jedna tablica ... xd
		        float y;
		        float x = x_min; //pierwsze x to podane minimum
		        while(x <= x_max){ //petla az x nie wyjdzie ponad max
		            y = a*x + b; // y=ax+b
		            lista[2*i] = x; //przypisanie x
		            lista[2*i+1] = y; //przypisanie y
		            x+=abs(jump);
		            if(jump == 0){
		                x=x_max+1;
		            }
		            i++;
		            
		        }
		        return lista; 
		        
		        /* Disclaimer: lista jest jednowymiarowa więc: 
		           Parzyste indexy {0,2,4...} to wartości x
		           Nieparzyste indexy {1,3,5...} to wartości y
		        */   
		    }
		    
		    void wypisz(){
		        //cout<<"ilosc: "<<ilosc<<endl;
		        for(int i=0; i<=2*ilosc; i+=2){
		            cout<<"x: "<<lista[i]<<" | y: "<<lista[i+1]<<endl;
		        }
		    }
	};
	
	class QuadraticFunction{
		public:
		    float a,b,c,x_min,x_max,jump;
		    int ilosc;
		    float *lista;
		    
		    QuadraticFunction(float pa, float pb, float pc, float px_min, float px_max, float pjump){
		        this->a = pa;
		        this->b = pb;
		        this->c = pc;
		        this->x_min = px_min;
		        this->x_max = px_max;
		        this->jump = pjump;
		    }
		    
		    float* wynik(){
		        int i=0;
		        if(jump==0){
		            ilosc = 1;
		        }
		        else{
		            ilosc = (x_max-x_min)/ jump; //ile wartosci x i y bedzie
		        }
		        lista = new float[2*ilosc+2]; //Dwie zmienne - jedna tablica ... xd
		        float y;
		        float x = x_min; //pierwsze x to podane minimum
		        while(x <= x_max){ //petla az x nie wyjdzie ponad max
		            y = a*(x*x) + b*x + c; // y=ax+b
		            lista[2*i] = x; //przypisanie x
		            lista[2*i+1] = y; //przypisanie y
		            x+=jump;
		            if(jump == 0){
		                x=x_max+1;
		            }
		            i++;
		            
		        }
		        return lista; 
		    }
		    
		    void wypisz(){
		        //cout<<"ilosc: "<<ilosc<<endl;
		        for(int i=0; i<=2*ilosc; i+=2){
		            cout<<"x: "<<lista[i]<<" | y: "<<lista[i+1]<<endl;
		        }
		    }
	};


//Rozklad prawdopodobienstwa opisujacy liczbe sukcesow w podanych probach o danym prawdopodobienstwie sukcesu
//Tutaj x to ilosc sukcesow a y to prawdopodobienstwa wystopienia danej liczby sukcesow w n-probach
	class BinomialDistribution{
		public:
			long int n;
		    long double p;
		    long double *lista;
		    
		    BinomialDistribution(long int pn, long double pp){
		        this->n = pn; //ilosc prob
		        this->p = pp; //prawdopodobienstwo sukcesu
		    }
		    
		    long double* wynik(){
		        int i=0;
		        lista = new long double[2*n+2]; 
		        long double y;
		        long int x = 0; 
		        while(x <= n){ 
		            y = newton(n,x) * pow(p,x) * pow((1-p),n-x);
		            //cout<<newton(n,x)<<" "<<pow(p,x)<<" "<<pow((1-p),n-x)<<endl;
		            lista[2*i] = x; //przypisanie x
		            lista[2*i+1] = y; //przypisanie y
		            x++;
		            i++;
		            
		        }
		        return lista; 
		    }
		    
		    long int silnia(int n){
		        if((n==0)||(n==1))
		        return 1;
		        else
		        return n*silnia(n-1);
		    }
		    
		    long double newton(int n, int k){
		        long double iloczyn = 1;
		        //cout<<n<<" "<<k<<endl;
		        for(int l=0;l<k;l++){
		            iloczyn*=(long double)(n-l)/(k-l);
		            cout<<iloczyn<<endl;
		        }
		        return iloczyn;
		    }
		    
		    void wypisz(){
		        //cout<<"ilosc: "<<ilosc<<endl;
		        for(long int i=0; i<=2*n; i+=2){
		            cout<<"x: "<<lista[i]<<" | y: "<<lista[i+1]<<endl;
		        }
		    }
		};
}
