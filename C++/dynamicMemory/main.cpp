/* 
 * File:   main.cpp
 * Author: Formation
 *
 * Created on 11 janvier 2016, 11:36
 */

#include <cstdlib>
#include <iostream>
#include <cstring>

#include <memory> //allocation pour le C++ 2011
//Mais c'est insuffisent, il faut egalement configurer le compilateur C++2011
// clic droit sur le nom du projet puis properties et changer C++ standard pour C++11


using namespace std;

void f2(char *a, int t){
    for(int i=0;i<t;i++) {
        a[i]=(char)(48+i); //48=0x30=caractere 0
    }
    a[t]='\0';
}
void f3(char tab[], int taille){
    for(int i=0;i<taille;i++) tab[i]=i;
}


unique_ptr<int[]> f4(){
    int taille=100;
    unique_ptr<int[]> resultat(new int[taille]);
    for(int i=0;i<taille;i++) resultat[i]=i;
    return resultat;
}

struct Personne {
    string nom;
    int age;
};
unique_ptr<Personne[]> f5(){
    int taille=100;
    unique_ptr<Personne[]> resultat(new Personne[taille]);
    for(int i=0;i<taille;i++) {
        if (i==43) {
            resultat[i].nom = "Fabrice";
            resultat[i].age = 43;
        } else {
            resultat[i].nom = "a";
            resultat[i].age = 1;
        }
    }
    
    return resultat;
}

/*
 * 
 */
int main(int argc, char** argv) {
    const int Taille=10;
    //EN C
    //Allocation dynamique de memoire
    int* ptr1=(int*)malloc(sizeof(int));       //allocation memoire d'un pointeur (taille 8) de int (taille 4 sur windows 64bits)
    char* s1=(char*)malloc(Taille*sizeof(char));  //allocation memoire d'un pointeur (taille 8) de 100*taille char (100*1)
    cout << "ptr1: taille int="<<sizeof(int)<<", taille ptr1=" << sizeof(ptr1) << endl;
    cout << "s1:   taille char="<<sizeof(char)<<", taille s1=" << sizeof(s1) << endl;
    *ptr1=123;
    *s1='c';
    //liberation de la memoire
    free(ptr1);
    free(s1); 
    
    //EN C++ classic
    int* ptr2=new int;
    char* s21=new char[Taille];
    char* s22=new char[Taille];
    cout << "ptr2: taille int="<<sizeof(int)<<", taille ptr2=" << sizeof(ptr2) << endl;
    cout << "s21:  taille char="<<sizeof(char)<<", taille s21=" << sizeof(s21) << endl;
    
    //remplissage s21
    f2(s21,Taille);
    //il n'exite pas de moyen direct de retrouver la taille d'un tableau dynamique comme en python
    // => soit on garde la taille (par ex en creant une struct avec le tab dyn)
    // => soit on le recalcule en ayant prealablement defini un element particulier qui termine le tableau (par ex \0 ou NULL)
    //recalcul de la taille
    int t_s21=0;
    for(int i=0;s21[i]!='\0';i++) 
        t_s21++;
    cout << "Taille s21 = "<<t_s21<<endl;
    //ecriture du resultat
    cout<<"s21 = {";
    for(int i=0;i<t_s21;i++) 
        cout<<s21[i]<<",";
    cout<<s21[t_s21]<<"}"<<endl;
    
    //remplissage s22
    f3(s22,Taille);
    cout<<"s22 = {";
    for(int i=0;s22[i]!='\0';i++) 
        cout<<s22[i]<<",";
    cout<<"}"<<endl;
        
    delete ptr2;
    delete[] s21; //ne pas oublier les [] pour detruire un tableau
    delete[] s22;
    
    //EN C++ 2011 <- si compilateur compatible
    //ajouter aussi #include <memory>
    //et configurer le standard de compilation en C++11
    unique_ptr<int> ptr3(new int);
    unique_ptr<char[]> s3(new char[Taille]);
    cout << "taille int="<<sizeof(int)<<", taille ptr3=" << sizeof(ptr2) << endl;
    cout << "taille char="<<sizeof(char)<<", taille s3=" << sizeof(s21) << endl;

    //liberation automatique a la fin de son utilisation
    //mais on peut aussi le controler soit-meme avec
    ptr3.reset();
    
    unique_ptr<int[]> var4=f4();
    cout << "var4[98] = " << var4[98] << endl;
    // la liberation se fait alors a la sortie de cette fonction car elle ne retourne pas var

    unique_ptr<Personne[]> var5=f5();
    cout << "var5[42] = " << var5[42].nom << endl;
    cout << "var5[43] = " << var5[43].nom << endl;
    cout << "var5[44] = " << var5[44].nom << endl;
    return 0;
}

