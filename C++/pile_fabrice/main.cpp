/* 
 * File:   main.cpp
 * Author: Formation
 *
 * Created on 12 janvier 2016, 15:24
 */

#include <cstdlib>
#include <iostream>
#include "pile.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    Pile p1;
    cout << "begining size = " << p1.getSize() << endl;
    
    cout << "Add 22 elements"<< endl;
    for (int i=0;i<22;i++){
        p1.push(i*2);
    }
    cout << "size after push = " << p1.getSize() << endl;
    cout << "empty?" << (bool)p1.isEmpty() << endl;
    cout << "content of pile:"<<endl;
    p1.print();
    cout <<endl;
    cout<<p1<<endl; //surcharge operateur <<
    
    cout <<endl;
    
    cout << "Remove last elements (pop):"<< p1.pop() << endl;
    cout << "size after pop = " << p1.getSize() << endl;
    cout << "Remove first elements (pull):"<< p1.pull() << endl;
    cout << "size after pull = " << p1.getSize() << endl;
    cout << "Remove 10th elements (remove):"<< p1.remove(10) << endl;
    cout << "size after remove = " << p1.getSize() << endl;
    
    cout << "content of pile:"<<endl;
    p1.print();
    
    cout <<endl;

    cout << "Remove first elements (pull):"<< p1.pull() << endl;    
    cout << "Remove first elements (pull):"<< p1.pull() << endl;
    cout << "Remove first elements (pull):"<< p1.pull() << endl;
    cout << "Remove first elements (pull):"<< p1.pull() << endl;
    cout << "Remove first elements (pull):"<< p1.pull() << endl;
    cout<<p1<<endl;
    
    cout << "Add 1000 at 5th, then 10th and finally 15th position:"<<endl;
    p1.insert(1000,5);
    p1.insert(1000,0);
    p1.insert(1000,10);
    p1.insert(1000,15);
    cout << "size after insert = " << p1.getSize() << endl;
    
    cout << "content of pile:"<<endl;
    p1.print();
    
    cout <<endl;
    
    
    
    cout << "Remove all elements from end"<< endl;
    while (p1.getSize()>0){
        cout <<p1.pop() << endl;
    }
    cout << endl;
    cout << "size after pop = " << p1.getSize() << endl;
    cout << "empty?" << (bool)p1.isEmpty() << endl;
   
    cout << "Add 1 element"<<endl;
    p1.push(1024);
    for (int i=0;i<2;i++){
        cout<<"get pile["<<i<<"]=";
        int val=p1.getElem(i);
        if (val==-1){
            std::cerr << "does not exist, pos " << i << " not in ["<<p1.getFirst()<<"," << p1.getLast()-1 << "]";
            exit(1);
        }
        else cout << val << endl;
    }
    
    return 0;
}

