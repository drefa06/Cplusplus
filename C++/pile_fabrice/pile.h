/* 
 * File:   pile.h
 * Author: Formation
 *
 * Created on 12 janvier 2016, 15:25
 */

#ifndef PILE_H
#define	PILE_H

#include <iostream>

class Pile {
private:
    int capaciteMAX;
    int first,last; //for lifo last is enough, for fifo need also first
    int * pile;
    
public:
    Pile(int capaciteMAX=20){
        this->capaciteMAX=capaciteMAX;
        pile = new int[capaciteMAX];
        
        first=0;
        last=0;
    }
    ~Pile(){
        delete [] pile;
    }
    
    int getSize() const  {return last-first;}
    int getFirst() const {return first;}
    int getLast() const  {return last;}
    int getElem(int pos){
        if (pos<first or pos>=last)
            return -1;
        else                          
            return pile[pos];
    }
    
    
    void push(int a){ //insert at end
        if (getSize()<capaciteMAX){
            pile[last] = a;

            last++;
        }
    }
    void add(int a){ //insert at beginning
        if (first>0 or getSize()<capaciteMAX){
            pile[first-1] = a;

            first--;
        }
    }    
    int pop(){ //lifo == pile, on retire le dernier
        if (! isEmpty()){
            int val = pile[last-1]; 
            
            last--;
            return val;
        }
    }
    int pull(){ //fifo == file, on retire le premier
        if (! isEmpty()){
            int val = pile[first]; 
            
            first++;
            return val;
        }
    }

    int insert(int a, int pos){
        if (pos<0 or getSize()==capaciteMAX)
            return -1;
        
        else if (pos > last+1)
            return -1;
        
        else if (pos==first-1)
            this->add(a);
        
        else if (pos==last+1)
            this->push(a);
        
                           
        else if (pos<first){
            pile[pos]=a;

            for(int i=pos+1;i<first;i++) 
                pile[pos]=0;
            first=pos;
        }
        else if (pos>last+1){
            pile[pos]=a;

            for(int i=last+1;i<pos;i++) 
                pile[pos]=0;
            
            last=pos;
        }        
        
        else {
            for(int i=last-1;i>=pos;i--) 
                pile[i+1]=pile[i];
            pile[pos]=a;
            last++;
        }
    }
    
    int remove(int pos){
        if (pos<first or pos>=last)
            return -1;
        else {
            int val=pile[pos];
            for(int i=pos+1;i<last;i++)
                pile[i-1]=pile[i];
            last--;
            return val;
        }
           
    }
    
    bool isEmpty(){
        if (getSize()==0) return true;
        return false;
    }
    
    void print(){
        std::cout<<"["<<first<<","<<last-1<<"]{";
        for(int i=first;i<last-1;i++){
            std::cout<<pile[i]<<",";
        }
        std::cout<<pile[last-1]<<"}";
    }
    
    friend std::ostream& operator<<(std::ostream& os, const Pile& p);
};

std::ostream& operator<<(std::ostream& os, const Pile& p){
    //ATTENTION: l'operateur reclame la variable p en tant que const
    //OR on utilise getSize, il faut donc rajouter const dans la declaration de getSize
    
    //afficher la pile dans le sens fifo
    os<<"["<<p.getFirst()<<","<<p.getLast()-1<<"]={";
    for(int i=p.getFirst();i<p.getLast()-1;i++) os<<p.pile[i]<<",";
    os<<p.pile[p.getLast()-1]<<"}(" << p.getSize() << " val)";
}
#endif	/* PILE_H */

