/* 
 * File:   pile.h
 * Author: Formation
 *
 * Created on 12 janvier 2016, 15:24
 */

#ifndef PILE_H
#define	PILE_H

#include <iostream>

class Pile
{
public:
    Pile(int capaciteMAX=100); //voir pile.cpp pour la definition
    ~Pile() { delete[] tableau; }
    
    Pile(const Pile& p){ // Constructeur d'initialisation
        initAffect(p);
    }
    Pile& operator=(const Pile& p){ //operateur d'affectation
        delete [] tableau; //necessaire car on a une capa max par defaut de 100
        initAffect(p);
        return *this;
    }

    void push(int);
    int pop();
    bool isEmpty() const;
    int getSize() const; // retourne le nombre d'entiers empilés
    
private:
    int *tableau;
    int dessus;
    int capaciteMAX;
    
    void initAffect(const Pile& p){
        dessus=p.dessus;
        capaciteMAX=p.capaciteMAX;
        tableau=new int[capaciteMAX];
        for(int i=0;i<=dessus;i++)
            tableau[i]=p.tableau[i];        
    }
    
    friend std::ostream& operator<<(std::ostream& os, const Pile& p); //necessaire pour acceder directement a tableau
};

std::ostream& operator<<(std::ostream& os, const Pile& p);

#endif	/* PILE_H */

