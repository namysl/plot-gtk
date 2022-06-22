#include <iostream>
#include <sstream>
using namespace std;
#include "../rownania.h"

int main()
{
    /*string kontrola;
    cout<<"1-wpisz rownanie 2-zakoncz program 3-przykladowe rownania"<<endl;
    cin>>kontrola;
    while(kontrola!="2"){
        if(kontrola!="3"){
            int ilosc=0;
            while(true){
                cout<<"Ile linijek ma twoje rownanie? ";
                cin>>ilosc;
                if(cin.good()){
                    if(ilosc<=0){
                        cout<<"Niepoprawna ilosc"<<endl;
                        continue;
                    }
                    break;
                }else{
                    cin.clear();
                    cin.ignore();
                    cout<<"Wpisz liczbe"<<endl;
                }
            }
            cout<<"=========="<<endl;
            Rownania rownania(ilosc);
            if(kontrola=="debug"){
                rownania.debug();
            }
            if(kontrola=="debug"){
                rownania.debug();
            }
            rownania.pokaz();
            cout<<"=========="<<endl;
        }else{
            cout<<"=========="<<endl;
            Rownania rownania("2x-y=2\ny=2",true);
            rownania.pokaz();
            cout<<"=========="<<endl;

            cout<<"=========="<<endl;
            Rownania rownania2("a+b+c+d=75\na-b+c-d=101\n2d-3c-2a-b=-313\n10b-3a=76",true);
            rownania2.pokaz();
            cout<<"=========="<<endl;

            cout<<"=========="<<endl;
            Rownania rownania3("x+y+z=10\nx-y+z=-2\nx-z-y=3",true);
            rownania3.pokaz();
            cout<<"=========="<<endl;

            cout<<"=========="<<endl;
            Rownania rownania4("1.5a-b=18\n2.3a+1.1b=19.7",true);
            rownania4.pokaz();
            cout<<"=========="<<endl;


        }
        cout<<"1-kontynuuj 2-zakoncz program 3-przykladowe rownania"<<endl;
        cin>>kontrola;
    }*/


    //test
    int ilosc;
    double* wyniki;
    char* znaki;
    {Rownania rownania("2x-y=2\ny=2",true);
    ilosc = rownania.getIlosc();
    wyniki = rownania.getWyniki();
    znaki = rownania.getZnaki();}
    for(int i = 0;i<ilosc;i++){
        cout<<znaki[i]<<" : "<<wyniki[i]<<endl;
    }
    return 0;
}
