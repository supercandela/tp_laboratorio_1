/*
    utest example : Unit test examples.
    Copyright (C) <2018>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef __LINKEDLIST
#define __LINKEDLIST
struct Node
{
    void* pElement;
    struct Node* pNextNode;
}typedef Node;

struct LinkedList
{
    Node* pFirstNode;
    int size;
}typedef LinkedList;
#endif



//Publicas
//nueva lista. la lista es dinámica
LinkedList* ll_newLinkedList(void);
// longitud de la lista
int ll_len(LinkedList* this);
//no las usamos las test
Node* test_getNode(LinkedList* this, int nodeIndex);
int test_addNode(LinkedList* this, int nodeIndex,void* pElement);
//agrega pax, no importa dónde
int ll_add(LinkedList* this, void* pElement);
//retorna el pasajero que pasó por index -tal vez haya que castear
void* ll_get(LinkedList* this, int index);
//setea en el index el elemento que le paso. sobre escribe lo que haya en ese lugar
int ll_set(LinkedList* this, int index,void* pElement);
//elimina elemento de la lista, como que lo pasa a null. el free lo tengo que hacer yo
int ll_remove(LinkedList* this,int index);
//las int devuelven éxito o fracaso, as usual
//remove de toda la lista
int ll_clear(LinkedList* this);
//elimina la lista. no hace el free de los elementos
int ll_deleteLinkedList(LinkedList* this);
//devuelve el índice de un elemento
int ll_indexOf(LinkedList* this, void* pElement);
//verifica si la lista tiene algo cargado
int ll_isEmpty(LinkedList* this);
//agrega un elemento en la lista en el index específico. Empuja el resto de la lista
int ll_push(LinkedList* this, int index, void* pElement);
//retorna el elemento que está en la posición index y lo saca de la lista.
void* ll_pop(LinkedList* this,int index);
//verifica si el elemento está en la lista
int ll_contains(LinkedList* this, void* pElement);
//verifica si la lista 2 está contenida en la lista 1
int ll_containsAll(LinkedList* this,LinkedList* this2);
//Crea una nueva lista desde el primer elemento al segundo elemento
LinkedList* ll_subList(LinkedList* this,int from,int to);
//crea una nueva lista, exactamente igual a la original
LinkedList* ll_clone(LinkedList* this);
//ordena la lista. recibe la lista, un puntero a función y el orden
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order);
