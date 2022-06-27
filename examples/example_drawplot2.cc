#include "mathfunctions.h"
#include "drawplot.h"
#include "matplotlibcpp.h"

int main(){
	LinearFunction liniowa(3,4,-5,5,0.0625);//losowa funkcja liniowa
	float *lista = liniowa.wynik();//wyniki w jednej tablicy
	int ilosc = liniowa.ilosc+1;
	plotargs A(ilosc);
	A.importval(lista,ilosc);//nowa metoda
	A.draw();

	QuadraticFunction kwadratowa(2,3,5,-4,4,0.125);
	float *lista2 = kwadratowa.wynik();
	int ilosc2 = kwadratowa.ilosc+1;
	plotargs B(ilosc2);
	B.importval(lista2,ilosc2);
	B.draw();

	BinomialDistribution dwumianowe(10,0.4);
	long double *lista3 = dwumianowe.wynik();
	long int n = dwumianowe.n+1;
	plotargs C(n);
	C.importval(lista3,n);
	C.draw();
}
//g++ newplotexample.cc -std=c++11 -I/usr/include/python2.7 -lpython2.7 -o testplot
