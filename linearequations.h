#ifndef ROWNANIA_H_INCLUDED
#define ROWNANIA_H_INCLUDED


#endif // ROWNANIA_H_INCLUDED
//using namespace std;


class Rownania{
    public:
        int ilosc=0;

        Rownania(string linijka, bool wypisz = false){
            string split;
            stringstream X(linijka);
            while(getline(X, split, '\n')) {
                if(wypisz)
                    cout << split << endl;
                this->ilosc++;
            }
            cout<<endl;
            linijki = new string[ilosc];
            stringstream Y(linijka);
            int i=0;
            while(getline(Y, split, '\n')) {
                linijki[i++] = split;
            }
            znaki = new char[ilosc];
            wyniki = new double[ilosc];
            wartosci = new double[ilosc*2*(ilosc+1)]{0};//odpowiednio: rzad, lewa/prawa strona, która zmienna
            wyszukajZnaki();
            rozbior();
            rozwiaz();
        }


        Rownania(int x){
            this->ilosc = x;
            linijki = new string[ilosc];
            znaki = new char[ilosc];
            wyniki = new double[ilosc];
            wartosci = new double[ilosc*2*(ilosc+1)]{0};//odpowiednio: rzad, lewa/prawa strona, która zmienna
            wpiszLinijki();
            wyszukajZnaki();
            rozbior();
            rozwiaz();
        }
        void debug(){
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

            for(int i=0;i<ilosc;i++){
                cout<<znaki[i]<<":"<<wyniki[i]<<endl;
            }
        }

		string getString(){
			string str4gtk;
			
		    if(!daSieRozwiazac){
                str4gtk.append("Nie da sie rozwiazac tego rownania");
            }
            else{
		        for(int i=0; i<ilosc; i++){
		            str4gtk += znaki[i];
		            str4gtk += " = ";
		            str4gtk += to_string(wyniki[i]);
		            str4gtk += "\n";
		        }
            }
            return str4gtk;
		}


        void pokaz(){
            if(!daSieRozwiazac){
                cout<<"Nie da sie rozwiazac tego rownania"<<endl;
                return;
            }
            for(int i=0;i<ilosc;i++){
                cout<<znaki[i]<<" = "<<wyniki[i]<<endl;
            }
        }

        double* getWyniki(){
            return wyniki;
        }

        char* getZnaki(){
            return znaki;
        }

        int getIlosc(){
            if(!daSieRozwiazac){
                return 0;
            }
            return ilosc;
        }

    private:
        string *linijki;
        char *znaki;
        double *wyniki;
        double *wartosci;
        bool daSieRozwiazac = true;

