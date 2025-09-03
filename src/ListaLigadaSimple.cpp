#include<iostream>
#include <new>
#include "ListaLigadaSimple.h"

using namespace std;

ListaLigadaSimple::ListaLigadaSimple()
{
    pIni = NULL;
    pFin = NULL;
}


NodoLLS *ListaLigadaSimple::CrearNodoLLS(int dato)
{
    //Creación de un nuevo nodo
    NodoLLS *pNodo = NULL;

    try{
        pNodo = new NodoLLS(dato);
    }
    catch(bad_alloc){
        cout << "ERROR: No se puede crear un nuevo nodo" <<endl;
        cout << " error en la asignación dinámica de memoria" <<endl;
    }

    return pNodo;
}


// Agrega el dato al final de lista
void ListaLigadaSimple::AgregarFinal(int dato)
{
    //Creación de un nuevo nodo
    NodoLLS *pNodo = CrearNodoLLS(dato);
    if (pNodo == NULL) return;

    //caso 1: La lista está vacia
    if (EstaVacia())
    {
        pIni = pNodo;
        pFin = pNodo;

    }
    else {
        //No está vacia la lista
        pFin->pSig = pNodo;
        pFin = pNodo;
    }
}

// Agrega el dato al Inicio de lista
void ListaLigadaSimple::AgregarInicio(int dato)
{
    Insertar(dato, 0);  //El dato se inserta al inicio
}

// Inser el dato al final de lista
void ListaLigadaSimple::Insertar(int dato, int indice)
{
    NodoLLS *p = pIni;
    int i = 0;

    //1. Buscar el nodo previo al lugar donde se insertará
    // el nuevo nodo
    for( ; (i< indice - 1)&&(p!=NULL); i++, p = p->pSig);

    //2. Creación de un nuevo nodo
    NodoLLS *pNodo = CrearNodoLLS(dato);
    if (pNodo == NULL) return;

    // Caso cuando la lista está vacia
    if (EstaVacia())
    {
        pIni = pNodo;
        pFin = pNodo;
    }

    //Caso donde el índice se encuentra en medio de lista
    if((i==indice - 1)&&(p!=NULL))
    {
        pNodo->pSig = p->pSig;
        p->pSig = pNodo;
    }
    else if (p == pIni)
    {
        //El nodo se insertará al inicio
         pNodo->pSig = p;
         pIni = pNodo;
    }
    else if (p==pFin) //Se inserta al final
    {
        p->pSig = pNodo;
        pFin = pNodo;
    }
}


//Imprime la lista
void ListaLigadaSimple::Imprimir()
{
    NodoLLS *p = pIni;

    cout << "{ ";
    while (p!=NULL)
    {
        cout << p->dato << ", ";
        p = p->pSig;
    }
    cout << " }" <<endl;

}

//Elimina el nodo de la lista del índice dado
// y regresa su valor
// (Extrae el dato de lista)
int ListaLigadaSimple::Extraer(int indice)
{
    return Eliminar(indice);
}

//Obtiene el dato de la posición especificada
//por el índice sin extraerlo de la lista
int ListaLigadaSimple::Obtener(int indice)
{
    NodoLLS *p = pIni;
    int i =0;
    while((i<indice) && (p != NULL))
    {
        p = p->pSig;
        i++;
    }
    if(p != NULL) return p->dato;
    else cout << "ERROR: Indice fuera de rango!" << endl;
    //cout << __LINE__ <<__FILE__ << endl;

    return 0;
}


int ListaLigadaSimple::operator[](int indice){
    return Obtener(indice);
}


//Modifica el dato que se encuentra en la posición dada
void ListaLigadaSimple::modificar(int dato, int indice)
{
    NodoLLS *p = pIni;
    int i =0;
    while((i<indice) && (p != NULL))
    {
        p = p->pSig;
        i++;
    }
    if(p != NULL)
        p->dato = dato;
    else
    {
        cout << "ERROR: Indice fuera de rango!" << endl;
        cout << "Linea: " << __LINE__ << " Archivo: " << __FILE__ << endl;
    }
}

//Eliminar el nodo dato por el índice y regresa su valor
int ListaLigadaSimple::Eliminar(int indice)
{
    NodoLLS *p=pIni;
    NodoLLS *pPrev=NULL;

    int i = 0;

    while( (i<indice) && (p != NULL) )
    {
        pPrev = p;
        p = p->pSig;
        i++;
    }
    if(p!= NULL)
    {
        if (p == pIni) //Se eliminará el primer nodo
        {
            pIni = p->pSig;
            if (pIni == NULL) //Cuando solo hay un nodo
                pFin = NULL;
        }
        else if( p == pFin) //El nodo a eliminar es el nodo Final
        {
            pPrev->pSig = p->pSig;
            pFin = pPrev;
        }
        else{ //Cuando el nodo a eliminar se encuentra en medio
            pPrev->pSig = p->pSig;
        }

        int valor = p->dato;
        delete p; //Libera la memoria del nodo
        return valor;
    }

    return 0;
}

//Vacía todos los elementos en la lista
void ListaLigadaSimple::Vaciar()
{

}

//Regresa verdadero si la lista está vaciar
//y falso en caso contrario
bool ListaLigadaSimple::EstaVacia()
{
    return pIni == NULL;
}

//Regresa el número de elementos en la lista
int ListaLigadaSimple::Longitud()
{
    NodoLLS *p = pIni;
    int i =0;
    while(p != NULL)
    {
        p = p->pSig;
        i++;
    }

    return i;
}





ListaLigadaSimple::~ListaLigadaSimple()
{
    //dtor
    Vaciar();  //Se libera la memoria
}
