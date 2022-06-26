#ifdef __cplusplus
extern "C" {
#endif

    typedef void *LinearHandle;
    LinearHandle create_LinearFunction(float a, float b, float x_min, float x_max, float step);
    void free_Linear(LinearHandle);
    float* wynik_Linear(LinearHandle);
    void wypisz_Linear(LinearHandle);
    
    typedef void *QuadraticHandle;
    QuadraticHandle create_QuadraticFunction(float a, float b, float c, float x_min, float x_max, float step);
    void free_Quadratic(QuadraticHandle);
    float* wynik_Quadratic(QuadraticHandle);
    void wypisz_Quadratic(QuadraticHandle);
    
    typedef void *BinomialHandle;
    BinomialHandle create_BinomialDistribution(long double p, long int n);
    void free_Binomial(BinomialHandle);
    long double* wynik_Binomial(BinomialHandle);
    long int silnia(BinomialHandle);
    long double newton(BinomialHandle);
    void wypisz_Binomial(BinomialHandle);
    
#ifdef __cplusplus
}
#endif
