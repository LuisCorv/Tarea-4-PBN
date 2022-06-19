#include<iostream>
#include <queue>
#include <string>

using namespace std;

class grafos{
private:
    queue<int>n_nodos;        //deberia ser una 'lista' de los nodos
    queue <string> arco_nodo;      // deberia ser una 'lista' de los arcos entre nodos
    int largo;

    bool hay_arco(int,int);         //Revisa si existe o no un arco entre 2 nodos
    bool hay_camino(int,int);       //Revisa si existe o no un camino entre 2 nodos

public:
    grafos(int);    //Constructor de la clase con parametros
    grafos() : grafos(0) {};        //Constructor de la clase sin parametros

    void add_arco(int,int);     //Crea un arco entre d y h 
    int add_nodo();         //Crea un nodo
    void imprimir_si_hay_arco(int,int);     //imprimir si existe o no un arco
    void imprimir_si_hay_camino(int,int);     //imprimir si existe o no un arco

    void imprimir_nodos();
    void imprimir_arcos();
    
};
