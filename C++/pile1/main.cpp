/* 
 * File:   main.cpp
 * Author: Formation
 *
 * Created on 12 janvier 2016, 15:24
 */

#include <cstdlib>
#include <iostream>
using namespace std;

#include "pile.h"

/*
 * 
 */
int main(int argc, char** argv) {
 
    cout << "Exemple1: " << endl;
    Pile p;
    cout<<"push 5 elem"<<endl;
    for(int i=0;i<5;i++){
        p.push(i+1);
    }
    cout<<"vide="<<p.isEmpty()<<endl;
    cout<< "Pile p: " <<p<<endl;
    int taille=p.getSize();
    for(int i=0;i<taille;i++) { // ou while(!p.isEmpty())
        cout<< "pop p["<<p.getSize()<<"] = " <<p.pop()<<endl;
    }
    cout<<"vide="<<p.isEmpty()<<endl;
    
    cout << endl << "Exemple2: " << endl;
    Pile* ptrPile=new Pile;
    ptrPile->push(1);
    ptrPile->push(10);
    ptrPile->push(100);
    cout << "Pile ptrPile (addr: " << ptrPile << "):" << (*ptrPile)<<endl;
    
    Pile pile2=(*ptrPile); //ne fonctionnera que si on a redefini 
                           // - l'initialisation: T(const T&)
    Pile pile3; 
    pile3=(*ptrPile);      // - l' affectation:   T& operator=(const T&)
    

    cout << "Pile ptrPile2: " << pile2<<endl;
    cout << "Pile ptrPile3: " << pile3<<endl;

    Pile* pile4=new Pile;
    cout << "pile4=ptrPile"<<endl;
    pile4=ptrPile;
    
    cout << "Pile pile4 before delete ptrPile (addr:  " << pile4 << "): " << (*pile4)<<endl;
    delete ptrPile;
    cout << "Pile pile4 after delete ptrPile (addr:  " << pile4 << "): " << (*pile4)<<endl;
            
    return 0;
}

