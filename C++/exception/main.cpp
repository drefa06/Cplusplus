/* 
 * File:   main.cpp
 * Author: Formation
 *
 * Created on 14 janvier 2016, 14:48
 */

#include <cstdlib>
#include <iostream>

//EN C on a besoin de:
#include <stdio.h> //utile a FILE en C
#include <errno.h> //utile a la gestion d'erreur en C

#include <fstream>
#include <string>
using namespace std;
/*
 * 
 */
class monException : public exception {
public:
    const char* what() const throw(){
        return "Mon Exception";
    }
    const char* plusInfo() const {
        return "Il y a eu une erreur que moi seul connait";
    }

};

istream& operator>> (istream& is, ifstream& f){
    string s;
    is>>s;
    getline(f, s); // getline from <string>
    is.ignore(1024, '\n'); // after reading the loanAmount, skip the trailing '\n'
    return is;
}       
  

//void maFonction(){ // ca marche, mais on peut aussi preciser les exceptions des la def de la fonction
void maFonction(char* Fname) throw (monException,ifstream::failure) { //but informatif danss la declaration dans le fichier H
    
    try
    {
        ifstream file(Fname, ifstream::in);
        file.exceptions(ifstream::eofbit | ifstream::failbit | ifstream::badbit);

        try {
            string s;
            int nbLine=0;
            while (getline(file,s)){
                nbLine++;
                if(nbLine==10){throw monException();}
            }
            
        }
        catch (monException& e){
            cout << e.what() << endl;
            cerr << e.plusInfo() << endl;
        }
        catch (ifstream::failure& e) {
            if (file.rdstate() & ifstream::eofbit) {
                cout << "EOF reached." << endl;
            }
            cout << e.what();
        }
        
    }
    catch (ifstream::failure& e) {
        cout << "Error: Failure to open file " << Fname << endl;
        cout << e.what() << endl;
    }
}

int main(int argc, char** argv) {

    //gestion d'erreur en C
    cout << "Gestion d'erreur en C: fichier inexistant"<<endl;
    FILE * f1=fopen("f.txt","r");
    if(f1==NULL){
        cerr<<"Num d'err: "<<errno<<endl;
        cerr<<"Msg d'err: "<<sys_errlist[errno]<<endl;
        
        cout<<"La on exit"<<endl;
        //exit(1);
    }
    fclose(f1);
    cout<<endl;
    
    //gestion d'erreur en C++
    cout << "Gestion d'erreur en C++"<<endl;
    cout << "Test avec C:/windows/system32/drivers/etc/hosts"<<endl;
    char* F1 = "C:/windows/system32/drivers/etc/hosts";
    maFonction(F1);
    cout<<endl;
    cout << "Test avec C:/windows/system32/drivers/etc/hosts"<<endl;
    char* F2 = "C:/windows/system32/drivers/etc/hosts2";
    maFonction(F2);
    cout<<endl;
    
/*    try {
        ifstream f1;
        ios_base::iostate exceptionMask = f1.exceptions();
        f1.exceptions ( exceptionMask | ifstream::failbit );

        f1.open ("C:/windows/system32/drivers/etc/hosts");
        f1.exceptions(exceptionMask);
        string s1;
        while (!f1.eof()) {getline(f1,s1);cout << s1 << endl;};
        
    }
    catch (exception &e) {
        cout << "Error: " <<e.what() << endl;
    }    
   
    ifstream f2("C:/windows/system32/drivers/etc/hosts2");
    string s2;
    do { f2>>s2; } while (!f2.eof());
    cout << s2 << endl;
*/
    
    return 0;
}

