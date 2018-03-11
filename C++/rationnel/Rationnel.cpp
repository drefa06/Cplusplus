#include <iostream>
#include <stdio.h>
#include <string>
#include "rationnel.h"

using namespace std;

int Rationnel::nbrInstances=0; //c'est ici qu'on fait l'allocation memoire de la variable static 
int Complex::nbrInstances=0; //c'est ici qu'on fait l'allocation memoire de la variable static 

string printRationnel(Rationnel r){
    string s;
    if (r.getNumerateur()==0) 
        s = "0";
    else if (r.getNumerateur() == r.getDenominateur()) 
        s = "1";
    else if (r.getDenominateur() == 1) 
        s = to_string(r.getNumerateur());
    else {
        if ((r.getNumerateurInit()==r.getNumerateur())||(r.getFacteur()==1))
            s = to_string(r.getNumerateur()) + "/" + to_string(r.getDenominateur());
        else
            s = to_string(r.getFacteur()) + "*" + to_string(r.getNumerateur()) + "/" + to_string(r.getDenominateur());
        }
    return s;
}

Rationnel scanRationnel(string s){
    int num,denom;
    
    if (s.find("/"))
        sscanf(s.c_str(),"%d/%d",&num,&denom);
    else {
        num=std::stoi(s);
        denom=1;
    }
    
    //pb num et denom sont des var privées et ne peuvent etre modifiée
    //solution1, declarer cette fonction dans la classe avec le mot clef friend
    //           une fonction amie a alors acces a tous les membres de cette classe
    // int div=Rationnel::pgcd(num,denom);
    // r.numerateur=num/div;
    // r.denominateur=denom/div;

    //mais y a mieux ...
    Rationnel tmp(num,denom);
    return tmp;
}

//outside solution tp print a Rationnel
//we can also declare it in Rationnel
ostream & operator<<(ostream& o, const Rationnel& r){ 
    //create and use a function in this file
    //o << printRationnel(r);
    //use an internal method of Rationnel
    o << r.printable();

    return o;
}

//outside solution to scan  a rationnel
//an inside solution is declared in Rationnel
//istream & operator>>(istream& i, Rationnel& res){
//    string s;
//    i>>s;
    
//    res=scanRationnel(s);
    
//    return i;
//}

ostream & operator<<(ostream& o, const Complex& r){  
    
    o << "(" << printRationnel(r.getReel()) << "," << printRationnel(r.getImaginaire()) << ")";
    
    return o;
}

istream & operator>>(istream& i, Complex& res){
    #define FMT_NOT_LBRACKET "%*[^(]"
    #define FMT_NOT_RBRACKET "%*[)$]"

    string s;
    i>>s;
    string re,im;
    
    //Something wrong in sscanf
    if (s.find(","))
        sscanf(s.c_str(),FMT_NOT_LBRACKET "%[0-9-/],%[0-9-/]" FMT_NOT_RBRACKET,&re,&im);
    else {
        re=s;
        im="0";
    }
    Rationnel reel(re);
    Rationnel imaginaire(im);
    
    Complex tmp(reel,imaginaire);
    res=tmp;
    
    return i;
}
