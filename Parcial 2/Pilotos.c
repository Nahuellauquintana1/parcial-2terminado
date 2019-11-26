#include <stdio.h>
#include <stdlib.h>
#include "Pilotos.h"

int piloto_SetNombre(ePilotos* this,char* nombre)
{

    int returnAux = 0;

    if( this != NULL && nombre != NULL && strlen(nombre) > 3)
    {

        strcpy(this->nombre, nombre);
        returnAux = 1;
    }

    return returnAux;

}

int piloto_GetNombre(ePilotos* this,char* nombre)
{

    int returnAux = 0;

    if( this != NULL && nombre != NULL )
    {

        strcpy(nombre, this->nombre);
        returnAux = 1;
    }

    return returnAux;

}

int piloto_SetId(ePilotos* this,int idPiloto)
{

    int returnAux = 0;

    if( this != NULL && idPiloto > 0)
    {

        this->idPiloto = idPiloto;
        returnAux = 1;
    }

    return returnAux;
}

int piloto_GetId(ePilotos* this,int* idPiloto)
{

    int returnAux = 0;

    if( this != NULL && idPiloto != NULL )
    {

        *idPiloto = this->idPiloto;
        returnAux = 1;
    }
    return returnAux;
}


void hardcodeDescripcionProblema(ePilotos* listaPilotos,int TP)
{
    int codigoAux[] = {1,2,3,4,5};
    char nombre[][50]= {"Alex Lifeson","Richard Bach","John Kerry","Erwin Rommel","Stephen Coonts"};
    int i;
    for(i = 0; i < TP; i++)
    {
       listaPilotos[i].idPiloto= codigoAux[i];
       strcpy(listaPilotos[i].nombre,nombre[i]);
    }
}
