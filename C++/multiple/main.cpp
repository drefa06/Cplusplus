/* 
 * File:   main.cpp
 * Author: Formation
 *
 * Created on 14 janvier 2016, 11:28
 */

#include <cstdlib>
#include <iostream>
using namespace std;

/*         +-----------------+ +------------+
 *         |      Base       | | Comparable |
 *         +-----------------+ +------------+
 *         /       \       \     /
 *  +--------+ +--------+ +-------+ 
 *  | Fils1  | | Fils2  | | C1    |
 *  +--------+ +--------+ +-------+ 
 *         \    /
 *       +--------+
 *       | Strange|
 *       +--------+
 */ 


struct Base {
    int n;
};

struct Fils1 :  virtual public Base
{
    int valeur;
};
struct Fils2 :  virtual public Base
{
    int valeur;
};
struct Strange :virtual public Fils1,virtual public Fils2
{
    void f1(int val) { 
        n=val; 
        Fils1::valeur=val-1; 
        Fils2::valeur=val+1;
    }
    void f2() {cout<<n<<","<<Fils1::valeur<<","<<Fils2::valeur<<endl; }
};


struct Comparable {
    virtual bool operator==(Comparable&) =0;
    virtual bool operator!=(Comparable&) =0;
};


struct C1 :public Base,public Comparable
{
    int val;
    C1() { val=123; }
    bool operator==(Comparable& c) { return true;}
    bool operator!=(Comparable& c) { return false;}
};

template<class T>
bool isEqual(T p1,T p2)
{
    static_assert(std::is_base_of<Comparable, T>::value, "Le paramètre de utile() doit dériver de Comparable");
    bool b= p1==p2;
    return b;
}
template<class T>
bool isDiff(T p1,T p2)
{
    static_assert(std::is_base_of<Comparable, T>::value, "Le paramètre de utile() doit dériver de Comparable");
    return p1!=p2;
}


int main(int argc, char** argv) {
    cout<<"Ex1: diamond"<<endl;
    cout<<"Create b,f1,f2 and s"<<endl;
    Base b;
    Fils1 f1;
    Fils2 f2;
    Strange s;
    
    cout<<"init f1.n and f2.n"<<endl;
    f1.n=5;
    cout<<"f1.n="<<f1.n<<endl;
    f2.n=10;
    cout<<"f2.n="<<f2.n<<", f1.n="<<f1.n<<endl;
    
    cout<<"init f1.valeur and f2.valeur"<<endl;
    f1.valeur=1;
    f2.valeur=2;
    cout<<"f1.valeur="<<f1.valeur<<", f2.valeur="<<f2.valeur<<endl;

    cout<<"init s.n, s.Fils1::valeur and s.Fils2::valeur"<<endl;
    s.n=20;
    s.Fils1::valeur=50;
    s.Fils2::valeur=100;
    cout<<"s.n="<<s.n<<", s.Fils1::valeur="<<s.Fils1::valeur<<", s.Fils2::valeur="<<s.Fils2::valeur<<endl;
    cout<<"apply s.f1 and s.f2"<<endl;
    s.f1(75);
    s.f2();
    cout<<"s.n="<<s.n<<", s.Fils1::valeur="<<s.Fils1::valeur<<", s.Fils2::valeur="<<s.Fils2::valeur<<endl;
    
    cout<<"Ex2: "<<endl;
    C1 obj1,obj2;
    cout<<"obj1 = "<<&obj1<<", obj2 = "<<&obj2<<endl;
    cout<<"isEqual(obj1,obj2)="<<isEqual(obj1,obj2)<<endl; //fonctionne car C1 derive de comparable
    cout<<"isDiff(obj1,obj2)="<<isDiff(obj1,obj2)<<endl; //fonctionne car C1 derive de comparable


    obj1.val=111;
    obj2.val=222;
    cout<<"isEqual(obj1,obj2)="<<isEqual(obj1,obj2)<<endl; //fonctionne car C1 derive de comparable
    cout<<"isDiff(obj1,obj2)="<<isDiff(obj1,obj2)<<endl; //fonctionne car C1 derive de comparable

    //cout<<"isEqual(obj1,f1)="<<isEqual(obj1,f1)<<endl; //ne compile pas car Fils1 ne derive pas de comparable
    //cout<<"isDiff(obj1,f1)="<<isDiff(obj1,f1)<<endl; //ne compile pas car Fils1 ne derive pas de comparable
    
   //utile(b); //ne fonctionne pas car b ne derive pas de comparable
  
    return 0;
}