/*** Main function call ***/
#include <stdio.h>
#include "interface.h"

int main()
{
    printf("uje muje\n");
    FHandle myRec = create_LinearFunction(1, 8, -20, 20, 1);
    printf("działa\n");
    
    float *lista = wynik(myRec);
    
    for (int i=0;i < (sizeof (lista) /sizeof (lista[0]));i++) {
    printf("%lf\n",lista[i]);
}

    free_Function(myRec);
    return 0;
}
