#include "NodoLLS.h"

NodoLLS::NodoLLS()
{
    dato = 0;
    pSig = NULL;
}

NodoLLS::NodoLLS(int dato)
{
    this->dato = dato;
    this->pSig = NULL;
}

NodoLLS::NodoLLS(int dato, NodoLLS *pSig)
{
    this->dato = dato;
    this->pSig = pSig;
}




NodoLLS::~NodoLLS()
{
    //dtor
}
