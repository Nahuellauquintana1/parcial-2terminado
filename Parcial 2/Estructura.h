#include <stdio.h>
#include <stdlib.h>
#include "Pilotos.h"
typedef struct
{
  int idVuelo;
  int idAvion;
  int idPiloto;
  char fecha[20];
  char destino[50];
  int cantPasajeros;
  int horaDespegue;
  int horaLlegada;

}eVuelos;


void mostrarDatos(LinkedList* lista);
void mostrarVuelo(eVuelos* unVuelo);
eVuelos* vuelos_new();
eVuelos* Vuelos_newParametros(char* idVuelo,char* Fecha ,char* idAvion, char* idPiloto,char* Destino, char* cantPasajeros, char* horaDespegue, char* horaLlegada);

int filterPortugal(void* pElement);
int filterAlex(void* pElement);

int vuelos_getDestino(eVuelos* this,char* destino);
int vuelos_setDestino(eVuelos* this,char* destino);

int vuelos_getHoraLLegada(eVuelos* this,int* horaLLegada);
int vuelos_setHoraLLegada(eVuelos* this,int horaLLegada);

int vuelos_getHoraDespegue(eVuelos* this,int* horaDespegue);
int vuelos_setHoraDespegue(eVuelos* this,int horaDespegue);

int vuelos_getCanPasajeros(eVuelos* this,int* cantPasajeros);
int vuelos_setCanPasajeros(eVuelos* this,int cantPasajeros);

int vuelos_getIdPiloto(eVuelos* this,int* idPiloto);
int vuelos_setIdPiloto(eVuelos* this,int idPiloto);

int vuelos_getIdAvion(eVuelos* this,int* idAvion);
int vuelos_setIdAvion(eVuelos* this,int idAvion);

int vuelos_getFecha(eVuelos* this,char* Fecha);
int vuelos_setFecha(eVuelos* this,char* Fecha);

int vuelos_getIdVuelo(eVuelos* this,int* idVuelos);
int vuelos_setIdVuelo(eVuelos* this,int idVuelos);


