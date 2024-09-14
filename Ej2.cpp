#include <iostream>
#include "Cola/Cola.h"
using namespace std;

void mostrarCola(Cola<int> &cola1){
    Cola<int>aux;
    int valor;

    while (!cola1.esVacia())
    {
        valor=cola1.desencolar();
        cout<<valor<<" -> ";
        aux.encolar(valor);
    }

    while (!aux.esVacia())
    {
        cola1.encolar(aux.desencolar());
    }
    
    
}

void eliminarmayor(Cola<int> &c1, int n1){
    Cola<int> aux;
    int valor;

    while (!c1.esVacia())
    {
        valor=c1.desencolar();
        if(valor<n1){
            aux.encolar(valor);
        }
    }
    
    while (!aux.esVacia())
    {
        c1.encolar(aux.desencolar());
    }
    
}


int main() {

    cout << "Ejercicio N° 2" << endl;

    Cola<int> cola1;

    cola1.encolar(1);

    cola1.encolar(2);

    cola1.encolar(3);

    cola1.encolar(4);

    cola1.encolar(5);

    cout<<"Cola original"<<endl;
    mostrarCola(cola1);

    eliminarmayor(cola1,3);

    cout<<" "<<endl;

    cout<<"Cola depurada"<<endl;

    mostrarCola(cola1);

    cout<<" "<<endl;






    return 0;
}