        void wpiszLinijki(){
            for(int i=0;i<this->ilosc;i++){
                cin>>linijki[i];
            }
            cout<<endl;
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
                            daSieRozwiazac = false;
                            return;
                        }
                        znaki[licznik] = temp[j];
                        licznik++;
                    }
                }
            }
            if(licznik<this->ilosc){
                cout<<"Za malo znakow!"<<endl;
                daSieRozwiazac = false;
                return;
            }
        }

        void rozbior(){
            if(!daSieRozwiazac){
                return;
            }
            for(int i=0;i<this->ilosc;i++){
                string temp = linijki[i];
                string dozwolone = "qwertyuiopasdfghjklzxcvbnm";
                string cyfry = "0123456789";
                char znak = '+';
                int numerZnaku = this->ilosc;
                string liczba = "";
                bool prawaStrona = 0;
                //musi znalezc '=' inaczej to nie jest rownanie
                if(temp.find('=')==string::npos){
                    cout<<"Zle napisane rownanie"<<endl;
                    daSieRozwiazac = false;
                    return;
                }

                for(unsigned int j=0;j<temp.length();j++){
                    if(dozwolone.find(temp[j])!=string::npos){
                        numerZnaku = string(znaki).find(temp[j]);
                    }else if(temp[j]=='+'){
                        if(liczba==""){
                            liczba = "1";
                        }
                        ustawWartosc(getWartosc(i,prawaStrona,numerZnaku),znak,liczba);
                        numerZnaku = this->ilosc;
                        znak = '+';
                        liczba = "";
                    }else if(temp[j]=='-'){
                        if(liczba=="" && j==0){
                            znak = '-';
                            continue;
                        }else if(temp[j-1]=='='){
                            znak = '-';
                            continue;
                        }else if(liczba==""){
                            liczba = "1";
                        }

                        ustawWartosc(getWartosc(i,prawaStrona,numerZnaku),znak,liczba);
                        numerZnaku = this->ilosc;
                        znak = '-';
                        liczba = "";
                    }else if(cyfry.find(temp[j])!=string::npos){
                        liczba += temp[j];
                    }else if(temp[j]=='='){
                        if(liczba==""){
                            liczba = "1";
                        }
                        ustawWartosc(getWartosc(i,prawaStrona,numerZnaku),znak,liczba);
                        numerZnaku = this->ilosc;
                        znak = '+';
                        liczba = "";
                        prawaStrona = 1;
                    }else if(temp[j]=='.'){
                        liczba += temp[j];
                    }
                }
                if(liczba=="" && numerZnaku!=this->ilosc){
                    liczba = "1";
                }
                ustawWartosc(getWartosc(i,prawaStrona,numerZnaku),znak,liczba);
            }
        }

        double* getWartosc(int i, int j, int k){
            return &this->wartosci[i*2*(ilosc+1) + j*(ilosc+1) + k];
        }

        void ustawWartosc(double* gdzie, char znak, string wartosc){
            stringstream ss(wartosc);
            ss>>*gdzie;
            if(znak=='-'){
                *gdzie = -*gdzie;
            }
        }

        void ustawWartosc(double* gdzie, double wartosc){
            *gdzie=wartosc;
        }

        double wyznacznik(double *macierz, int n){
            if(n==1){
                return *macierz;
            }else{
                double *podmacierz = new double[(n-1)*(n-1)]{0};
                double det=0;
                int znak=1;
                for(int kolumna=0;kolumna<n;kolumna++){
                    int p=0,q=0;
                    for(int i=1;i<n;i++){
                        for(int j=0;j<n;j++){
                            if(j!=kolumna){
                                podmacierz[p*(n-1)+(q++)] = macierz[i*n+j];
                                if (q % (n - 1) == 0) {
                                    p++;
                                    q = 0;
                                }
                            }
                        }
                    }
                    det = det + macierz[kolumna]*wyznacznik(podmacierz,n-1)*znak;
                    znak = -znak;
                }
                delete podmacierz;
                return det;
            }
        }

        void rozwiaz(){
            if(!daSieRozwiazac){
                return;
            }
            //wszystkie zmienne na lewo, wartosci na prawo
            for(int i=0;i<this->ilosc;i++){
                for(int j=0;j<this->ilosc;j++){
                    ustawWartosc(getWartosc(i,0,j),*getWartosc(i,0,j)-*getWartosc(i,1,j));
                    ustawWartosc(getWartosc(i,1,j),0);
                }
                ustawWartosc(getWartosc(i,1,this->ilosc),*getWartosc(i,1,this->ilosc)-*getWartosc(i,0,this->ilosc));
                ustawWartosc(getWartosc(i,0,this->ilosc),0);
            }
            //policzyc wyznacznik
            double *macierz = new double[ilosc*ilosc]{0};
            for(int i=0;i<ilosc;i++){
                for(int j=0;j<ilosc;j++){
                    macierz[i*ilosc+j] = *getWartosc(i,0,j);
                }
            }
            double wyznacznikWartosc = wyznacznik(macierz,ilosc);
            delete macierz;
            //cout<<"WYZNACZNIK TO: "<<wyznacznikWartosc<<endl;
            if(wyznacznikWartosc==0){
                //cout<<"Nie da sie rozwiazac tego rownania"<<endl;
                daSieRozwiazac = false;
                return;
            }
            for(int x=0;x<ilosc;x++){
                double *macierz = new double[ilosc*ilosc]{0};
                for(int i=0;i<ilosc;i++){
                    for(int j=0;j<ilosc;j++){
                        macierz[i*ilosc+j] = *getWartosc(i,0,j);
                    }
                }
                //zamien kolumne
                for(int i=0;i<ilosc;i++){
                    macierz[i*ilosc+x]=*getWartosc(i,1,ilosc);
                }
                //cout<<"Po lewej:"<<wyznacznik(macierz,ilosc)<<"Wyznacznik:"<<wyznacznikWartosc<<endl;
                wyniki[x] = (double)wyznacznik(macierz,ilosc)/(double)wyznacznikWartosc;
                delete macierz;
            }
        }

};
