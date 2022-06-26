#include "interface.h"
#include "linearequations.h"

#include <string>
#include <iostream>
#include <sstream>
using namespace std;

extern "C"
{
    LinEquHandle create_LinEqu(string linijka, bool wypisz){ //char*/string linijka ?
        return (LinEquHandle*) new Rownania(linijka, wypisz);
    };
	void free_LinEqu(LinEquHandle V){
		delete (LinEquHandle*) V;
	}
	/*
	void debug_LinEqu(LinEquHandle V){
		return ((LinEquHandle*) V)->debug();
	}

	string getString_LinEqu(){
		return ((LinEquHandle*) V)->getString();
	}

    void pokaz_LinEqu(LinEquHandle V){
    	return ((LinEquHandle*) V)->pokaz();
    }
    */
    double* getWyniki_LinEqu(LinEquHandle V){
    	return ((LinEquHandle*) V)->getWyniki();
    }
    char* getZnaki_LinEqu(LinEquHandle V){
    	return ((LinEquHandle*) V)->getZnaki();
    }
    int getIlosc_LinEqu(LinEquHandle V){
    	return ((LinEquHandle*) V)->getIlosc();
    }

}
