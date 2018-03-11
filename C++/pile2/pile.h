/* 
 * File:   pile.h
 * Author: Formation
 *
 * Created on 12 janvier 2016, 15:24
 */

#ifndef PILE_H
#define	PILE_H

#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <memory>
#include <string>
#include <sstream>

#include <exception>
using namespace std;

template <class T>
class Pile
{
public:
    
    //creation d'une exception de Pile
    //c'est une sous classe de Pile MAIS qui n'accede pas aux elements de Pile
    class BadIndex : public exception{
        protected:
            int badIndex,tailleCourante;
        public:
            BadIndex(int n,int taille){
                badIndex=n;
                tailleCourante=taille;
            }
            const char* what() const throw() {
//                char* s = new char[1000]; //pb du delete ... necessite du unique_ptr
                ostringstream os;
                os<<"Acces a l'indice "<<badIndex<<" pour une Pile de taille "<<tailleCourante;
                string s = os.str();
                return s.c_str();
            }
    };

//Si on veut gerer plusieur exception comme BadIndex, il faut creer autant de sous-classe
//    class BadPush : public exception{
//    public:
//        const char* what() const throw() { 
//            return "Impossible to push new element";
//        }
//    };
//    class BadPop : public exception{
//    public:
//        const char* what() const throw() {
//            return "Impossible to pop element";
//        }
//    };
//
//On peut aussi creer une sous-classe plus generique     
    class PileError : public exception{
    protected:
        string errStr;
        
    public:
        enum errType{
            BADINDEX,
            BADPOP,
            BADPUSH,
        };

        PileError(errType err,string opt=""){
            switch(err)
            {
                case errType::BADINDEX: errStr = "(BADINDEX) Bad index: "+opt; break;
                case errType::BADPOP:   errStr = "(BADPOP) Impossible to pop element"; break;
                case errType::BADPUSH:  errStr = "(BADPUSH) Impossible to push new element"; break;
                default: break;
            }
        }
        
        const char* what() const throw() {
            return errStr.c_str();
        }
    };


    Pile(int capaciteMAX=100) {
        this->capaciteMAX=capaciteMAX;
        dessus=-1;
        tableau=new T[capaciteMAX];
    }
    ~Pile() { delete[] tableau; }
    
    Pile(const Pile& p){ // Constructeur d'initialisation
        initAffect(p);
    }
    Pile& operator=(const Pile& p){ //operateur d'affectation
        delete [] tableau; //necessaire car on a une capa max par defaut de 100
        initAffect(p);
        return *this;
    }

    void push(T n) {
        if (getSize()>=capaciteMAX)
            throw PileError(PileError::BADPUSH);
        tableau[++dessus]=n;         
    }
    
    T pop() {
        //if (dessus<0) throw BadPop();
        if (dessus<0) 
            throw PileError(PileError::BADPOP);
            //throw BadPop();
        return tableau[dessus--];
    }
    
    bool isEmpty() const  {return dessus==-1;}
    int getSize() const   {return dessus+1;}     // retourne le nombre d'entiers empilés
    
    //T ElemAtPos(int pos)  {return tableau[pos];} //lecture seule
    T& ElemAtPos(int pos) {return tableau[pos];}//en retournant un reference on peut egalement ecrire
    //si on sait faire ce genre de fonction, on peut egalement surcharger l'operateur []
    T& operator[](int pos)      {
        cout<<"version ref non const"<<endl; 
        if((pos<0)||(pos>=getSize())) 
            throw PileError(PileError::BADINDEX,to_string(pos));
            //throw BadIndex(pos,getSize()); //exception si on veut un element qui n' est pas dans ma pile
        return tableau[pos];
    }
    T operator[](int pos) const {
        cout<<"version non ref const"<<endl;
        if((pos<0)||(pos>=getSize())) 
            throw PileError(PileError::BADINDEX,to_string(pos));
        return tableau[pos];
    } //necessaire pour les cas d'accesseur non reference const
    
private:
    T *tableau;
    int dessus;
    int capaciteMAX;
    
    void initAffect(const Pile& p){
        dessus=p.dessus;
        capaciteMAX=p.capaciteMAX;
        tableau=new T[capaciteMAX];
        for(int i=0;i<=dessus;i++)
            tableau[i]=p.tableau[i];        
        }
    
    friend std::ostream& operator<<(std::ostream& os, const Pile<T>& p){
        os<<"[";
        for(int i=p.dessus;i>0;i--) os<<p.tableau[i]<<",";
        os<<p.tableau[0]<<"]";
    
        return os;
        }
};

template <>
class Pile<char>{ //specialisation de classe generique pour un type particulier ici <char>
    //reecrire tout pour le cas <char> =>EX ecrire sous form 0x..

};
   
#endif	/* PILE_H */

