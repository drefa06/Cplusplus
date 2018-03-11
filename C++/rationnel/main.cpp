/* 
 * File:   main.cpp
 * Author: Formation
 *
 * Created on 12 janvier 2016, 09:18
 */

#include <cstdlib>
#include <iostream>

#include "rationnel.h"

using namespace std;


/*
 * 
 */
int main(int argc, char** argv) {

    cout << "Rationnel:";
    Rationnel r("1/2");
    Rationnel r0,r1("1"); //r0 est le constructeur par defaut car ne necessite aucune variable
    Rationnel r2("2/4");
    
    cout << "r = " << r << endl;
    cout << "r0 = " << r0 << endl;
    cout << "r1 = " << r1 << endl;
    cout << "r2 = " << r2 << endl;
    
    cout << "calcul r2+r1 = ";
    Rationnel r2r1 = r2+r1;
    cout << "r2r1 = " << r2r1 << endl;
    
    Rationnel* pr=new Rationnel("3/5");
    cout << "(*pr) = " << (*pr) << endl;
    Rationnel* tr=new Rationnel[100];
    
    
    cout << "r = " << r << endl;
    
    cout << "calcul r2+(*pr): ";
    Rationnel r3 = r2+(*pr);
    cout << "r3 = " << r3 << endl;
    cout << "calcul r2-(*pr): ";
    Rationnel r4 = r2-(*pr);
    cout << "r4 = " << r4 << endl;
    cout << "calcul r2x(*pr): ";
    Rationnel r5 = r2*(*pr);
    cout << "r5 = " << r5 << endl;    
    cout << "calcul r2/(*pr): ";
    Rationnel r6 = r2/(*pr);
    cout << "r6 = " << r6 << endl;    

    cout << "calcul ++r: ";
    Rationnel r7 = ++r;
    cout << "r7 = " << r7 << ", r = " << r << endl;    
    cout << "calcul r++: ";
    Rationnel r8 = r++;
    cout << "r8 = " << r8 << ", r = " << r << endl;    

    Rationnel r9;
    int i;
    cout << "Entrer un nombre rationnel: ";
    cin >> r9;
    cout << "Vous avez entré: " << r9 << endl;
    
    delete pr;
    delete[] tr;

    cout<<endl;
    
    cout << "Complex:";
    Complex c;
    Complex c0(1),c1(0,1);
    Complex c2(Rationnel("2/2"),4);
    
    cout << "c = " << c << endl;
    cout << "c0 = " << c0 << endl;
    cout << "c1 = " << c1 << endl;
    cout << "c2 = " << c2 << endl;
    
    cout << "calcul c2+c1: ";
    Complex c2c1 = c2+c1;
    cout << "c2c1 = " << c2c1 << endl;
    
    Complex* pc=new Complex(Rationnel("3/2"),Rationnel("5/2"));
    cout << "(*pc) = " << (*pc) << endl;
    Complex* tc=new Complex[100];
    
    
    cout << "c = " << c << endl;
    
    cout << "calcul c2+(*pc): ";
    Complex c3 = c2+(*pc);
    cout << "c3 = " << c3 << endl;
    cout << "calcul c2-(*pc): ";
    Complex c4 = c2-(*pc);
    cout << "c4 = " << c4 << endl;
    cout << "calcul c2x(*pc): ";
    Complex c5 = c2*(*pc);
    cout << "c5 = " << c5 << endl;    
    //cout << "calcul c2/(*pc): ";
    //Complex c6 = c2/(*pc);
    //cout << "c6 = " << c6 << endl;      

    Complex c9;
    cout << "Entrer un nombre complexe (r,i): ";
    cin >> c9;
    cout << "Vous avez entré: " << c9 << endl;
    
    delete pc;
    delete[] tc;
    
    return 0;
}

