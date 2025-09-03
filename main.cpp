#include <iostream>
#include "ListaLigadaSimple.h"

using namespace std;

int main()
{
    ListaLigadaSimple lista;

    //Revisando el metodo Agregar al final
    lista.AgregarFinal(50);
    lista.AgregarFinal(30);
    lista.AgregarFinal(80);
    // Salida {50, 30, 80}
    lista.Imprimir();

    //Se prueba el método GregarAl inicios
    lista.AgregarInicio(70);
    // Salida {70, 50, 30, 80}
    lista.Imprimir();

    // Salida {22, 70, 50, 30, 80}
    lista.AgregarInicio(22);
    // Salida {22, 70, 50, 30, 80, 77}
    lista.AgregarFinal(77);
    // Salida {22, 70, 25, 50, 30, 80, 77}
    lista.Insertar(25, 2);

    // Salida {70, 25, 50, 30, 80, 77}
    lista.Eliminar(0);
    lista.Imprimir();
    // Salida {70, 25, 50, 30, 80, 77}
    lista.Eliminar(20);  //Indice fuera de rango

    // Salida {70, 25, 50, 30, 80}
    lista.Eliminar(5);
    lista.Imprimir();
    // Salida {70, 50, 30, 80}
    lista.Eliminar(1);

    //Elimina el elemento 2
    lista.Eliminar(2);
    // Salida {70, 50, 80}
    lista.Imprimir();

    // salida: La lista está vacia: 0
    cout << "La lista está vacia: " <<  lista.EstaVacia() <<endl;

    //Inserta el 22 en la posición 1
    lista.Insertar(22, 1);
     // Salida {70, 22, 50, 80}
    lista.Imprimir();

    int dato = lista.Extraer(3);
    cout << "Elemento 3 extraido es: " << dato <<endl;
     // Salida {70, 22, 50}
    lista.Imprimir();

    dato = lista.Obtener(1);
    cout << "Elemento 1 es: " << dato <<endl;
    cout << "Elemento 2 es: " << lista[2] <<endl;


    cout << "La lista tiene: " << lista.Longitud() << " elementos" <<endl;

    lista.modificar(33, 20);
    lista.modificar(33, 2);
     // Salida {70, 22, 33}
    lista.Imprimir();

    dato = lista.Obtener(1);
    cout << "Elemento 1 es: " << dato <<endl;

    return 0;
}
