#ifdef __cplusplus
extern "C" {
#endif
    typedef void *FHandle;
    FHandle create_LinearFunction(float a, float b, float x_min, float x_max, float step);
    void free_Function(FHandle);
    float* wynik(FHandle);
    void wypisz(FHandle);

#ifdef __cplusplus
}
#endif
