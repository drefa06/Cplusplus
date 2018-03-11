#include <iostream>

#include "fabrice2.hpp"

namespace fabrice2 {
    char buffer2[1024];

    void remplir2(){
        std::cout << "IN fabrice2::remplir" << std::endl;
        for(int i=0;i<sizeof(buffer2);i++) buffer2[i]=i; //sizeof permet d'avoir la juste taille de buffer quelquesoit le systeme (32, 64 bits, etc ...))
                                                       //sizeof retourne la valeur size_t
                                                       //dans ce cas sizeof return la taille du type (char = 1)* taille du tableau (1024) => 1024
        std::cout << "taille du buffer: " << sizeof(buffer2) << std::endl;
        
        std::cout << "OUT fabrice2::remplir" << std::endl;
    }
}
