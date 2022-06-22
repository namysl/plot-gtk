#include <iostream>
#include "drawplot.h"

using namespace std;

int main(){
	//Jeśli nie działa to:
	//1. brakuje pliku matplotlibcpp w tym samym katalogu,
	//2. system nie ma python2.7, wersja ma znaczenie
	//3. powyższy python nie ma biblioteki matplotlib
	int n;
	cout << "Podaj liczbę argumentów wykresu: ";
	cin >> n;
	plotargs A(n);
	A.init();
	A.setcolor('k');
	A.draw();
	plotargs B(4);
	double x[4]{1,2,3,4};
	double y[4]{3,5,6,3};
	int m = 2;
	double nn = 2.5;
	double step = 0.5;
	//B.importval(x,y,4);
	//B.importval(m,y,4);
	//B.importval(nn,step,y,4);
	B.importval(y,4);
	B.draw();
	return 0;
}
//g++ exampledraw.cc -std=c++11 -I/usr/include/python2.7 -lpython2.7 -o testfile
