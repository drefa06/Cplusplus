/* 
 * File:   main.cpp
 * Author: Formation
 *
 * Created on 13 janvier 2016, 15:04
 */

#include <cstdlib>
#include <iostream>
#include <typeinfo>
using namespace std;

class Vehicule
{
protected:
    int vitesseMAX;
    int vitesseCourante;
    int nbrEssieux;

public:
    Vehicule(int vitesseMAX){
        this->vitesseMAX=vitesseMAX;
        vitesseCourante=0;
        nbrEssieux=0;
    }
            
    int getVitesseMAX()     {return vitesseMAX;}
    int getViteseCourante() {return vitesseCourante;}
    
    //avec virtual ce sera la methode de la classe fille qui sera appelée
    virtual void accelerer() =0;
    virtual void freiner()=0;  //=0 va interdire de creer un vehicule
};

class Voiture : public Vehicule
{
protected:
    bool bride;
public:
    int acceleration;
    int freinage;
    
    Voiture() : Vehicule(200){
        this->nbrEssieux=2;
        acceleration=25;
        freinage=10;
        bride=true;
    }

    int getNbrEssieux() {return nbrEssieux;}
    bool getBride(){return bride;}
    
    void brider(){bride=true;vitesseMAX=vitesseMAX-50;}
    void debrider(){bride=false;vitesseMAX=vitesseMAX+50;}
    
    void accelerer() {
        if (vitesseCourante+acceleration<vitesseMAX) vitesseCourante=vitesseCourante+acceleration;
        else if (vitesseCourante<vitesseMAX)         vitesseCourante=vitesseMAX;
    }
    void freiner()   {
        if (vitesseCourante-freinage>0) vitesseCourante=vitesseCourante-freinage;
        else if (vitesseCourante>0)     vitesseCourante=0;
    }
    
};
class VoitureDeSport : public Voiture
{
private:
    //le voiture de sport est naturellement debridee, si on choisi de rendre impossible de brider ou debrider,
    //il suffit de la declarer en private.
    //si on veut juste qe les methode ne rendent rien on pour les reecrire.
    void brider(){}
    void debrider(){}
public:
    int acceleration;
    int freinage;
    
    VoitureDeSport() : Voiture(){
        vitesseMAX=350;
        acceleration=50;
        freinage=25;
        bride=false;
    }
    void accelerer() {
        Voiture::accelerer();
        
    }
};

class Camion : public Vehicule
{
//protected:
//    int nbrEssieux;
public:
    int acceleration;
    int freinage;
    

    Camion(int nbrEssieux) : Vehicule(100){
        this->nbrEssieux=nbrEssieux;
        acceleration=10;
        freinage=10;

    }
    
    int getNbrEssieux() {return nbrEssieux;}
    
    void accelerer() {
        if (vitesseCourante+acceleration<vitesseMAX) vitesseCourante=vitesseCourante+acceleration;
        else if (vitesseCourante<vitesseMAX)         vitesseCourante=vitesseMAX;
    }
    void freiner()   {
        if (vitesseCourante-freinage>0) vitesseCourante=vitesseCourante-freinage;
        else if (vitesseCourante>0)     vitesseCourante=0;
    }

};

//heritage multiple
class Pickup : public Voiture,public Camion{
public:   
    Pickup() : Voiture(),Camion(2){
        //Voiture ET Camion amene tous les 2 les variables acceleration et freinage
        Voiture::acceleration=30;
        Camion::acceleration=Voiture::acceleration;
        Voiture::freinage=20;
        Camion::freinage=Voiture::freinage;
    }
    
    void accelerer() {Voiture::accelerer();}
    void freiner() {Camion::freiner();}
};

class Test {
public:
    char buffer[100];
    
    virtual void rien() {} //le sizeof de Test sans virtual est de 100
                           //le sizeof de Test avec virtual est de 112 !!!
                           //   => virtual entraine la creation d'un pointeur caché (ici de taille 12)
                           //      vers une table de fct virtuel qui contient un pointeur
                           //      vers la vrai fonction rien...
};
/*
 * 
 */
//on crée une fonction aFond pour faire accelerer notre voiture jusqu'au max
//void aFond1(Voiture& v){
//    int vitesse;
//    do {
//        vitesse=v.getViteseCourante();
//        v.accelerer();
//        cout << "   acceleration de " << vitesse << " a " << v.getViteseCourante() << endl;
//    } while (vitesse!=v.getVitesseMAX());
//}
////pour camion on pourrait tout recopier mais y a mieux
//void aFond2(Camion& c){
//    int vitesse;
//    do {
//        vitesse=c.getViteseCourante();
//        c.accelerer();
//        cout << "   acceleration de " << vitesse << " a " << c.getViteseCourante() << endl;
//    } while (vitesse!=c.getVitesseMAX());
//}

