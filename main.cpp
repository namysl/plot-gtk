#include <iostream>
#include <sstream>
#include <string>

#include "mathfunctions.h"
#include "drawplot.h"
#include "linearequations.h"

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define BOLDWHITE "\033[1m\033[37m"

using namespace std;

void available_options();
void linear_fun();
void quadratic_fun();
void binomial_dist();
void linear_eq();

int main(){
	int picked;	
	
	available_options();
	
	while (true){
		cout << GREEN << "Wybierz: " << RESET;
		cin >> picked; 
		
		switch(picked){
			case 0:
				available_options();
				break;
			case 1:
				linear_fun();
				break;
			case 2:
				quadratic_fun();
				break;
			case 3:
				binomial_dist();
				break;
			case 4:
				linear_eq();
				break;
			case 5:
				return 0;
			default:
				cout << RED << "Brak takiej opcji." << RESET << endl;
				cout << "Wybierz 0, żeby sprawdzić dostępne funkcje programu.\n" << endl;
		}
	}
}


void available_options(){
	cout << "0: Dostępne funkcje" << endl;
	cout << "1: Wykres funkcji liniowej" << endl;
	cout << "2: Wykres funkcji kwadratowej" << endl;
	cout << "3: Wykres rozkładu dwumianowego" << endl;
	cout << "4: Obliczanie równania liniowego" << endl;
	cout << "5: Wyjście\n" << endl;
}


void linear_fun(){
	float a, b, x_min, x_max, jump;
	
	cout << BOLDWHITE << "Funkcja liniowa" << RESET << endl;
	
    cout << "Współczynnik kierunkowy (a): ";
    cin >> a;
    cout << "Wyraz wolny (b): ";
    cin >> b;
    cout << "Dolny zakres na osi x: ";
    cin >> x_min;
    cout << "Górny zakres na osi x: ";
    cin >> x_max;
    cout << "Wielkość kroku: ";
    cin >> jump;
    
    LinearFunction liniowa(a, b, x_min, x_max, jump);
	
	float *lista = liniowa.wynik();
	int ilosc = liniowa.ilosc+1;
	plotargs plot(ilosc);
	plot.importval(lista, ilosc);
	plot.draw();
}


void quadratic_fun(){
	float a, b, c, x_min, x_max, jump;

	cout << BOLDWHITE << "Funkcja kwadratowa" << RESET << endl;
	
	cout << "Wartość a: ";
    cin >> a;
    cout << "Wartość b: ";
    cin >> b;
    cout << "Wartość c: ";
    cin >> c;
    cout << "Dolny zakres na osi x: ";
    cin >> x_min;
    cout << "Górny zakres na osi x: ";
    cin >> x_max;
    cout << "Wielkość kroku: ";
    cin >> jump;

    QuadraticFunction kwadratowa(a, b, c, x_min, x_max, jump);

	float *lista = kwadratowa.wynik();
	int ilosc = kwadratowa.ilosc+1;
	plotargs plot(ilosc);
	plot.importval(lista, ilosc);
	plot.draw();
}


void binomial_dist(){
    long int n;
	long double p;
	
	cout << BOLDWHITE << "Rozkład dwumianowy" << RESET << endl;
    
    cout << "Liczba prób (n): ";
    cin >> n;
    cout << "Prawdopodobieństwo sukcesu w próbie (p): ";
    cin >> p;

    BinomialDistribution dwumianowe(n, p);
    
	long double *lista = dwumianowe.wynik();
	n = dwumianowe.n+1;
	plotargs plot(n);
	plot.importval(lista, n);
	plot.draw();
}


void linear_eq(){
	int ilosc;
    double* wyniki;
    char* znaki;
    string str;
    
    cout << BOLDWHITE << "Równanie liniowe" << RESET << endl;

	cin >> str; // 2x-y=2\ny=2
	
    Rownania rownania(str, true);
    ilosc = rownania.getIlosc();
    wyniki = rownania.getWyniki();
    znaki = rownania.getZnaki();

    for(int i=0; i < ilosc; i++){
        cout << znaki[i] << " = " << wyniki[i] << endl;
    }
}

