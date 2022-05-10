#ifndef ROWNANIA_H_INCLUDED
#define ROWNANIA_H_INCLUDED



#endif // ROWNANIA_H_INCLUDED
using namespace std;

class Rownania{
    public:
        int ilosc;

        Rownania(int x){
            this->ilosc = x;
            linijki = new string[ilosc];
            znaki = new char[ilosc];
            wyniki = new int[ilosc];
            wartosci = new int[ilosc*2*(ilosc+1)]{0};//odpowiednio: rz¹d, lewa/prawa strona, która zmienna
            wpiszLinijki();
            rozbior();
        }
        void pokaz(){
            cout<<"Linijki:"<<endl;
            for(int i=0;i<this->ilosc;i++){
                cout<<linijki[i]<<endl;
            }
            cout<<"---"<<endl<<"Znaki:"<<endl;
            for(int i=0;i<this->ilosc;i++){
                cout<<znaki[i]<<endl;
            }

            for(int i=0;i<ilosc;i++){
                for(int j=0;j<2;j++){
                    for(int k=0;k<ilosc+1;k++){
                        cout<<*getWartosc(i,j,k)<<" ";
                    }
                    if(j==0){
                        cout<<": ";
                    }
                }
                cout<<endl;
            }
        }

        void rozwiaz(){
            //wszystkie zmienne na lewo, wartosci na prawo
            for(int i=0;i<this->ilosc;i++){
                for(int j=0;j<this->ilosc;j++){
                    ustawWartosc(getWartosc(i,0,j),*getWartosc(i,0,j)-*getWartosc(i,1,j));
                    ustawWartosc(getWartosc(i,1,j),0);
                }
                ustawWartosc(getWartosc(i,1,this->ilosc),*getWartosc(i,1,this->ilosc)-*getWartosc(i,0,this->ilosc));
                ustawWartosc(getWartosc(i,0,this->ilosc),0);
            }
        }

    private:
        string *linijki;
        char *znaki;
        int *wyniki;
        int *wartosci;

        void wpiszLinijki(){
            for(int i=0;i<this->ilosc;i++){
                cin>>linijki[i];
            }
            cout<<endl;
            wyszukajZnaki();
        }

        void wyszukajZnaki(){
            int licznik=0;
            for(int i=0;i<this->ilosc;i++){
                string temp = linijki[i];
                string dozwolone = "qwertyuiopasdfghjklzxcvbnm";
                for(unsigned int j=0;j<temp.length();j++){
                    if(dozwolone.find(temp[j])!=string::npos){
                        if(string(znaki).find(temp[j])!=string::npos){
                            continue;
                        }
                        if(licznik>=this->ilosc){
                            cout<<"Za duzo znakow!"<<endl;
                            return;
                        }
                        znaki[licznik] = temp[j];
                        licznik++;
                    }
                }
            }
        }

        void rozbior(){
            for(int i=0;i<this->ilosc;i++){
                string temp = linijki[i];
                string dozwolone = "qwertyuiopasdfghjklzxcvbnm";
                string cyfry = "0123456789";
                char znak = '+';
                int numerZnaku = this->ilosc;
                string liczba = "";
                bool prawaStrona = 0;
                for(unsigned int j=0;j<temp.length();j++){
                    if(dozwolone.find(temp[j])!=string::npos){
                        numerZnaku = string(znaki).find(temp[j]);
                    }else if(temp[j]=='+'){
                        if(liczba==""){
                            continue;
                        }
                        ustawWartosc(getWartosc(i,prawaStrona,numerZnaku),znak,liczba);
                        numerZnaku = this->ilosc;
                        znak = '+';
                        liczba = "";
                    }else if(temp[j]=='-'){
                        if(liczba==""){
                            znak = '-';
                            continue;
                        }
                        ustawWartosc(getWartosc(i,prawaStrona,numerZnaku),znak,liczba);
                        numerZnaku = this->ilosc;
                        znak = '-';
                        liczba = "";
                    }else if(cyfry.find(temp[j])!=string::npos){
                        liczba += temp[j];
                    }else if(temp[j]=='='){
                        ustawWartosc(getWartosc(i,prawaStrona,numerZnaku),znak,liczba);
                        numerZnaku = this->ilosc;
                        znak = '+';
                        liczba = "";
                        prawaStrona = 1;
                    }
                }
                ustawWartosc(getWartosc(i,prawaStrona,numerZnaku),znak,liczba);
            }
        }

        int* getWartosc(int i, int j, int k){
            return &this->wartosci[i*2*(ilosc+1) + j*(ilosc+1) + k];
        }

        void ustawWartosc(int* gdzie, char znak, string wartosc){
            stringstream ss(wartosc);
            ss>>*gdzie;
            if(znak=='-'){
                *gdzie = -*gdzie;
            }
        }

        void ustawWartosc(int* gdzie, int wartosc){
            *gdzie=wartosc;
        }

};