//on se base la sur vehicule MAIS comme vehicule::accelerer ne fait rien et que l'on veut faire accelerer un camion,
//il faut donc ajouter le prefix virtual devant accelerer pour que ce soit la methode de camion qui soit appellée et non plus celle de vehicule.    
void aFond(Vehicule& v){
    int vitesse;
    do {
        vitesse=v.getViteseCourante();
        v.accelerer();
        cout << "   acceleration de " << vitesse << " a " << v.getViteseCourante() << endl;
    } while (vitesse!=v.getVitesseMAX());
    
    //si on veut utiliser cette fonction pour effectuer un traiement supplementaire pour une classe herite de Vehicule on cre un dynamic_cast
    //le dynamic_cast ne s'applique que sur des reference ou des pointeurs
    //Cas du pointeur, s'il ne pointe pas vers une voiture, retourn NULL
    //Cas de la reference, s'il ne pointe pas vers une voiture, genere une exception
    
    //Cas du pointeur
    Voiture* voiture = dynamic_cast<Voiture*>(&v);
    if (voiture!=NULL){
        cout << "c'est une voiture"<<endl;;
        if (!voiture->getBride()) {
            cout << "voiture est debridee"<<endl;
            vitesse=v.getViteseCourante();

            while (vitesse!=v.getVitesseMAX()){
                v.accelerer();
                cout << "   acceleration de " << vitesse << " a " << v.getViteseCourante() << endl;
                vitesse=v.getViteseCourante();
            }
        }
        else{
            cout << "voiture est bridéee"<<endl;
        }
    }
    
    //on peut aussi utiliser un autre mecanisme dans #include <typeinfo>
    //avec typeid, on recupere le type de v (Voiture ou Camion))
    //il suffit alors de tester si c'est une voiture ou non.
    const type_info& ti=typeid(v);
    if(ti==typeid(Voiture&)) cout<<"oui, c' est bien une voiture"<<endl;
}

void stop(Vehicule& v){
    int vitesse;
    do {
        vitesse=v.getViteseCourante();
        v.freiner();
        cout << "   freinage de " << vitesse << " a " << v.getViteseCourante() << endl;
    } while (vitesse!=0);
}

int main(int argc, char** argv) {
    //Vehicule v; //erreur car on a rajouté =0 a la ligne de declaration virtual de accelerer
                //accelerer est alors une fonction virtuelle pure.
                //on a cependant toujours le droit d'avoir des pointeur et ref de cette classe vers une classe fille
    //Par contre on peut avoir un pointeur ou une reference => voir plus bas
    
    
    Voiture voiture;
    cout << "voiture roule au max a " << voiture.getVitesseMAX() << endl;
    cout << "voiture roule actuellement a " << voiture.getViteseCourante() << endl;
    cout << "voiture possede "<< voiture.getNbrEssieux() <<" essieux." << endl;
    //aFond1(voiture); //utilisation de la fonction qui agit sur (et que sur) voiture
    aFond(voiture);    //utilisation de la fonction commune
    
    cout << "voiture roule actuellement a " << voiture.getViteseCourante() << endl;

    cout << endl;
    //appel au traitement particulier a une voiture qui soit debridée
    cout<<"je debride\n";
    voiture.debrider();
    aFond(voiture);
    cout << "voiture roule actuellement a " << voiture.getViteseCourante() << endl;
    cout << endl;
    cout<<"je freine\n";
    stop(voiture);
    cout<<"je bride\n";
    voiture.brider();
    aFond(voiture);
    
    Camion camion(3);
    cout << "camion roule au max a " << camion.getVitesseMAX() << endl;
    cout << "camion roule actuellement a " << camion.getViteseCourante() << endl;
    cout << "camion possede "<< camion.getNbrEssieux() <<" essieux." << endl;
    
    //aFond2(camion); //utilisation de la fonction qui agit sur (et que sur) camion
    aFond(camion);    //utilisation de la fonction commune
    
    cout << "camion roule actuellement a " << camion.getViteseCourante() << endl;
    
    //pointeur ou reference sur Vehicule
    Vehicule *pv=&camion; //pointeur
    Vehicule& rv=camion;  //reference
    
    Camion *vehicule1=(Camion*)pv; //On peut affecter pv sur un pointeur sur Camion ssi on cast
    cout << "Nbr d'essieux du Camion: " << vehicule1->getNbrEssieux()<<endl;        
    Voiture *vehicule2=(Voiture*)pv; //On peut affecter pv sur un pointeur sur Camion ssi on cast
    cout << "Nbr d'essieux de la voiture: " << vehicule2->getNbrEssieux()<<endl;        
    
    
    
    
    
    VoitureDeSport porsche;
    cout << "porsche roule au max a " << porsche.getVitesseMAX() << endl;
    cout << "porsche roule actuellement a " << porsche.getViteseCourante() << endl;
    cout << "porsche possede "<< porsche.getNbrEssieux() <<" essieux." << endl;
    //aFond1(voiture); //utilisation de la fonction qui agit sur (et que sur) voiture
    aFond(porsche);    //utilisation de la fonction commune
    
    cout << "porsche roule actuellement a " << porsche.getViteseCourante() << endl;


    
//    cout << "\n------------- TEST ------------------\n";
//    Test test;
//    cout << sizeof(test) << endl;
    
    return 0;
}

