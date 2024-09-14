#include <iostream>
#include "Cola/Cola.h"
#include "Pila/Pila.h"
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

void mostrarPila(Pila<int> &p1)
{
    Pila<int> aux;
    int var;

    while (!p1.esVacia())
    {
        var = p1.pop();
        cout << var << " - ";
        aux.push(var);
    }

    while (!aux.esVacia())
    {
        p1.push(aux.pop());
    }
}

void separa(Cola<int> &c1, Pila<int> &p1)
{

    Cola<int> aux;

    while (!c1.esVacia())
    {
        if (c1.peek() % 2 != 0)
        {
            p1.push(c1.desencolar());
        }
        else
        {
            aux.encolar(c1.desencolar());
        }
    }

    while (!aux.esVacia())
    {
        c1.encolar(aux.desencolar());
    }
    
}

int main()
{

    cout << "Ejercicio N° 5" << endl;

    Cola<int> cola;
    Pila<int> pila;

    cola.encolar(1);
    cola.encolar(3);
    cola.encolar(2);
    cola.encolar(4);
    cola.encolar(5);
    cola.encolar(8);

    if (cola.esVacia())
    {
        cout<<"Error cola vacia"<<endl;
    }
    

    cout<<"Cola original"<<endl;
    mostrarCola(cola);

    cout<<" "<<endl;

    separa(cola,pila);

    cout<<"Cola de pares"<<endl;
    mostrarCola(cola);

    cout<<" "<<endl;

    cout<<"Pila de impares"<<endl;
    mostrarPila(pila);


    return 0;
}