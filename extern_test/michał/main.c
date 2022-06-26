/*** Main function call ***/
#include <stdio.h>
#include "interface.h"

int main()
{
    printf("uje muje1\n");
    LinearHandle liniowa = create_LinearFunction(1, 8, -20, 20, 1);
    printf("działa1\n");
    
    float *lista1 = wynik_Linear(liniowa);
    
    for (int i=0; i < (sizeof(lista1)); i++) {
	    printf("%lf\n", lista1[i]);
	}

    free_Linear(liniowa);
    
    
    printf("uje muje2\n");
    QuadraticHandle kwadratowa = create_QuadraticFunction(1, 8, 5, -20, 20, 1);
    printf("działa2\n");
    
    float *lista2 = wynik_Quadratic(kwadratowa);
    
    for (int i=0; i < (sizeof(lista2)); i++) {
	    printf("%lf\n", lista2[i]);
	}

    free_Quadratic(kwadratowa);
    
    
    printf("uje muje3\n");
    BinomialHandle dwumianowy = create_BinomialDistribution(20, 0.5);
    printf("działa3\n");
    
    long double *lista3 = wynik_Binomial(dwumianowy);
    
    for (int i=0; i < (sizeof(lista3)); i++) {
	    printf("%Lf\n", lista3[i]);
	}

    free_Binomial(dwumianowy);
    
    return 0;
    
    
}
