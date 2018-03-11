#include "pile.h"
//
//std::ostream& operator<<(std::ostream& os, const Pile& p){
//    //ATTENTION: l'operateur reclame la variable p en tant que const
//    //OR on utilise getSize, il faut donc rajouter const dans la declaration de getSize
//    
//    //afficher la pile dans le sens fifo
//    os<<"(" << p.getSize() << " val): ";
//    for(int i=p.dessus;i>0;i--) os<<p.tableau[i]<<",";
//    os<<p.tableau[0];
//    
//    return os;
//}