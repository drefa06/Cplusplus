/* 
 * File:   main.cpp
 * Author: Formation
 *
 * Created on 15 janvier 2016, 14:07
 */

#include <cstdlib>
#include <iostream>

#include "master_mind.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    //Pion p1(Pion::pionCouleur::ROUGE);
    //Pion p2(Pion::pionCouleur::VERT);
    //Pion p3(Pion::pionCouleur::BLEU);
    //Pion p4(Pion::pionCouleur::JAUNE);

    Code secret;
    secret.addPion();
    secret.addPion();
    secret.addPion();
    secret.addPion();
    cout<<"Code Secret: "<<secret<<endl;
    
    Code proposition;
    proposition.addPion();
    proposition.addPion();
    proposition.addPion();
    proposition.addPion();
    cout<<"Proposition: "<<proposition<<endl;
    
    Code result = proposition.comparer(secret)
    cout<<"Resultat: "<<result << endl;
    
    vector<Result> res;
    for (int i=0; i<4; i++){
        Result r;
        r.pion = result.code[i];
        if (result.code[i] == Pion::pionCouleur::BLANC){
            r.status=Result::statusPossible::MISPLACED;
        } else if (result.code[i] == Pion::pionCouleur::NOIR){
            r.status=Result::statusPossible::GOOD;
        } else {
            r.status=Result::statusPossible::BAD;
        }
        
        res.push_back(r);
    }
    
    
    return 0;
}

