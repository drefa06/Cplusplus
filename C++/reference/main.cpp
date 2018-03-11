/* 
 * File:   main.cpp
 * Author: Formation
 *
 * Created on 11 janvier 2016, 14:27
 */

#include <cstdlib>
#include <iostream>

using namespace std;

/*
 * 
 */

void incrementerRef1(int* n){ //en C on met *
    (*n)++;    
}

//Passage par valeur, return et increment....
int incrementerVal1(int n){ 
    return n+1; //return n+1
}
int incrementerVal2(int n){ 
    return n++; //return n then increment n !!
}
int incrementerVal3(int n){ 
    return ++n; //increment n then return the result ...
}


void incrementer2(int& n){ //en C++ on met & pour indiquer l'adresse, c'est le passage par reference.
    n++;    
}
void incTab2(int* tab, int taille){
    for(int i=0;i<taille;i++) tab[i]++;
}

struct Personne {
    string nom;
    int age;
};
void f(Personne& p){
    cout << p.nom;
}

int main(int argc, char** argv) {
    //en C
    //passage de parametre par valeur
    int var=123;
    cout << "var before = "<<var;
    incrementerRef1(&var);
    cout << ", var after incrementerRef1 = " << var << endl;
    var = incrementerVal1(var); //fonctionne pas
    cout << "    var after incrementerVal1 = " << var << endl;
    var = incrementerVal2(var); //fonctionne pas
    cout << "    var after incrementerVal1 = " << var << " !!!" << endl;
    var = incrementerVal3(var); //fonctionne pas
    cout << "    var after incrementerVal1 = " << var << endl;
    
    //en C++
    //Pour une fonction, il y a des parametres:
    //  - formels: ici n = nom de la variable dans la fonction
    //  - reels:   ici var = nom de la variable dans l'appel de la fonction
    //
    //Passage de parametre:
    //  - valeur: La modif du parametre formel ne modifie pas le param reel
    //  - reference: La modif du formel MODIFIE le reel.
    cout << "var before = "<<var;
    incrementer2(var);
    cout << ", var after incrementer2 = " << var;
    var = incrementerVal1(var); //fonctionne pas
    cout << ", var after incrementerVal1 = " << var << endl;
          
    int tab[]={1,2,3};
    int sTab=sizeof(tab)/sizeof(*tab);
    incTab2(tab,sTab);
    cout << "Resultat de incTab2 (taille="<<sTab<<"): " << endl;
    for(int i=0;i<sTab;i++) cout << "   tab[" << i << "] = " << tab[i] << endl;
    
    //en C
    int* p;
    p=&var;
    (*p)++;
    cout << "var=" << var << ", adresse p=" << p << ", p=" << *p << endl; 
    
    //en C++
    int& ref=var;
    ref++;
    cout << "var=" << var << ", ref=" << ref << endl; //on ne peut pas afficher l'adresse dans ce cas
    
    //copie de la valeur, var reste inchangé
    int a=var;
    a++;
    cout << "var=" << var << ", a=" << a << endl;
    
    
    return 0;
}

