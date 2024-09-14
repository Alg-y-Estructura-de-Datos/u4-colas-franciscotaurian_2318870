#include <iostream>
#include <string>
#include "Cola/Cola.h"
using namespace std;

struct documento
{
    string nombre;
    int cantpags;
};

void menu(){

    cout<<"***Menu de impresion***"<<endl;
    cout<<"1. Agregar documento"<<endl;
    cout<<"2. Imprimir documento"<<endl;
    cout<<"3. Mostrar cola de impresion"<<endl;
    cout<<"4. Salir"<<endl;
}


void agregarDocumento(Cola<documento> &c1)
{
    documento doc;
    cout << "Ingrese el nombre del documento: "<<endl;
    cin.ignore();
    getline(cin, doc.nombre);
    cout << "Ingrese la cantidad de paginas: "<<endl;
    cin >> doc.cantpags;
    c1.encolar(doc);
}

void imprimirDocumento(Cola<documento> &c1)
{
    documento doc;
    if (c1.esVacia())
    {
        cout << "No hay documentos en espera" << endl;
    }
    else
    {
        cout << "Imprimiendo documento" << endl;
        doc = c1.desencolar();
        cout << "Nombre: " << doc.nombre << endl;
        cout << "Cantidad de paginas: " << doc.cantpags << endl;
    }
}

void mostrarCola(Cola<documento> &cola1)
{
    Cola<documento> aux;
    documento valor;

    if (cola1.esVacia())
    {
        cout<<"No hay documentos para imprimir"<<endl;
    }
    

    while (!cola1.esVacia())
    {
        valor = cola1.desencolar();
        cout<<"Nombre: "<<valor.nombre<<endl;
        cout<<"DNI: "<<valor.cantpags<<endl;
        aux.encolar(valor);
        cout<<" "<<endl;
    }

    while (!aux.esVacia())
    {
        cola1.encolar(aux.desencolar());
    }
}


int main() {

    cout << "Ejercicio N° 7" << endl;

    int option;
    Cola<documento> colaimpresion;

    do
    {
        menu();
        cin>>option;

        switch (option)
        {
        case 1:
            agregarDocumento(colaimpresion);
            break;
        case 2:
            imprimirDocumento(colaimpresion);
            break;
        case 3:
            mostrarCola(colaimpresion);
        break;
        case 4:
            cout<<"Saliendo..."<<endl;
            break;
        
        default:
            cout<<"Opcion incorrecta."<<endl;
            break;
        }
    } while (option!=4);
    

    return 0;
}