/* 
 * File:   main.cpp
 * Author: Formation
 *
 * Created on 11 janvier 2016, 09:41
 */

#include <cstdlib>
#include <iostream>  //indispensable pour cout, cin, cerr
using namespace std; //permet d'ecrire directement cout
                     //si on n'utilise pas ce using namespace on serait obligé d'ecrire std::cout
#include "fabrice2.hpp"
using namespace fabrice2;
static int buffer3[10]; //static => variable globale uniquement pour ce fichier

namespace fabrice {
    char buffer[1024];
    // char taille = 1
    // short         2
    // int           depend de la cible
    // long          4
    // long long     8
    void remplir(){
        cout << "IN fabrice::remplir" << endl;
        for(int i=0;i<sizeof(buffer);i++) buffer[i]=i; //sizeof permet d'avoir la juste taille de buffer quelquesoit le systeme (32, 64 bits, etc ...))
                                                       //sizeof retourne la valeur size_t
                                                       //dans ce cas sizeof return la taille du type (char = 1)* taille du tableau (1024) => 1024
        cout << "taille du buffer: " << sizeof(buffer) << endl;
        
        cout << "OUT fabrice::remplir" << endl;
    }
}

/*
 * 
 */
int main(int argc, char** argv) {
    string reponse;
    
    //Helloworld
    cout << "Test Helloworld" << endl;
    
    cout << endl << "Quel est ton prenom?: ";
    cin >> reponse;
    cout << "Bonjour " << reponse << " tu vas bien? (y|n)";
    cin >> reponse;
    //if statement classic
    if(reponse=="y"){
        cout << "super! bonne journée alors" << endl;
    }
    else {
        cout << "dommage!" << endl;
    }
    //inline operator ?
    cout << ( (reponse=="y")? "yes": "no") << endl;
    
    cout << "Do you want to proceed for next test? (Y|n)";
    cin >> reponse;
    if (reponse=="n") return 0;

    
    //types
    int n,a,b;
    cout << endl << "Test de types" << endl;
    cout << "Entres un chiffre: ";
    cin >> a;
    cout << "Entres un autre chiffre: ";
    cin >> b;
    cout << "Resultat: (Entier)      " << a+b << endl;
    cout << "          (Hexadecimal) " << "0x" << hex << a+b << dec << endl;
    cout << "          (Octal)       " << "0c" << oct << a+b << dec << endl;
    //cout << "          (Binary)     " << "b" << bin << a+b << dec << endl; //ERROR: bin  does not exist like dec, hex and oct
    
    cout << "\nUtilisation d'un namespace local" << endl;
    fabrice::remplir();
    cout << "Contenu de buffer: ";
    for(int i=0;i<10;i++) cout << (int)fabrice::buffer[i];
    cout << endl;
    
    cout << "\nUtilisation d'un namespace ailleur (dans fabrice2.cpp et .hpp)" << endl;
    remplir2();
    cout << "Contenu de buffer2: ";
    for(int i=0;i<10;i++) cout << (int)buffer2[i] << ",";
    cout << endl;

    remplir3(); //utilisation de inline
    cout << "Contenu de buffer2: ";
    for(int i=0;i<10;i++) cout << (int)buffer2[i] << ",";
    cout << endl;    
    //Typage fort
    //toute fonction doit returner quelquechose avec un type definie
    
    return 0;
}

