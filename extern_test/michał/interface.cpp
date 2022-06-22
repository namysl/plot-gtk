#include "interface.h"
#include "mathfunctions.h"

extern "C"
{
    FHandle create_LinearFunction(float a, float b, float x_min, float x_max, float step){
        return (LinearFunction*) new LinearFunction(a, b, x_min, x_max, step);
    };
	void free_Function(FHandle p){
		delete (LinearFunction*) p;
	}
    float* wynik(FHandle p){
        return ((LinearFunction*) p)->wynik();
    }
    void wypisz(FHandle p){
        return ((LinearFunction*) p)->wypisz();
    }
}
