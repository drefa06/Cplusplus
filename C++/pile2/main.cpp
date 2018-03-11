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




template <class T1>
T1 fct_get(const Pile<T1>& p,int pos){
    return p[pos];
}

template <class T2>
void fct_put(Pile<T2>& p,T2 val){
    p.push(val);
}

/*
 * 
 */
int main(int argc, char** argv) {
 
    //creation d'une pile generique de double
    cout<<"Create Pile<double> of 1 element"<<endl;
    Pile<double> p1(1);
    try {
        cout << "push 1 elem => OK"<<endl;
        p1.push(1.23);
        cout << "push 1 other elem => KO"<<endl;
        p1.push(2.23);
    }
    catch (exception& e) {
        cout << "print exception"<<endl;
        cout << e.what() << endl;
    }
    cout << "Pile p1("<<p1.getSize()<<" val) = "<<p1<<endl;
    
    cout << endl;
    
    //creation d'une pile generique de string
    cout<<"Create Pile<string> of 5 elements"<<endl;
    Pile<string> p2(5);
    cout << "push 4 elem => OK"<<endl;
    p2.push("Fabrice");
    p2.push("Aurelie");
    p2.push("Aromo");
    p2.push("Jacomo");
    cout << "Pile p2("<<p2.getSize()<<" val) = "<<p2<<endl;
    
    //retourner l'element p2[0]
    cout << "p2[" << 0 << "] = " << p2.ElemAtPos(0) << endl;
    //Pb
    //j'aimerai egalement faire un acces en ecriture avec la meme fonction
    cout << "Modifier l'element p2[" << 0 << "]" << endl;
    p2.ElemAtPos(0) = "toto";
    cout << "p2[" << 0 << "] = " << p2.ElemAtPos(0) << endl;
    
    try {
        cout << "push elem until exception"<<endl;
        for(;;) 
            p2.push("test");
    }
    catch(Pile<string>::PileError& e){//si on connais l'exception a rechercher, ici PileError
        cout << "specific exception treatment"<<endl;
        string s;
        s=(string)e.what();
        if (s.find(Pile<string>::PileError::BADPOP)) 
            cerr << "Bad POP" << endl;
        else
            cerr << e.what() << endl;
    }        
    catch(exception& e){ //ici on ne connais pas l'exception, on les catch toutes
        cout << "general exception treatment"<<endl;
        cerr << e.what() << endl;
    }        
        
    try {
        cout << "pop elem until exception"<<endl;
        for(;;) 
            p2.pop();
    }
    catch(Pile<string>::PileError& e){//si on connais l'exception a rechercher, ici PileError
        cout << "specific exception treatment"<<endl;
        string s;
        s=(string)e.what();
        if (s.find(Pile<string>::PileError::BADPOP)) 
            cerr << "Bad POP" << endl;
        else
            cerr << e.what() << endl;
    }        
    catch(exception& e){ //ici on ne connais pas l'exception, on les catch toutes
        cout << "general exception treatment"<<endl;
        cerr << e.what() << endl;
    } 

    try {
        cout<<"try to read elem at inexisting position"<<endl;
        cout << "p2[" << 10 << "] = " << p2[10] << endl;
    }
    catch(Pile<string>::PileError& e){//si on connais l'exception a rechercher, ici PileError
        cout << "specific exception treatment"<<endl;
        cerr << e.what() << endl;
    }
    catch(exception& e){ //ici on ne connais pas l'exception, on les catch toutes
        cout << "general exception treatment"<<endl;
        cerr << e.what() << endl;
    }
    
    try{
        cout<<"try to write elem at inexisting position"<<endl;
        p2[10]="tata";
        cout << "p2[" << 10 << "] = " << p2[10] << endl;
    }
     catch(Pile<string>::PileError& e){//si on connais l'exception a rechercher, ici PileError
        cout << "specific exception treatment"<<endl;
        cerr << e.what() << endl;
    }
    catch(exception& e){ //ici on ne connais pas l'exception, on les catch toutes
        cout << "general exception treatment"<<endl;
        cerr << e.what() << endl;
    }
    
    try{
        cout << "p1[" << 0 << "] = " << fct_get(p1,0) << endl;
        fct_put(p2,(string)"tata");
        cout << "p2[" << 0 << "] = " << fct_get(p2,0) << endl;
        fct_put(p1,5.55);
        cout << "p1[" << 0 << "] = " << fct_get(p1,0) << endl;
    }
     catch(Pile<string>::PileError& e){//si on connais l'exception a rechercher, ici PileError
        cout << "specific exception treatment"<<endl;
        cerr << e.what() << endl;
    }
    catch(exception& e){ //ici on ne connais pas l'exception, on les catch toutes
        cout << "general exception treatment"<<endl;
        cerr << e.what() << endl;
    }    
    
    cout <<endl;
    cout<<"Create a pile of pile of double"<<endl;
    Pile<Pile<string> > p3;
    p3.push(p2);
    p3.push(p2);
    cout << "Pile p3("<<p3.getSize()<<" val) = "<<p3<<endl;
    
    
    return 0;
}

