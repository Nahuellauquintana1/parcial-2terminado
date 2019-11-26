#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Estructura.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_ClientFromText(FILE* pFile , LinkedList* lista)
{
     char idVuelo [100];
     char idAvion [100];
     char idPiloto[100];
     char fecha[100];
     char destino[100];
     char cantPasajeros[100];
     char horaDespegue[100];
     char horaLlegada[100];
     eVuelos* unVuelo;
     fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",idVuelo,idAvion,idPiloto,fecha,destino,cantPasajeros,horaDespegue,horaLlegada);
     while(!feof(pFile))
    {
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",idVuelo,idAvion,idPiloto,fecha,destino,cantPasajeros,horaDespegue,horaLlegada);
        unVuelo = Vuelos_newParametros(idVuelo,idAvion,idPiloto,fecha,destino,cantPasajeros,horaDespegue,horaLlegada);
        ll_add(lista, unVuelo);
    }
    return 1;
}

int saveAsText(char* path, LinkedList* lista)
{
    FILE* pFile;
    eVuelos* aux;
    int len, i;
    len = ll_len(lista);
    pFile = fopen(path,"w");
    for(i = 0; i < len; i++)
    {
        aux = ll_get(lista,i);
        fprintf(pFile,"%d,%d,%d,%s,%s,%d,%d,%d\n",aux->idVuelo,aux->idAvion,aux->idPiloto,aux->fecha,aux->destino,aux->cantPasajeros,aux->horaDespegue,aux->horaLlegada);
    }
    return 1;
}
