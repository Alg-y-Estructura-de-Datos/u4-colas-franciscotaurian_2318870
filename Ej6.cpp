#include <iostream>
#include <string>
#include "Cola/Cola.h"
using namespace std;

class paciente
{
private:
    string nombre;
    int dni;
    int numtel;
public:
    paciente();
    void setNombre(string nombre);
    void setDni(int dni);
    void setNumtel(int numtel);
    string getNombre();
    int getDni();
    int getNumtel();
};

paciente::paciente()
{
    nombre = "";
    dni = 0;
    numtel = 0;
}

void paciente::setNombre(string nombre)
{
    this->nombre = nombre;
}

void paciente::setDni(int dni)
{
    this->dni = dni;
}

void paciente::setNumtel(int numtel)
{
    this->numtel = numtel;
}

string paciente::getNombre()
{
    return nombre;
}

int paciente::getDni()
{
    return dni;
}

int paciente::getNumtel()
{
    return numtel;
}


void mostrarCola(Cola<paciente> &cola1)
{
    Cola<paciente> aux;
    paciente valor;

    while (!cola1.esVacia())
    {
        valor = cola1.desencolar();
        cout<<"Nombre: "<<valor.getNombre()<<endl;
        cout<<"DNI: "<<valor.getDni()<<endl;
        cout<<"Numero de telefono: "<<valor.getNumtel()<<endl;
        aux.encolar(valor);
    }

    while (!aux.esVacia())
    {
        cola1.encolar(aux.desencolar());
    }
}

void menu()
{
    cout<<"***Consultorio***"<<endl;
    cout << "1. Agregar paciente" << endl;
    cout << "2. Atender paciente" << endl;
    cout << "3. Mostrar pacientes en espera" << endl;
    cout << "4. Salir" << endl;
}

void agregarPaciente(Cola<paciente> &c1){

    paciente p1;
    string nombre;
    int dni;
    int numtel;

    cout<<"Ingrese el nombre del paciente: ";
    getline(cin,nombre);

    cout<<"Ingrese el DNI del paciente: ";
    cin>>dni;

    cout<<"Ingrese el numero de telefono del paciente: ";
    cin>>numtel;

    p1.setNombre(nombre);
    p1.setDni(dni);
    p1.setNumtel(numtel);

    c1.encolar(p1);
}

void atenderPaciente(Cola<paciente> &c1){
    paciente p1;

    if (c1.esVacia())
    {
        cout<<"No hay pacientes en espera"<<endl;
    }
    else
    {
        cout<<"Paciente atendido"<<endl;
        p1=c1.desencolar();
        cout<<"NOmbre: "<<p1.getNombre()<<endl;
        cout<<"DNI: "<<p1.getDni()<<endl;
        cout<<"Numero de telefono: "<<p1.getNumtel()<<endl;
    }
}





int main() {

    cout << "Ejercicio N° 6" << endl;

    Cola<paciente> cola1;

    int opcion;

    do
    {
        menu();
        cin>>opcion;
        cin.ignore();

        switch (opcion)
        {
        case 1:
            agregarPaciente(cola1);
            break;
        case 2:
            atenderPaciente(cola1);
            break;
        case 3:
            mostrarCola(cola1);
            break;
        case 4:
            cout<<"Saliendo..."<<endl;
            break;
        default:
            cout<<"Opcion incorrecta"<<endl;
            break;
        }
    } while (opcion!=4);
    
    
    return 0;
}