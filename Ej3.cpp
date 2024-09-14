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

void eliminarValor(Cola<int> &c1, int n1)
{

    Cola<int> aux;
    bool encontrado = false;
    int cont;

    while (!c1.esVacia())
    {
        if (c1.peek() == n1)
        {
            if (!encontrado)
            {
                encontrado = true;
                aux.encolar(c1.desencolar());
            }
            else
            {
                cont++;
            }
        }
        else
        {
            aux.encolar(c1.desencolar());
        }
    }

    if (encontrado == false && cont == 0)
    {
        while (!aux.esVacia())
        {
            if (aux.peek() != n1)
            {
                c1.encolar(aux.desencolar());
            }
            aux.desencolar();
        }
    }
    else
    {
        while (!aux.esVacia())
        {

            c1.encolar(aux.desencolar());
        }
    }
}

int main()
{

    cout << "Ejercicio N° 3" << endl;
    Cola<int> cola1;

    cola1.encolar(1);

    cola1.encolar(2);

    cola1.encolar(3);

    cola1.encolar(2);

    cola1.encolar(4);

    cola1.encolar(2);

    cout << "Cola original" << endl;
    mostrarCola(cola1);

    eliminarValor(cola1, 2);

    cout << "Cola depurada" << endl;
    mostrarCola(cola1);

    return 0;
}
