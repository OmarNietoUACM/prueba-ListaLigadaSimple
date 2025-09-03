#ifndef LISTALIGADASIMPLE_H
#define LISTALIGADASIMPLE_H

#include "NodoLLS.h"


class ListaLigadaSimple
{
private:
    NodoLLS *pIni;
    NodoLLS *pFin;

    public:
        ListaLigadaSimple();

        // Agrega el dato al final de lista
        void AgregarFinal(int dato);
        // Agrega el dato al Inicio de lista
        void AgregarInicio(int dato);
        // Inser el dato al final de lista
        void Insertar(int dato, int indice);
        //Imprime la lista
        void Imprimir();
        //Elimina el nodo de la lista del índice dado
        // y regresa su valor
        // (Extrae el dato de lista)
        int Extraer(int indice);
        //Obtiene el dato de la posición especificada
        //po el índice sin extraerlo de la lista
        int Obtener(int indice);

        int operator[](int indice);


        //Modifica el dato que se encuentra en la posición dada
        void modificar(int dato, int indice);
        //Eliminar el nodo dato por el índice y regresa su valor
        int Eliminar(int indice);
        //Vacía todos los elementos en la lista
        void Vaciar();
        //Regresa verdadero si la lista está vaciar
        //y falso en caso contrario
        bool EstaVacia();
        //Regresa el número de elementos en la lista
        int Longitud();







        virtual ~ListaLigadaSimple();

    protected:
        NodoLLS *CrearNodoLLS(int dato);

    private:

};

#endif // LISTALIGADASIMPLE_H
