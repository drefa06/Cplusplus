#include <iostream>

#include "master_mind.h"

using namespace std;

ostream & operator<<(ostream& o, const Code& c){  
    for(int i=0;i<c.getNbrPion();i++){
        o<<c.code[i].getCouleurName()<<",";
    }
    return o;
}
