#ifdef __cplusplus
extern "C" {
#endif

    typedef void *PlotHandle;
    PlotHandle create_Plot(int l);
    void free_Plot(PlotHandle);
    bool import_val_Plot12(PlotHandle, float tt[], int num);
    bool import_val_Plot3(PlotHandle);
    void draw_Plot(PlotHandle);
    
#ifdef __cplusplus
}
#endif
