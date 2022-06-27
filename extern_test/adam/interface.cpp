#include "interface.h"
#include "drawplot.h"

extern "C" {
	/*
	typedef void *PlotHandle;
    PlotHandle create_Plot(int l);
    void free_Plot(PlotHandle);
    bool import_val_Plot12(float tt[], int num);
    bool import_val_Plot3(long double tt[], long int num);
    void draw_Plot(*PlotHandle);
    */
    
    PlotHandle create_Plot(int l){
    	return (PlotHandle*) new plotargs(l);
    };
    void free_Plot(PlotHandle V){
    	delete (PlotHandle*) V;
    }
    bool import_val_Plot12(PlotHandle V, float tt[], int num){
    	//float tt[]; 
    	//int num;
    	return ((PlotHandle*) V)->import_val(tt[], num);
    }
    bool import_val_Plot3(PlotHandle V){
    	long double tt[];
    	long int num;
    	return ((PlotHandle*) V)->import_val(tt[], num);
    }
    void draw_Plot(PlotHandle V){
    	return ((PlotHandle*) V)->draw();
    }
}
