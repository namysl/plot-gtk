#include "interface.h"
#include "mathfunctions.h"

extern "C"
{
    LinearHandle create_LinearFunction(float a, float b, float x_min, float x_max, float step){
        return (LinearFunction*) new LinearFunction(a, b, x_min, x_max, step);
    };
	void free_Linear(LinearHandle V){
		delete (LinearFunction*) V;
	}
    float* wynik_Linear(LinearHandle V){
        return ((LinearFunction*) V)->wynik();
    }
    void wypisz_Linear(LinearHandle V){
        return ((LinearFunction*) V)->wypisz();
    }
    
    
    QuadraticHandle create_QuadraticFunction(float a, float b, float c, float x_min, float x_max, float step){
        return (QuadraticFunction*) new QuadraticFunction(a, b, c, x_min, x_max, step);
    };
	void free_Quadratic(QuadraticHandle V){
		delete (QuadraticFunction*) V;
	}
    float* wynik_Quadratic(QuadraticHandle V){
        return ((QuadraticFunction*) V)->wynik();
    }
    void wypisz_Quadratic(QuadraticHandle V){
        return ((QuadraticFunction*) V)->wypisz();
    }
    
    
    BinomialHandle create_BinomialDistribution(long double p, long int n){
        return (BinomialDistribution*) new BinomialDistribution(p, n);
    };
	void free_Binomial(BinomialHandle V){
		delete (BinomialDistribution*) V;
	}
    long double* wynik_Binomial(BinomialHandle V){
        return ((BinomialDistribution*) V)->wynik();
    }
    long int silnia(BinomialHandle V){
    	int n;
    	return ((BinomialDistribution*) V)->silnia(n);
    }
    long double newton(BinomialHandle V){
    	int n, k;
    	return ((BinomialDistribution*) V)->newton(n, k);
   	}
    void wypisz_Binomial(BinomialHandle V){
        return ((BinomialDistribution*) V)->wypisz();
    }
}
