	
/*
 * File:   main.cpp
 * Author: Formation
 *
 * Created on 16 décembre 2015, 14:35
 */
 
#include <cstdlib>
#include <iostream>
 
using namespace std;
 
 
static char bufferDuCapteur[]=
{22,1,1,  25,0,2,  20,0,3,  10,0,4,  0,0,0};
 
/*
 *
 */
 
 
struct CapteurInterne
{
    short temp;  // short = length 2 (word) -> 0 à 65535
                 // => NOTE: 22,1 sera lue comme 1 puis 22 donc en binaire byte1=0000 0001, byte2=00010110 => 278
    char numero; // char = length 1 (byte) -> 0 à 255
}
 __attribute__((packed)); // annulation alignement mémoire
 
class Basic1 { }; //taille = 1
class Basic2 {    //taille = 8
public:
    virtual void f() {};
};
class Basic3 {   //taille = 8
public:
    CapteurInterne *c;
};

class Capteur    //taille=16 = taille Basic2+Basic3
 {
 public:
     CapteurInterne *c;
     virtual void f() {};
 };
 
int main(int argc, char** argv) {
 
     
    cout<<"taille short="<<sizeof(short) << ", taille char="<<sizeof(char)<<endl;
    cout<<"taille CapteurInterne (1short+1char)="<<sizeof(CapteurInterne)<<endl;
    
    cout<<"taille Basic1="<<sizeof(Basic1)<<endl;
    cout<<"taille Basic2="<<sizeof(Basic2)<<endl;
    cout<<"taille Basic3="<<sizeof(Basic3)<<endl;
    cout<<"taille Capteur="<<sizeof(Capteur)<<endl;
    
    bool fini=false;
    Capteur masque;
    masque.c=(CapteurInterne *)bufferDuCapteur;
    do {
        if((masque.c->numero!=0)||(masque.c->temp!=0)) {
            cout<<"numéro "<<(int)masque.c->numero << " temp="<<masque.c->temp<<endl ;
        }
        else
            fini=true;
         
        masque.c++;
    } while(!fini);
     
     
     
    return 0;
}
