#include <iostream>
#include "Cola/Cola.h"
using namespace std;

void mostrarCola(Cola<int> &cola1)
{
    Cola<int> aux;
    int valor;

    while (!cola1.esVacia())
    {
        valor = cola1.desencolar();
        cout << valor << " -> ";
        aux.encolar(valor);
    }

    while (!aux.esVacia())
    {
        cola1.encolar(aux.desencolar());
    }
}

int sumatoria(Cola<int> &c1, int n){
    int sumatoria=0;

    while (!c1.esVacia())
    {
        if (c1.peek()!=n)
        {
            sumatoria+=c1.desencolar();
        }
        else
        {
            return sumatoria;
        }
    }

    return sumatoria;
}

int main() {

    cout << "Ejercicio N° 4" << endl;

    Cola<int> cola1;

    cola1.encolar(3);
    cola1.encolar(5);
    cola1.encolar(2);
    cola1.encolar(8);
    cola1.encolar(7);

    mostrarCola(cola1);

    cout<<" "<<endl;

    cout<<"La sumatoria es: "<<sumatoria(cola1,1);

    cout<<" "<<endl;

    return 0;
}