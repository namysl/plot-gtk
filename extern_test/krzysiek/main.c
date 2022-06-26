/*** Main function call ***/
#include <stdio.h>
#include <stdbool.h>
#include "interface.h"

int main()
{
    printf("uje muje\n");
    LinEquHandle test = create_LinEqu("2x-y=2\ny=2", true);
    printf("działa\n");
    
    int ilosc;
    double* wyniki;
    char* znaki;
    
    ilosc = getIlosc_LinEqu(test);
    wyniki = getWyniki_LinEqu(test);
    znaki = getZnaki_LinEqu(test);
    
    for(int i=0; i<ilosc; i++){
        printf("%c : %lf", znaki[i], wyniki[i]);
    }
    
    free_LinEqu(test);
    
    return 0;
}
