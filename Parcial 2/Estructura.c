#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Estructura.h"
#include "PediryValidar.h"




void mostrarDatos(LinkedList* lista)
{
    int i, tam;
    tam = ll_len(lista);
    eVuelos* aux;
    printf("idVuelo\tidAvion\tidPiloto\tfecha\tdestino\tcantPasajeros\thoraDespegue\thoraLlegada\n");
    for(i= 0; i<tam ; i++)
    {
        aux = (eVuelos*)ll_get(lista,i);
        mostrarVuelo(aux);
    }
    return 0;
}
void mostrarVuelo(eVuelos* unVuelo)
{
    int i;
    char auxFecha[50];
    char auxDestino[50];
    int idVueloAux, idAvionAux,cantPasaerosAux,horaDespegueAux,horaLlegadaAux,idPilotoAux;

    if(unVuelo != NULL)
    {
        vuelos_getFecha(unVuelo,auxFecha);
        vuelos_getDestino(unVuelo,auxDestino);
        vuelos_getCanPasajeros(unVuelo,&cantPasaerosAux);
        vuelos_getHoraDespegue(unVuelo,&horaDespegueAux);
        vuelos_getHoraLLegada(unVuelo,&horaLlegadaAux);
        vuelos_getIdAvion(unVuelo,&idAvionAux);
        vuelos_getIdVuelo(unVuelo,&idVueloAux);
        vuelos_getIdPiloto(unVuelo,&idPilotoAux);

        printf("%-10d", idVueloAux);
        printf("%-10d", idAvionAux);
        switch(idPilotoAux)
        {
        case 1:
            printf("Alex Lifeson\t");
            break;
        case 2:
            printf("Richard Bach\t");
            break;
        case 3:
            printf("John Kerry\t");
            break;
        case 4:
            printf("Erwin Rommel\t");
            break;
        case 5:
            printf("Stephen Coonts\t");
            break;
        }
        printf("%-10s\t", auxFecha);
        printf("%-10s", auxDestino);
        printf("%-10d", cantPasaerosAux);
        printf("%-10d", horaDespegueAux);
        printf("%-10d\n",horaLlegadaAux);
    }
}

eVuelos* Vuelos_newParametros(char* idVuelo,char* idAvion,char* idPiloto, char* Fecha,char* Destino, char* cantPasajeros, char* horaDespegue, char* horaLlegada)
{

    eVuelos* this;
    int idVueloAux,idAvionAux,idPilotoAux,cantPasajerosAux,horaDespegueAux,horaLlegadaAux;

    if (idVuelo != NULL && Fecha != NULL && idAvion != NULL && idPiloto != NULL && Destino != NULL && cantPasajeros != NULL && horaDespegue != NULL && horaLlegada != NULL)
    {
        this  = vuelos_new();

        if( this != NULL)
        {
            idVueloAux = atoi(idVuelo);

            idAvionAux = atoi(idAvion);

            idPilotoAux = atoi(idPiloto);

            cantPasajerosAux = atoi(cantPasajeros);

            horaDespegueAux = atoi(horaDespegue);

            horaLlegadaAux = atoi(horaLlegada);

            vuelos_setIdVuelo(this,idVueloAux);

            vuelos_setFecha(this,Fecha);

            vuelos_setIdAvion(this,idAvionAux);

            vuelos_setIdPiloto(this,idPilotoAux);

            vuelos_setDestino(this,Destino);

            vuelos_setCanPasajeros(this,cantPasajerosAux);

            vuelos_setHoraDespegue(this,horaDespegueAux);

            vuelos_setHoraLLegada(this,horaLlegadaAux);
        }
    }

    return this;
}
eVuelos* vuelos_new()
{
    eVuelos* this = (eVuelos*) malloc(sizeof(eVuelos));

    if( this != NULL)
    {
        this->idVuelo = 0;
        strcpy(this->fecha, "");
        this->idPiloto = 0;
        this->cantPasajeros = 0;
        strcpy(this->destino, "");
        this->horaDespegue = 0;
        this->horaLlegada = 0;
    }

    return this;
}

int vuelos_setIdVuelo(eVuelos* this,int idVuelos)
{

    int returnAux = 0;

    if( this != NULL && idVuelos > 0)
    {

        this->idVuelo = idVuelos;
        returnAux = 1;
    }

    return returnAux;
}

int vuelos_getIdVuelo(eVuelos* this,int* idVuelos)
{

    int returnAux = 0;

    if( this != NULL && idVuelos != NULL )
    {

        *idVuelos = this->idVuelo;
        returnAux = 1;
    }
    return returnAux;
}

