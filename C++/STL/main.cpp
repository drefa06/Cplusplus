/* 
 * File:   main.cpp
 * Author: Formation
 *
 * Created on 15 janvier 2016, 10:34
 */

#include <cstdlib>
#include <iostream>
#include <stack>
#include <vector>
#include <map>
#include <tuple>

#include <chrono>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    clock_t start;
    double duration;
    int taille = 100000000;
    try{
        
        //tableau taille définie (1000000) sans STL + init
        start = clock();
        cout<<"classic array of "<<taille<<endl;
        int* t11=new int[taille];
        int* t12=new int[taille];
        //remplissage
        for(int i=0;i<taille;i++)
            t11[i]=i;
        //soit on doit conserver la taille, soit on doit la recalculer
        //la recalculer necessite de mettre dans le tableau une valeur particuliere
        t11[taille]='\0';
        int s_t11=0;
        for(int i=0;t11[i]!='\0';i++) 
            s_t11++;
        //parcour et recopie de t11 dans t12
        for(int i=0;i<s_t11;i++) 
            t12[i]=2*t11[i];
        
        cout<<"taille de t12: "<<s_t11<<endl;
        duration = ( clock() - start ) / (double) CLOCKS_PER_SEC;
        cout<<"duration: "<< duration <<endl;
        
        //tableau vecteur STL
        start = clock();
        cout<<"vector of "<<taille<<endl;
        vector<int> t21,t22;
        //remplissage
        for(int i=0;i<taille;i++)
            t21.push_back(i);
        for(auto valCourante:t21) //taille connue
            t22.push_back(2*valCourante);
        cout<<"taille de t22: "<<t22.size()<<endl;
        duration = ( clock() - start ) / (double) CLOCKS_PER_SEC;
        cout<<"duration: "<< duration <<endl;
        
        
        cout<<endl;
        
        stack<int> p;
        for(int i=0;i<5;i++) p.push(i+1);
        
        vector<int> tableau1;
        vector<int> tableau2={1,2,3}; //init en meme temps que declaration en C++11
        
        cout<<tableau2[1]<<endl;
        tableau2[1]=123;
        cout<<tableau2[1]<<endl;
        cout<<"Taille de tableau2: "<<tableau2.size()<<endl;
        
        cout<<"Taille de tableau1: "<<tableau1.size()<<endl;
        tableau1.push_back(1234);
        cout<<"Taille de tableau1: "<<tableau1.size()<<endl;
        
        //parcours par iteration
        //forme classique
        cout<<"Parcours par iteration de tableau2:"<<endl;
        cout<<"Forme classique"<<endl;
        for(vector<int>::const_iterator valCourante=tableau2.begin();valCourante!=tableau2.end();++valCourante){
            cout<<(*valCourante)<<",";
        }
        cout<<endl;
        //forme C++11 (1))
        cout<<"Forme C++ (type1)"<<endl;
        for(auto valCourante=tableau2.begin();valCourante!=tableau2.end();++valCourante){
            cout<<(*valCourante)<<",";
        }
        cout<<endl;
        //forme C++11 (2))
        cout<<"Forme C++ (type2)"<<endl;
        for(auto valCourante:tableau2){
            cout<<valCourante<<","; //valCourante n'est plus un pointeur mais une reference
        }
        cout<<endl;
        
        map<string,string> myMap;
        myMap["ipServeur1"]="10.1.1.1";
        myMap["clef2"]="valeur2";
        cout << "{";
        for(auto v:myMap)
            cout << v.first<<"="<<v.second<<",";
        cout <<"}"<<endl;
        
        
        tuple<int,double,string> myTuple1(1, 2.3, "chaine");
        auto myTuple2=make_tuple(1, 2.3, "chaine");
        cout<<get<2>(myTuple2)<<endl;
        
        auto myTuple3 = tuple_cat(myTuple2,myTuple1);
        cout << "Tuple size: " << tuple_size<decltype(myTuple3)>::value << endl;
        cout << get<0>(myTuple3) << endl;
        cout << get<1>(myTuple3) << endl;
        cout << get<2>(myTuple3) << endl;
        cout << get<3>(myTuple3) << endl;
        cout << get<4>(myTuple3) << endl;
        cout << get<5>(myTuple3) << endl;
        
    }
    catch(exception &e){
        cerr<<"Erreur"<<endl;
    }

    
    return 0;
}

