#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"

static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this= NULL;
    this = (LinkedList*)malloc(sizeof(LinkedList));
    if(this != NULL)
    {
        this->pFirstNode = NULL;
        this->size = 0;
    }

    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1;
    if(this != NULL)
    {
        returnAux = this->size;
    }

    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
    int i;
    int len = ll_len(this);
    Node* actual = NULL;
    if(this != NULL && (nodeIndex > -1 && nodeIndex < len ))
    {
        actual = this->pFirstNode;
        for(i = 0; i < nodeIndex ; i++)
        {
            actual = actual->pNextNode;
        }
    }
    return actual;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux = -1;
    Node* anterior = NULL;
    Node* nuevo = NULL;

    if(this != NULL)
    {
        int len = ll_len(this);
        if(nodeIndex > -1 && nodeIndex <= len)
        {

            if(nodeIndex == 0)
            {
                nuevo = (Node*)malloc(sizeof(Node));
                nuevo->pNextNode = this->pFirstNode;
                this->pFirstNode = nuevo;
                nuevo->pElement = pElement;
                returnAux = 0;

            }
            else
            {
                anterior = getNode(this,nodeIndex-1);
                nuevo = (Node*)malloc(sizeof(Node));
                nuevo->pNextNode = anterior->pNextNode;
                anterior->pNextNode = nuevo;
                nuevo->pElement = pElement;
                returnAux = 0;
            }
            this->size++;
        }
    }

    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElemento)
{
    int returnAux = -1;
    if(this != NULL)
    {
        int len = ll_len(this);
        addNode(this,len,pElemento);
        returnAux = 0;
    }
    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    int auxLen;
    Node* aux;
    auxLen = ll_len(this);
    if(this != NULL &&(index >= 0 && index < auxLen))
    {
        aux = getNode(this, index);
        returnAux = (void*)aux->pElement;
    }
    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;
    if(this != NULL)
    {
        int len = ll_len(this);
        if(index > -1 && index < len)
        {
            getNode(this,index)->pElement = pElement;
            returnAux = 0;
        }
    }
    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;
    Node* anterior = NULL;
    Node* remover = NULL;
    if(this != NULL)
    {
        int len = ll_len(this);
        if(index > -1 && index < len)
        {
            if(index == 0)
            {
                remover = getNode(this,index);
                this->pFirstNode = remover->pNextNode;
                free(remover);
                returnAux = 0;
            }
            else
            {
                anterior = getNode(this,index-1);
                remover = getNode(this,index);
                anterior->pNextNode = remover->pNextNode;
                free(remover);
                returnAux = 0;
            }
            this->size--;
        }
    }
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1;
    Node* actual = NULL;
    Node* aux = NULL;
    if(this != NULL)
    {
        int len = ll_len(this);
        actual = this->pFirstNode;
        int i;
        for(i = 0; i < len; i++)
        {
            aux = actual;
            actual = actual->pNextNode;
            free(aux);
        }
        returnAux = 0;
    }
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;
    Node* actual;
    if(this != NULL)
    {
        int len = ll_len(this);
        actual = this->pFirstNode;
        int i;
        for(i = 0; i < len; i++)
        {
            free(actual);
        }
        free(this);
        returnAux = 0;
    }
    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int contador = 0;
    Node* actual;
    if(this != NULL)
    {
        actual = this->pFirstNode;
        while(actual)
        {

            if(actual->pElement == pElement)
            {
                returnAux = contador;
                break;
            }
            actual = actual->pNextNode;
            contador++;
        }
    }
    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;
    if(this != NULL)
    {
        int len = ll_len(this);
        if(len == 0)
        {
            returnAux = 1;
        }
        else
        {
            returnAux = 0;
        }
    }
    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;
    if(this != NULL)
    {
        int len = ll_len(this);
        if(index > -1 && index <= len)
        {
            addNode(this,index,pElement);
            returnAux = 0;
        }
    }
    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;
    Node* aux;
    if(this != NULL)
    {
        int len = ll_len(this);
        if(index > -1 && index < len)
        {
            aux = getNode(this,index);
            returnAux = aux->pElement;
            ll_remove(this,index);
        }
    }
    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    Node* actual;
    if(this != NULL)
    {
        returnAux = 0;
        actual = this->pFirstNode;
        while(actual)
        {
            if(actual->pElement == pElement)
            {
                returnAux = 1;
                break;
            }
            actual = actual->pNextNode;
        }
    }
    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;
    Node* actual;
    if(this != NULL)
    {
        if(this2 != NULL )
        {
            int lenThis2 = ll_len(this2);
            int i;
            for(i = 0; i < lenThis2; i++)
            {
                actual = ll_get(this2,i);
                if(0 == ll_contains(this,actual))
                {
                    returnAux =  0;
                    break;
                }
            }
            if(returnAux != 0)
            {
                returnAux = 1;
            }
        }
    }
    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;
    Node* aux = NULL;
    if(this != NULL)
    {
        int len = ll_len(this);
        if(from >= 0 && to >= from && from < len && to <= len)
        {
            cloneArray = ll_newLinkedList();
            int i;
            for(i = from; i < to; i++)
            {
                aux = ll_get(this,i);
                ll_add(cloneArray,aux);
            }
        }
    }
    return cloneArray;
}

/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;
    Node* aux = NULL;
    if(this != NULL)
    {
        cloneArray = ll_newLinkedList();
        int len = ll_len(this);
        int i;
        for(i = 0; i < len; i++)
        {
            aux = ll_get(this,i);
            ll_add(cloneArray,aux);
        }
    }
    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void*,void*), int order)
{
    int returnPFuncion;
    void* aux = NULL;
    int returnAux =-1;

    if(this != NULL && pFunc != NULL && (order == 1 || order == 0))
    {
        int len = ll_len(this);
        int i;
        for(i=0; i<len-1; i++)
        {
            int j;
            for(j=i+1; j<len; j++)
            {
                returnPFuncion = pFunc(ll_get(this,i),ll_get(this,j));
                if(order == 1)
                {
                    if(returnPFuncion == 1)
                    {
                        aux = ll_get(this,i);
                        ll_set(this,i,ll_get(this,j));
                        ll_set(this,j,aux);
                    }
                }
                else
                {
                    if(returnPFuncion == -1)
                    {
                        aux = ll_get(this,i);
                        ll_set(this,i,ll_get(this,j));
                        ll_set(this,j,aux);
                    }
                }
            }
        }
        returnAux = 0;
    }
    return returnAux;
}

LinkedList* ll_filter(LinkedList* this,int (*fn)(void*pElement))
{
    LinkedList* filterList = NULL;
    int resultado;
    void* aux;
    int i;

    if(this != NULL && fn != NULL)
    {
        int len = ll_len(this);
        filterList = ll_newLinkedList();
        for(i = 0; i < len; i++)
        {
            aux = ll_get(this,i);
            resultado = fn(aux);

            if(resultado == 1)
            {
                ll_add(filterList,aux);
            }
        }
    }
    return filterList;
}
