#ifdef __cplusplus

#include <string>
#include <iostream>
#include <sstream>
using namespace std;

extern "C" {
#endif

    typedef void *LinEquHandle;
    LinEquHandle create_LinEqu(string linijka, bool wypisz); //char*/string linijka ?
    void free_LinEqu(LinEquHandle);
    //void debug_LinEqu(LinEquHandle);
    //string getString_LinEqu(LinEquHandle);
	//void pokaz_LinEqu(LinEquHandle);
	double* getWyniki_LinEqu(LinEquHandle);
	char* getZnaki_LinEqu(LinEquHandle);
	int getIlosc_LinEqu(LinEquHandle);

#ifdef __cplusplus
}
#endif