int vuelos_setFecha(eVuelos* this,char* Fecha)
{
    int returnAux = 0;

    if( this != NULL && Fecha != NULL && strlen(Fecha) > 3)
    {

        strcpy(this->fecha, Fecha);
        returnAux = 1;
    }

    return returnAux;

}
int vuelos_getFecha(eVuelos* this,char* fecha)
{

    int returnAux = 0;

    if( this != NULL && fecha != NULL )
    {

        strcpy(fecha, this->fecha);
        returnAux = 1;
    }

    return returnAux;

}

int vuelos_setIdAvion(eVuelos* this,int idAvion)
{

    int returnAux = 0;

    if( this != NULL && idAvion > 0)
    {

        this->idAvion = idAvion;
        returnAux = 1;
    }

    return returnAux;
}
int vuelos_getIdAvion(eVuelos* this,int* idAvion)
{

    int returnAux = 0;

    if( this != NULL && idAvion != NULL )
    {

        *idAvion = this->idAvion;
        returnAux = 1;
    }
    return returnAux;

}

int vuelos_setIdPiloto(eVuelos* this,int idPiloto)
{

    int returnAux = 0;

    if( this != NULL && idPiloto > 0)
    {

        this->idPiloto = idPiloto;
        returnAux = 1;
    }

    return returnAux;

}
int vuelos_getIdPiloto(eVuelos* this,int* idPiloto)
{
    int returnAux = 0;

    if( this != NULL && idPiloto > 0)
    {

        *idPiloto = this->idPiloto;
        returnAux = 1;
    }

    return returnAux;
}
int vuelos_setCanPasajeros(eVuelos* this,int cantPasajeros)
{
    int returnAux = 0;

    if( this != NULL && cantPasajeros != NULL )
    {

        this->cantPasajeros = cantPasajeros;
        returnAux = 1;
    }
    return returnAux;
}
int vuelos_getCanPasajeros(eVuelos* this,int* cantPasajeros)
{
    int returnAux = 0;

    if( this != NULL && cantPasajeros != NULL )
    {

        *cantPasajeros = this->cantPasajeros;
        returnAux = 1;
    }
    return returnAux;
}

int vuelos_setHoraDespegue(eVuelos* this,int horaDespegue)
{
    int returnAux = 0;

    if( this != NULL && horaDespegue != NULL )
    {

        this->horaDespegue = horaDespegue;
        returnAux = 1;
    }
    return returnAux;
}
int vuelos_getHoraDespegue(eVuelos* this,int* horaDespegue)
{
    int returnAux = 0;

    if( this != NULL && horaDespegue != NULL )
    {

        *horaDespegue = this->horaDespegue;
        returnAux = 1;
    }
    return returnAux;
}
int vuelos_setHoraLLegada(eVuelos* this,int horaLLegada)
{
    int returnAux = 0;

    if( this != NULL && horaLLegada != NULL )
    {

        this->horaLlegada = horaLLegada;
        returnAux = 1;
    }
    return returnAux;
}
int vuelos_getHoraLLegada(eVuelos* this,int* horaLLegada)
{
    int returnAux = 0;

    if( this != NULL && horaLLegada != NULL )
    {

        *horaLLegada = this->horaLlegada;
        returnAux = 1;
    }
    return returnAux;
}
int vuelos_setDestino(eVuelos* this,char* destino)
{
    int returnAux = 0;

    if( this != NULL && destino != NULL && strlen(destino) > 3)
    {

        strcpy(this->destino, destino);
        returnAux = 1;
    }

    return returnAux;

}
int vuelos_getDestino(eVuelos* this,char* destino)
{

    int returnAux = 0;

    if( this != NULL && destino != NULL )
    {

        strcpy(destino, this->destino);
        returnAux = 1;
    }

    return returnAux;

}


int filterPortugal(void* pElement)
{
    int resultado = 0;
    eVuelos* unVuelo = (eVuelos*)pElement;
    char vuelo[50];
    vuelos_getDestino(unVuelo,vuelo);
    if(strcmp(vuelo,"Portugal")== 0)
    {
        resultado = 1;
    }
    return resultado;
}

int filterAlex(void* pElement)
{
    int resultado = 0;
    eVuelos* unVuelo = (eVuelos*)pElement;
    int idAux;
    vuelos_getIdPiloto(unVuelo,&idAux);
    if(idAux != 1)
    {
        resultado = 1;
    }
    return resultado;
}
