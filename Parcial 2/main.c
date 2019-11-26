#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Estructura.h"
#include "PediryValidar.h"

#define TP 5


int main()
{
    LinkedList* lista = ll_newLinkedList();
    LinkedList* listaAux = ll_newLinkedList();
    LinkedList* listaAux2 = ll_newLinkedList();
    FILE* pFile = fopen("data.csv","r");
    int flag = 0;
    int opcion;
    do
    {
        getValidInt("1.Cargar Archivo\n2.Imprimir Vuelos\n3.Filtro Portugal\n4.Filtro Alex\n","Error",0,5,&opcion);

        switch(opcion)
        {
        case 1:
            system("cls");
            parser_ClientFromText(pFile,lista);
            fclose(pFile);
            flag = 1;
            break;
        case 2:
            system("cls");
            if(flag == 1)
            {
             mostrarDatos(lista);
            }
            else
            {
                printf("No hay datos cargados");
            }
            break;
        case 3:
            system("cls");
            if(flag == 1)
            {
                listaAux = ll_filter(lista,filterPortugal);
                mostrarDatos(listaAux);
            }
            else
            {
                           printf("No hay datos cargados");

            }
            break;
        case 4:
            system("cls");
            if(flag == 1)
            {
              listaAux2 = ll_filter(lista,filterAlex);
            mostrarDatos(listaAux2);
            }
            else
            {

            printf("No hay datos cargados");
            }
            break;
        case 5:
            opcion = 5;
            break;
        }

    }while(opcion != 5);
    return 0;
}
