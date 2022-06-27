/*** Main function call ***/
#include <stdio.h>
#include <stdbool.h>
#include "interface.h"

int main()
{
	float lista[10] = {1.1, 1.1, 2.2, 2.2, 3.3, 3.3, 4.4, 4.4, 5.5, 5.5};
	int ilosc = 6;
	PlotHandle plot = create_Plot(ilosc);
	
	import_val_Plot12(plot, lista, ilosc);
	draw_Plot(plot);
	
	free_Plot(plot);
	
    return 0;
 
}
