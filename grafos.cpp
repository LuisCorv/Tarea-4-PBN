
#include <queue>
#include "grafos.h"

//Naturalmente no hay ningun arco creado, estos solo se crean a partir de la funcion add_arco


//Constructor de la clase
grafos :: grafos (int n_nodos){     //si es vacio, el n_nodos=0
        queue<int>numero_nodos;
        for (int i=0; i<n_nodos;i++){
                numero_nodos.push(i);
        } 
        this->n_nodos=numero_nodos;  
        this->largo= numero_nodos.size();
        imprimir_nodos();
}


//revisar si el nodo fue creado o no
bool comprobar_nodo( queue <int> nodos, int numero ){
        queue <int> comprobacion_nodos= nodos;
        while (!comprobacion_nodos.empty()){
                int front = comprobacion_nodos.front();
                comprobacion_nodos.pop();
                if (front == numero){
                        return true;
                }
        }
        return false;

}

//Crea un arco entre d y h 
void grafos :: add_arco (int d ,int h){
                bool comprobacion1, comprobacion2;
                comprobacion1 = comprobar_nodo(this->n_nodos , d);
                comprobacion2 = comprobar_nodo(this->n_nodos , h);
                if (comprobacion1 ==true){
                        if(comprobacion2==true){
                                //crear un arco entre un nodo y otro , y guardarlo en la 'lista' de arcos
                                string nombre_arco = to_string(d)+","+ to_string(h);
                                arco_nodo.push(nombre_arco);
                                imprimir_arcos();
                        }
                        else {
                        cout << "El segundo valor ingresado no existe entre los nodos creados" << endl;
                        }
                }
                else {
                        cout << "El primer valor ingresado no existe entre los nodos creados"<< endl;
                }   
}


//Crea un nodo, y le asigna un n° partiendo desde el 0, si es que ya existen nodos creados, partir desde el ultimo y sumarle 1 para el nuevo nodo
int grafos :: add_nodo (){
        int nuevo_nodo=largo;
        n_nodos.push(largo);
        this->largo=n_nodos.size();
        imprimir_nodos();
        return nuevo_nodo;
}


//imprimir 'si existe un arco entre d y h' si es true o un 'no existe arco entre d y h' si es false
void grafos :: imprimir_si_hay_arco(int d, int h){
        bool valor =hay_arco(d,h);
        if (valor==true){
                cout<< "Si existe un arco entre " << d << " y " << h << endl;
        }
        else{
                cout<< "No existe un arco entre " << d << " y " << h << endl;
        }
}

//Revisa si existe o no un arco entre 2 nodos
bool grafos :: hay_arco (int d , int h){
        bool comprobacion1, comprobacion2;
        comprobacion1 = comprobar_nodo(this->n_nodos , d);
        comprobacion2 = comprobar_nodo(this->n_nodos , h);
        if (comprobacion1 ==true){
                if(comprobacion2==true){
                        string nombre_arco = to_string(d)+","+ to_string(h);
                        queue <string> verificar_arcos= arco_nodo;
                        while (!verificar_arcos.empty()){
                                string front = verificar_arcos.front();
                                verificar_arcos.pop();
                                if (front==nombre_arco){
                                        return true;
                                }
                        }
                        return false;
                }
                else {
                cout << "El segundo valor ingresado no existe entre los nodos creados" << endl;
                return false;
                }
        }
        else {
                cout << "El primer valor ingresado no existe entre los nodos creados"<< endl;
                return false;
        }
}


//imprimir 'si existe un camino entre d y h' si es true o un 'no existe camino entre d y h' si es false
void grafos :: imprimir_si_hay_camino(int d, int h){
        bool valor =hay_camino(d,h);
        if (valor==true){
                cout<< "Si existe un camino entre " << d << " y " << h << endl;
        }
        else{
                cout<< "No existe un camino entre " << d << " y " << h << endl;
        }
}


//Revisa si existe o no un camino entre 2 nodos
bool grafos :: hay_camino (int d ,int h){
        bool comprobacion1, comprobacion2;
        comprobacion1 = comprobar_nodo(this->n_nodos , d);
        comprobacion2 = comprobar_nodo(this->n_nodos , h);
        if (comprobacion1 ==true){
                if(comprobacion2==true){
                        string nombre_nodo1 = to_string(d);
                        string nombre_nodo2 = to_string(h);
                        string x ="no";
                        string y = "no";
                        queue <string> verificar_arcos1= arco_nodo;
                        //queue <string> verificar_arcos2= arco_nodo;
                        while (!verificar_arcos1.empty()){
                                string nodes = (verificar_arcos1.front());
                                verificar_arcos1.pop();
                                if (nodes.find(nombre_nodo1)!= string::npos){
                                        x="maybe";    
                                }
                                else if ((nodes.find(nombre_nodo2)!= string::npos) ){
                                        y="maybe";
                                }
                        }
                        if ( x=="no" || y =="no"){
                                return false;
                        }
                        else if ((x=="maybe") && (y=="maybe")){
                                return true;
                        }
                }
                else {
                cout << "El segundo valor ingresado no existe entre los nodos creados" << endl;
                return false;
                }
        }
        else {
                cout << "El primer valor ingresado no existe entre los nodos creados"<< endl;
                return false;
        }
        return false;
}


void grafos :: imprimir_nodos(){
        queue <int> numeros_nodos= n_nodos;
        cout<< "Los nodos registrados hasta el momento son: { ";
        while (!numeros_nodos.empty()){
        int front = numeros_nodos.front();
        cout << front ;
        numeros_nodos.pop();
        if (!numeros_nodos.empty()){
                cout<< " ; ";
        }
        }
        cout << " }"<<endl;
}

void grafos :: imprimir_arcos(){
        queue <string> numeros_arcos= arco_nodo;
        cout<< "Los arcos registrados hasta el momento son: { ";
        while (!numeros_arcos.empty()){
        string front = numeros_arcos.front();
        cout << "'"<<front <<"'" ;
        numeros_arcos.pop();
        if (!numeros_arcos.empty()){
                cout<< " ; ";
        }
        }
        cout << " }"<<endl;
}