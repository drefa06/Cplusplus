/* 
 * File:   main.cpp
 * Author: Formation
 *
 * Created on 13 janvier 2016, 14:16
 */

#include <cstdlib>
#include <iostream>

using namespace std;

/*
 *          +----------+
 *          | Polygone |
 *          +----------+
 *         /            \
 * +----------+     +-----------+
 * |  carré1  |     | rectangle |
 * +----------+     +-----------+
 *                        |
 *                  +----------+
 *                  |  carré2  |
 *                  +----------+
 */

class Polygone
{
private:
    int nombreCotes;
    int *lcote;
protected:
    Polygone(int n) { 
        nombreCotes=n; 
        lcote=new int[nombreCotes];
    }
public:
    virtual void init(int ne)
    {
        int l=0;
        for(int i=0;i<nombreCotes/ne;i++){
            cout << "Longueur coté " << i << ": ";
            cin >> l;
            lcote[i]=l;
        }
        
    }
    int getNombreCotes() {return nombreCotes; }
    void setLCote(int i,int val) {lcote[i]=val;}
    void dessiner() 
    { cout<<"Polygone à "<<nombreCotes<<" côtés";  }
    int perimetre()
    { 
        int p=0;
        for(int i=0;i<nombreCotes;i++){p+=lcote[i];}
        return p;
    }
    
};

class Carre1 : public Polygone
{
private:
    int couleur;
public:
    Carre1(int l) : Polygone(4)   //appel du constructeur de Carre avant d'executer son propre code.
                            //le constructeur de Polygone etant protected on peut l' appeler
                            //mais impossible de l'appeller de l'exterieur
    {
        for(int i=0;i<4;i++) setLCote(i,l);
        //nombreCotes=4; // plus possible car private, possible si protected ou public.
    }
    
    void dessiner()
    {
        Polygone::dessiner();
        cout<<" égaux, c'est un carré"<<endl;
    }
         
};

class Rectangle : public Polygone
{
private:
    int couleur;
public:
    Rectangle(int length,int width) : Polygone(4)
    {
        for(int i=0;i<2;i++) setLCote(i,length);
        for(int i=2;i<4;i++) setLCote(i,width);

        
    }
    
    void dessiner()
    {
        Polygone::dessiner();
        cout<<" égaux 2 à 2, c'est un rectangle"<<endl;
    }
         
};

class Carre2 : public Rectangle
{
private:
    int couleur;
public:
    Carre2(int l) : Rectangle(l,l)   //appel du constructeur de Carre avant d'executer son propre code.
                            //le constructeur de Polygone etant protected on peut l' appeler
                            //mais impossible de l'appeller de l'exterieur
    {
        for(int i=0;i<4;i++) setLCote(i,l);
        //nombreCotes=4; // plus possible car private, possible si protected ou public.
    }
    
    void dessiner()
    {
        Polygone::dessiner();
        cout<<" égaux, c'est un carré"<<endl;
    }
         
};
/*
 * 
 */
int main(int argc, char** argv) {
    cout << "Carré1: " << endl;
    Carre1 c1(2);
    c1.dessiner();
    cout << "Perimetre: " << c1.perimetre()<<endl; 
    
    cout << "Rectangle: " << endl;
    Rectangle r(2,4);
    r.dessiner();
    cout << "Perimetre: " << r.perimetre()<<endl; 
    
    cout << "Carré2: " << endl;
    Carre2 c2(3);
    c2.dessiner();
    cout << "Perimetre: " << c2.perimetre()<<endl; 

    return 0;
}

