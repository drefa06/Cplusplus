/* 
 * File:   fabrice2.hpp
 * Author: Formation
 *
 * Created on 11 janvier 2016, 10:46
 */

#ifndef FABRICE2_HPP
#define	FABRICE2_HPP

namespace fabrice2 {
    extern char buffer2[1024];
    void remplir2();
    inline void remplir3(){ // inline impossible en C, ATTENTION CE CODE VA REMPLACER remplir3 PARTOUT DANS LE CODE => risque de pb RAM
        for(int i=0;i<sizeof(buffer2);i++) buffer2[i]=2*i;
    }
}

#endif	/* FABRICE2_HPP */

