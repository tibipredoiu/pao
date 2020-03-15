#include <iostream>
#include <stdlib.h>
using namespace std;
class individ {
private:
    int i;
    char tip;
    int varsta;
    double energie;
    unsigned char viu;
public:
    individ(int,char);
    void actualizare(individ&);
    int esteviu();
    int gettip();
    void citire(istream &in);
    void afisare(ostream &out);
    friend istream& operator>>(istream&,individ&);
    friend ostream& operator<<(ostream&,const individ&);
    void hraneste();
    void inmulteste(individ&);
    void ataca(individ&);
    void imbatraneste();
    void moare();

};

individ::individ(int i1=0, char tip1=0){
        this->i=i1;
        this->tip=tip1;
        this->varsta=0;
        this->energie=0;
        this->viu=1;
    }

void individ::hraneste(){
    int lowest=1;
    int highest=10;
    int range=(highest-lowest)+1;
    energie=lowest + range * (rand()/(RAND_MAX + 1));

}
void individ::inmulteste(individ&fiu){

    if(this->i+1==0 || this->i-1==0)
    {
        fiu.tip=this->tip;
        fiu.varsta=0;
        fiu.energie=2*this->energie;
    }
}

void individ::ataca(individ&x){

    while(this->i-1!=0 || this->i+1!=0 && x.tip!=this->tip)
    {
        if(this->energie > x.energie){
            this->energie = this->energie - x.energie;
            moare();
        }
    }
}

void individ::imbatraneste(){
    varsta++;
    energie=energie-1;
    if (varsta==70 || energie<=0)
        moare();
}

int individ::esteviu(){

    if(this->viu==1)
        return 1;
    else if (this->viu==0)
        return 0;

}

int individ::gettip(){
    return this->tip;
}
void individ::actualizare(individ& x){

    x.hraneste();
    x.inmulteste(*this);
    x.ataca(*this);
    x.imbatraneste();
}


void individ::moare(){
    this->viu=0;
}
void individ::citire(istream&in)
{
    cout<<"Pozitia este:";
    in>>i;
    cout<<"Tipul:";
    in>>tip;
    cout<<"Varsta:";
    in>>varsta;
    cout<<"Energia:";
    in>>energie;
    cout<<"Este viu:";
    in>>viu;

}
 istream &operator>>(istream&j,individ&c)
{
    c.citire(j);
    return j;
}
void individ::afisare(ostream&out)
{
    out<<"Pozitia "<< i<<". Tipul: "<<tip<<". Individul are: "<<varsta<<" ani si energia: "<<energie<<" si este viu:"<<viu;
}
 ostream &operator<<(ostream&j,individ&c)
{
    c.afisare(j);
    return j;
}


int main()
{

int option;
do
{
    cout<<endl;
    cout<<"Predoiu Tiberiu Ionut, 212, Proiect 16, Clasa individ \n";
    cout<<"\n\t MENIU:";
    cout<<"\n======================================================\n";
    cout<<"\n";
    cout<<"1. Cititi datele pentru un individ \n";
    cout<<"2. Afisati datele pentru un individ \n";
    cout<<"3. Actualizare date individ\n";
    cout<<"4. Verifica daca individul este mort sau viu \n";
    cout<<"5. Afiseaza tipul individului \n";
    cout<<"0. Iesire \n";
cout<<"\nAlegeti numarul optiunii:";
cin>> option;
switch(option)
{
case 1:
    int n;
    individ *x;
    cout<< "Dati numarul de indivizi: \n";
    cin >> n;
    x=new individ [n];
    for(int i =0; i<n;i++)
    {
        cout<<"Citire date indivizi \n";
        cin>>x[i];
    }
break;
case 2:
    for(int i= 0; i<n; i++)
    {
        cout<<"Afisare date indivizi: \n";
        cout<<x[i];
        cout<<endl;
    }
break;

case 3:
    for (int i=0; i<n;i++){
    x[i].actualizare(x[i]);
    }
break;

case 4:
    for (int i=0;i<n;i++){
        if(x[i].esteviu()==49)
        cout<<"Indiviul "<<i <<" este viu"<<endl;
    else if ((x[i].esteviu()==48))
        cout<<"Individul "<<i <<" este mort"<<endl;
    }
    break;

case 5:
    for (int i= 0; i<n ; i++){
    cout<<"Tipul individului "<<i+1<<" este: ";
    cout<<(x[i]).gettip();// Returneaza codul ascii al caracterului + (43) sau 0 (48).
    cout<<endl;
    }
    break;

case 0:
    cout<<"\nEXIT!\n";
    break;

if (option<0 || option > 5)
    cout<<"Selectie invalida\n";


}

}
while(option!=0);

return 0;
}
