#ifndef NODOLLS_H
#define NODOLLS_H
#include <iostream>

class NodoLLS
{
public:
    int dato;  //DAto a almacenar en un nodo
    NodoLLS *pSig = NULL;


    public:
        //Constructores
        NodoLLS();
        NodoLLS(int dato);
        NodoLLS(int dato, NodoLLS *pSig);

        //GET /SET
        /*
        void SetDato(int dato);
        int GetDato();
        void SetNodoSig(NodoLLS *pSig);
        NodoLLS *GetDato();
        */

        //


        virtual ~NodoLLS();

    protected:

    private:
};

#endif // NODOLLS_H
