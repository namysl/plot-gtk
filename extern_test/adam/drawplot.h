#ifndef DRAWPLOT_H_INCLUDED
#define DRAWPLOT_H_INCLUDED
#endif

#include "matplotlibcpp.h"

namespace plt = matplotlibcpp;
using namespace std;

extern "C" {
	class plotargs{
		public:
			plotargs(int l){//constructor
				length = l;
				x = new double[length];
				y = new double[length];
			}

			void init(){//manual x,y values
				std::cout << "Podaj " << length << " zmiennych x" << endl;
				for (int i=0; i<length; i++){
		                            std::cin >> x[i];
		                    }
				std::cout << "Podaj " << length << " zmiennych y" << endl;
		                    for (int i=0; i<length; i++){ 
		                            std::cin >> y[i];
		                    }
			}

			bool importval(double tx[], double ty[], int num){//use two arrays
				if (length != num) return false;
				for (int i=0; i<num; i++){
					x[i] = tx[i];
					y[i] = ty[i];
				}
				return true;
			}
			bool importval(int tx, double ty[], int num){//use first arg and y-array
				if (length != num) return false;
				for (int i=0; i<num; i++){
					x[i] = tx+i;
					y[i] = ty[i];
				}
				return true;
			}
			bool importval(double tx, double step, double ty[], int num){//use first arg, step and y-array
				if (length != num) return false;
				for (int i=0; i<num; i++){
					x[i] = tx+i*step;
					y[i] = ty[i];
				}
				return true;
			}
			bool importval(double ty[], int num){//use only y-array
				if (length != num) return false;
				for (int i=0; i<num; i++){
					x[i] = i+1;
					y[i] = ty[i];
				}
				return true;
			}
			
			bool importval(long double tt[], long int num){//mathfunction3
				if (length != num) return false;
				for (int i=0; i<num; i++){
					x[i] = static_cast<double>(tt[2*i]);
					y[i] = static_cast<double>(tt[2*i+1]);
				}
				return true;
			}
			bool importval(float tt[], int num){//mathfunction1,2
				if (length != num) return false;
				for (int i=0; i<num; i++){
					x[i] = tt[2*i];
					y[i] = tt[2*i+1];
				}
				return true;
			}


			void setcolor(char c){
				color[0] = c;
			}

			void draw(){//plot requires vectors not arrays
				std::vector<float> vx(length);
	   			std::vector<float> vy(length);
		    		for (int i=0; i<length; i++){
		            		vx.at(i) = this->x[i];
		            		vy.at(i) = this->y[i];
		    		}
		    		plt::plot(vx, vy, color);
				plt::title("Wykres");
				//plt::xlabel("X");
				//plt::ylabel("Y");
				plt::legend();
				plt::save("plot.jpg");//png zapisuje pusty plik
				plt::show();
			}

		private:
			int length;
			double *x;
			double *y;
			string color = "b-";
	};
}
