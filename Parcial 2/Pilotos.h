#include <stdio.h>
#include <stdlib.h>

typedef struct
{
  int idPiloto;
  char nombre[50];
}ePilotos;


void hardcodeDescripcionProblema(ePilotos* listaPilotos,int TP);

int piloto_SetNombre(ePilotos* this,char* nombre);
int piloto_GetNombre(ePilotos* this,char* nombre);

int piloto_SetId(ePilotos* this,int idPiloto);
int piloto_GetId(ePilotos* this,int* idPiloto);
