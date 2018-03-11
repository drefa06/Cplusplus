#include "pile.h"

Pile::Pile(int capaciteMAX) {
    this->capaciteMAX=capaciteMAX;
    dessus=-1;
    tableau=new int[capaciteMAX];
}

int Pile::getSize() const {
    return dessus+1;
}

void Pile::push(int n) {
    tableau[++dessus]=n;
}

int Pile::pop() {
    return tableau[dessus--];
}

bool Pile::isEmpty() const {
    return dessus==-1;
}


std::ostream& operator<<(std::ostream& os, const Pile& p){
    //ATTENTION: l'operateur reclame la variable p en tant que const
    //OR on utilise getSize, il faut donc rajouter const dans la declaration de getSize
    
    //afficher la pile dans le sens fifo
    os<<"(" << p.getSize() << " val): ";
    for(int i=p.dessus;i>0;i--) os<<p.tableau[i]<<",";
    os<<p.tableau[0];
}