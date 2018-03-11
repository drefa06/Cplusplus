/* 
 * File:   master_mind.h
 * Author: Formation
 *
 * Created on 15 janvier 2016, 14:09
 */

#ifndef MASTER_MIND_H
#define	MASTER_MIND_H

#include <cstdlib>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

struct Result {
    Pion pion;
    enum statusPossible {
        GOOD = 0,
        BAD,
        MISPLACED
    };
    statusPossible status;
};

class Pion
{
public:
    enum pionCouleur {
            ROUGE = 0,
            BLEU,
            VERT,
            JAUNE,
            GRIS,
            NOIR,
            BLANC,
            _
        };
        
    pionCouleur couleur;
    string couleurName;  

    Pion(){
        pionCouleur c = pionCouleur(rand()%7);
        couleur = c;
        couleurName = toString(c);
    }
    
    Pion(pionCouleur c){
        couleur = c;
        couleurName = toString(c);  
    }
    Pion(string s){
        couleurName = s;  
        couleur = fromString(s);
    }
    
    pionCouleur getCouleur(){
        return couleur;
    }
    string getCouleurName() const {
        return couleurName;
    }
    
    string toString(pionCouleur pc)
    {
       switch (pc)
       {
          case ROUGE: { return "rouge"; }
          case BLEU:  { return "bleu";  }
          case VERT:  { return "vert";  }
          case JAUNE: { return "jaune"; }
          case GRIS:  { return "gris";  }
          case NOIR:  { return "noir";  }
          case BLANC: { return "blanc"; }
          case _:     { return "..."; }
       }
       return "invalid";
    }

    pionCouleur fromString(string s)
    {
        if (s == "rouge") { return ROUGE; }
        else if (s == "bleu")  { return BLEU; }
        else if (s == "vert")  { return VERT; }
        else if (s == "jaune") { return JAUNE; }
        else if (s == "gris")  { return GRIS; }
        else if (s == "noir")  { return NOIR; }
        else if (s == "blanc") { return BLANC; }
        else if (s == "...")   { return _; }
    }

};

class Code{
public:
    vector<Pion> code;
    
    Code(){}
    
    int getNbrPion() const {
        return code.size();
    }
       
    void addPion(){
        Pion p;
        code.push_back(p);
    }

    void addPion(Pion p){
        code.push_back(p);
    } 
        
    Code comparer(Code s){
        Code res;
        bool find;
        for(int i=0;i<4;i++){
            find=false;
            for(int j=0;j<4;j++){
                if (code[i].getCouleurName()==s.code[j].getCouleurName()){
                    if (i==j){
                        Pion p(Pion::pionCouleur::NOIR);
                        res.addPion(p);
//                        delete p;
                    }
                    else {
                        find=true;
                    }
                
                }
            }
            if (find){
                Pion p(Pion::pionCouleur::BLANC);
                res.addPion(p);
//                delete p;
            }
            else {
                Pion p(Pion::pionCouleur::_);
                res.addPion(p);
//                delete p;
            }
        }
        
        return res;
    }
};


ostream & operator<<(ostream& o, const Code& c);

#endif	/* MASTER_MIND_H */

