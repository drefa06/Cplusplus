/* 
 * File:   main.cpp
 * Author: Formation
 *
 * Created on 13 janvier 2016, 11:11
 */

#include <cstdlib>
#include <iostream>
using namespace std;


/*
 * 
 */
short myMax1(short a, short b){
    return (a<b)? b: a ;
}
short myMax2(short a, short b){
    return (a<b)? b: a ;
}

//une des solution est de reecrire la fonction avec les types
double myMax2(double a, double b){
    return (a<b)? b: a ;
}
//PB: le calcul reste le meme qqsoit le type !!
//SOLUTION: utilisation des generiques
template <class T>
T myMax3(T a,T b){ //ne genere pas de code a la compilation
    return (a<b)? b: a ;
}

int main(int argc, char** argv) {
    short i=12,j=1;
    double x=1.3,y=1.42;
    char a='a',b='b';
    
    cout << "Test1: MyMax1 ne connais que les short"<<endl;
    cout << "max(i,j)="<<myMax1(i,j)<<endl; //le compilateur genere le code avec des short car il est créé ainsi ainsi.
    cout << "max(x,y)="<<myMax1(x,y)<<endl; //ne fonctionne pas car myMax ne connais QUE les short
    // => tres specialise voir restrictif
    
    cout << "Test2: MyMax2 est réécrit pour les short et les double"<<endl;
    cout << "max(i,j)="<<myMax2(i,j)<<endl; //le compilateur genere le code avec des short car il est créé ainsi.
    cout << "max(x,y)="<<myMax2(x,y)<<endl; //le compilateur genere le code avec des long car il est créé ainsi
    // => et il faut rajouter autant de fonctions que de types utilisés
    //cout << "max(x,y)="<<myMax2(a,b)<<endl; //ne fonctionne pas car myMax NE connais PAS les float
    
    cout << "Test3: MyMax3 est generique"<<endl;
    cout << "max(i,j)="<<myMax3(i,j)<<endl; //le compilateur genere le code avec des short car il est créé ainsi.
    cout << "max(x,y)="<<myMax3(x,y)<<endl; //le compilateur genere le code avec des long car il est créé ainsi
    cout << "max(x,y)="<<myMax3(a,b)<<endl; //le compilateur genere le code avec des long car il est créé ainsi
    
    
    return 0;
}

