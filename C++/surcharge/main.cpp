/* 
 * File:   main.cpp
 * Author: Formation
 *
 * Created on 11 janvier 2016, 15:19
 */

#include <cstdlib>
#include <iostream>
using namespace std;

double f1(double a, double b, double c){
    return a+b+c;
}
double f2(double a, double b, double c=1){
    return a+b+c;
}
int f2(string s){ //utilisation du meme nom que precedement
    return s.length();
}
/*
 * 
 */
struct Personne {
    string nom;
    int age;
    
    //Dans une structure on peut declarer/definir une fonction
    //Si le code est dans la structure, il est forcement inline
    void feterAnniversaire(/*const Personne this */) const; //le const qu'on ne met pas dans la declaration, se met apres la parenthese
    void prendreDeLAge(){
        age++;
        feterAnniversaire();
    }
    
    Personne operator+(const Personne& b){
        Personne resultat;
        resultat.nom = nom+" "+b.nom;
        resultat.age = age+b.age;

        return resultat;
    }
};
//si le code n'est pas DANS la structure (qui peut etre dans un .hpp) on le defini ainsi
//return_type struct_name::fonction_name(parameters){declaration}
void Personne::feterAnniversaire() const {
        cout<<"Joyeux anniversaire "<<nom<<" pour tes " << this->age <<"ans"<<endl; //le this est facultatif
    }

void feterAnniversairePersonne(const Personne& p){
    cout<<"Joyeux anniversaire "<<p.nom<<endl;
}


class C_Personne {
public:
    string nom;
    int age;
private:
    int secret;
    
public:
    void feterAnniversaire() const{
        cout<<"Joyeux anniversaire "<<nom<<" pour tes " << age <<"ans"<<endl;
    };
    void prendreDeLAge(){
        age++;
        feterAnniversaire();
    }
    int getSecret(){
        return secret;
    }
    
    C_Personne operator+(const C_Personne& b){
        C_Personne resultat;
        resultat.nom = nom+" "+b.nom;
        resultat.age = age+b.age;
        secret=123456;
        return resultat;
    }
};

//on peut egalement declarer la surcharge de + directement comme membre de Personne
//mais on doit enlever cette declaration pour eviter toute ambiguite
/*Personne operator+(const Personne& a,const Personne& b){
    Personne resultat;
    resultat.nom = a.nom+" "+b.nom;
    resultat.age = a.age+b.age;

    return resultat;
}*/
ostream & operator<<(ostream& o, const Personne& p){
    o << "Nom: " << p.nom << endl;
    o << "Age: " << p.age << endl;
    return o;
}

int main(int argc, char** argv) {
    cout << "f1(1,2,3):" << f1(1,2,3) << endl; //call f1
    
    cout << "f2(1,2,3):" << f2(1,2,3) << endl; //call f2
    cout << "f2(1,2):" << f2(1,2) << endl;   //call f2 with 3rd param = default = 1

    cout << "f2(\"Fabrice\"):" << f2("Fabrice") << endl; //le systeme ne se trompe pas de fonction f2 a appeller
    
    //surcharge de operateur + pour pouvoir additionner des personnes
    Personne fabrice={"Fabrice", 44};
    Personne aurelie={"Aurelie", 37};
    Personne aurelie_plus_fabrice = fabrice + aurelie;
    cout << "Nom de aurelieetfabrice: " << aurelie_plus_fabrice.nom << endl;
    cout << "Age de aurelieetfabrice: " << aurelie_plus_fabrice.age << endl;
    
    //surcharge de operateur << pour imprimer le contenu de fabrice
    cout << endl << "Contenu de fabrice: " << endl << fabrice << endl;
    cout << endl << "Contenu de aurelieetfabrice: " << endl << aurelie+fabrice << endl;
    
    //cast
    double x=12.3;
    int n = (int)x; //C
    int m = int(x); //C++
    
    void *p=&x;
    double *ptr=(double*)(p); //quasi identique au C, donc aucun interret
    
    cout << "En C:   ";
    feterAnniversairePersonne(fabrice); //ca c'est du C
    cout << "En C++: ";
    fabrice.feterAnniversaire();//en C++ il suffit de rajouter la fonction feterAnniversaire dans la structure
    fabrice.prendreDeLAge();
    
    //Avec classes
    C_Personne fabrice2;
    fabrice2.nom="Fabrice";
    fabrice2.age=44;
    C_Personne aurelie2;
    aurelie2.nom="Aurelie";
    aurelie2.age=37;
    C_Personne aurelie2_plus_fabrice2 = fabrice2 + aurelie2;
    cout << "Nom de aurelieetfabrice: " << aurelie_plus_fabrice.nom << endl;
    cout << "Age de aurelieetfabrice: " << aurelie_plus_fabrice.age << endl;
    cout << "Nom de aurelie2_plus_fabrice2: " << aurelie2_plus_fabrice2.nom << endl;
    cout << "Age de aurelie2_plus_fabrice2: " << aurelie2_plus_fabrice2.age << endl;
    cout << "secret de aurelie2_plus_fabrice2: " << aurelie2_plus_fabrice2.getSecret() << endl;
    
    fabrice2.feterAnniversaire();//en C++ il suffit de rajouter la fonction feterAnniversaire dans la structure
    fabrice2.prendreDeLAge();
     
    return 0;
}

