/* 
 * File:   rationnel.h
 * Author: Formation
 *
 * Created on 12 janvier 2016, 09:18
 */

#ifndef RATIONNEL_H
#define	RATIONNEL_H

#include <iostream>
#include <string>

using namespace std;

class Rationnel {
public:
    float valeur;
    
private:
    int numerateurInit,denominateurInit;
    int numerateur,denominateur;
    int facteur;
    int pgcd;
    
    static int nbrInstances; //un membre static necessite une initialisation 
                        //declaration => donc pas d' allocation memoire
    
public:
    //une fonction/class amie a alors acces a tous les membres de cette classe
    //ce n' est pas bijectif, si on veut que rationnel ait acces a tous les membre de autre, il faut egalement la declarer dans autre
    // => pour que operator>> puisse acceder a numerateur et denominateur, il faut donc la declarer en friend 
    friend std::istream & operator>>(std::istream& i, Rationnel& r){
        string s;
        i>>s;
        
        Rationnel tmp(s);
        r=tmp;
    
        return i;
    }
    // friend class autre;
    
    //Creation d'un constructeur => fonction membre qui porte le nom de la classe.
    //Le constructeur n' a pas de type de retour (meme pas void)  
    Rationnel(int n=0,int d=1){
        init(n,d);
    }
    Rationnel(std::string s){
        nbrInstances++;
        int n,d;
        
        std::size_t found = s.find('/');
        if (found!=std::string::npos)
            std::sscanf(s.c_str(),"%d/%d",&n,&d);
        else {
            n=std::stoi(s);
            d=1;
        }
        
        init(n,d);
    }
    ~Rationnel(){nbrInstances--;}
    
    //Init
    void init(int n,int d){
        if (d<0){
            numerateurInit=-n;
            denominateurInit=-d;
            }
        else {
            numerateurInit=n;
            denominateurInit=d;
        }
        
        factorize();
        pgcd = calcPgcd(numerateurInit,denominateurInit);
    }
    
    //Accesseur sur la variable privée
    int getNumerateur()   const { return this->numerateur;}
    int getDenominateur() const { return this->denominateur;}
    int getNumerateurInit()   const { return this->numerateurInit;}
    int getDenominateurInit() const { return this->denominateurInit;}
    int getPgcd() const { return this->pgcd;}
    int getFacteur() const { return this->facteur;}
    //une fonction membre static ne peut acceder qu'a des donnees membres statiques
    static int getNbrInstances(){return nbrInstances;}
    
    string printable() const {
        string s;
        if (this->getNumerateur()==0) 
            s = "0";
        else if (this->getNumerateur() == this->getDenominateur()) 
            s = "1";
        else if (this->getDenominateur() == 1) 
            s = to_string(this->getNumerateur());
        else {
            if ((this->getNumerateurInit()==this->getNumerateur())||(this->getFacteur()==1))
                s = to_string(this->getNumerateur()) + "/" + to_string(this->getDenominateur());
            else
                s = to_string(this->getFacteur()) + "*" + to_string(this->getNumerateur()) + "/" + to_string(this->getDenominateur());
            }
        return s;
    }
    
    
    
    int calcPgcd(int x,int y) const {
        if(x%y==0) return y;
        return calcPgcd(y,x%y); //base case,return x when y equals 0
    }
    
    void factorize(){
        pgcd=calcPgcd(numerateurInit,denominateurInit);
        if (pgcd <0) pgcd=-pgcd;
        numerateur=numerateurInit/pgcd;
        denominateur=denominateurInit/pgcd;
        facteur=1;
    }
    
    Rationnel operator+(const Rationnel& b) const {
        return Rationnel(numerateur*b.denominateur+denominateur*b.numerateur,denominateur*b.denominateur);
    }
    Rationnel operator-() const { //negation de this
        return Rationnel(-numerateur,denominateur);
    }
    Rationnel operator-(const Rationnel& b) const {
        Rationnel res = -b+(*this);
        return res;
        //return Rationnel(numerateur*b.denominateur-denominateur*b.numerateur,denominateur*b.denominateur);
    }
    Rationnel operator*(const Rationnel& b) const {
        return Rationnel(numerateur*b.numerateur,denominateur*b.denominateur);
    }
    Rationnel operator/(const Rationnel& b) const {
        return Rationnel(numerateur*b.denominateur,denominateur*b.numerateur);
    }

    //Incrementation
    //prefixe: r=++b => 
    Rationnel& operator++() { //ne pas mettre const car l'operateur va modifier les attributs de la classe
        numerateurInit+=denominateurInit;
        init(numerateurInit,denominateurInit);
        return *this;
    }
    //postfixe: r=b++ => 
    Rationnel operator++(int n) {
        //le param n ne sert a rien, sauf au compilateur a differencier entre les 2 operateur ++
        Rationnel res = *this;
        numerateurInit+=denominateurInit;
        init(numerateurInit,denominateurInit);
        return res;
    }

};

class Complex {
public:
    float valeur;
    
private:
    int facteur=1;
    Rationnel reel,imaginaire;
    
    static int nbrInstances; //un membre static necessite une initialisation 
                        //declaration => donc pas d' allocation memoire
    
public:

    Complex(Rationnel reel=Rationnel(),Rationnel imaginaire=Rationnel()){
        nbrInstances++;
        
        this->reel=reel;
        this->imaginaire=imaginaire;
    }
    ~Complex(){nbrInstances--;}
    
    void factorize(){
        Rationnel r;
        this->facteur=r.calcPgcd(reel.getPgcd(),imaginaire.getPgcd());
        this->reel=reel/this->facteur;
        this->imaginaire=imaginaire/this->facteur; 
    }
    
    //Accesseur sur la variable privée
    Rationnel getReel()   const { return this->reel;}
    Rationnel getImaginaire() const { return this->imaginaire;}
    //une fonction membre static ne peut acceder qu'a des donnees membres statiques
    static int getNbrInstances(){return nbrInstances;}
    
    Complex operator+(const Complex& b) const {
        return Complex(reel+b.reel,imaginaire+b.imaginaire);
    }
    Complex operator-() const { //negation de this
        return Complex(-reel,-imaginaire);
    }
    Complex operator-(const Complex& b) const {
        return Complex(reel-b.reel,imaginaire-b.imaginaire);
    }
    Complex operator*(const Complex& b) const {
        return Complex(reel*b.reel-imaginaire*b.imaginaire,reel*b.imaginaire+imaginaire*b.reel);
    }
    //Complex operator/(const Complex& b) const {
    //    return Complex(this,b);
    //}
};

std::ostream & operator<<(std::ostream& o, const Rationnel& r);
std::istream & operator>>(std::istream& i, Rationnel& r);

std::ostream & operator<<(std::ostream& o, const Complex& r);
std::istream & operator>>(std::istream& i, Complex& r);

#endif	/* RATIONNEL_H */

