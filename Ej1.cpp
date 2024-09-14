#include <iostream>
#include "Cola/Cola.h"
using namespace std;

bool verificar(Cola<char> &c1, Cola<char> &c2){
    Cola<char> aux1;
    Cola<char> aux2;
    char valor1, valor2;

    while (!c1.esVacia() && !c2.esVacia())
    {
        valor1=c1.desencolar();
        valor2=c2.desencolar();
        if(valor1!=valor2){
            return false;
        }
    }
    return c1.esVacia() && c2.esVacia(); //simplificacion de un if para ver si ambas estan vacias, si a una le quedan elementos son distintas.
    
}

int main()
{

    cout << "Ejercicio N° 1" << endl;
    Cola<char> cola1;
    Cola<char> cola2;

    cola1.encolar(1);

    cola1.encolar(2);

    cola1.encolar(3);

    cola1.encolar(4);

    cola1.encolar(5);

    
    cola2.encolar(1);
    
    cola2.encolar(2);
    
    cola2.encolar(3);
    
    cola2.encolar(4);

    cola2.encolar(5);
    

    if(!verificar(cola1,cola2)){
        cout<<"Las colas son distintas"<<endl;
    }
    else{
        cout<<"Las colas son iguales"<<endl;
    }

    return 0;
}
