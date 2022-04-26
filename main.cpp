#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

#include "Game.h"
#include "headers/dynamicDS.h"
#include "headers/staticDS.h"

template <typename type>
Data Arrays<type>::ref = Data();

char create_letter(int n){
    return char(65 + n % 26);
}

int main(void)
{
   int n = 5, f = 3, c = 4, val;
   int n2, f2, c2, cont;
    /*
        SECCION DE CODIGO PARA EL ARREGLO
    */
   Array<int>* array;

   cout << "Probando creación de arreglo de enteros... ";
   Arrays<int>::create(&array, n);

   cout << "Llenando arreglo de enteros con valores... ";
    for(int i = 0; i < n; i++)
        Arrays<int>::insert(array,i,i);
    cout << "OK\n";

    cout << "Mostrando el arreglo de enteros...\n";
    Arrays<int>::show(array,false);

    /*
        SECCION DE CODIGO PARA LA MATRIZ
    */
   Array<char>* matrix;

    cout << "Probando creación de matriz de caracteres... ";
    Arrays<char>::create(&matrix,f,c);


    cout << "Llenando matriz de caracteres con valores... ";
    for(int i = 0; i < f2*c2; i++)
        Arrays<char>::insert(matrix,i/c2,i%c2,create_letter(i));
    cout << "OK\n";

    cout << "Mostrando la matriz de caracteres...\n";
    Arrays<char>::show(matrix,false); //false indica que no se necesita modo VERBOSE

    /*
        SECCION DE CODIGO PARA LA LISTA ENLAZADA DOBLE
    */
    DS<int>* DL;

    cout << "Probando creación de lista enlazada doble... ";
   
    Dynamic_Structures<int>::create(&DL,DOUBLE_LINKED_LIST);
    cout << "OK\n";

    cout << "Probando inserción en lista enlazada doble... ";
    for(int i = 10; i > 0; i--)
        Dynamic_Structures<int>::insert(DL, i);
    
    cout << "Mostrando lista...\n";
    Dynamic_Structures<int>::show(DL,false);


    /*
        SECCION DE CODIGO PARA ARBOL BINARIO
    */
    DS<int>* T;
    cout << "Probando creación de árbol... ";

    Dynamic_Structures<int>::create(&T,BINARY_SEARCH_TREE);
    cout << "OK\n";

    cout << "Probando inserción en árbol... ";
    
    int datos[10] = {77,84,39,72,56,78,100,72,98,17};

    for(int i = 0; i < 10; i++)
    Dynamic_Structures<int>::insert(T, datos[i]);

    cout << "Mostrando árbol...\n";
    Dynamic_Structures<int>::show(T,false);

    cout << "\n";



    /*
        SECCION DE CODIGO PARA EL GRAFO
    */

    DS<int>* G;
    Dynamic_Structures<int>::create(&G, GRAPH);
    cout << "OK\n";

    for (int i = 0; i < 5; i++)
        Dynamic_Structures<int>::insert(G, i+1, i+1);

    cout << "Mostrando grafo...\n";
    Dynamic_Structures<int>::show(G, false);

    cout << "Probando definición de conexiones para los nodos del grafo...\n";

    /*
    GRAFO A CONSTRUIR

        1 ------ 4 ------- 5
           \       |         |
             \     |         |
               \   |         |
                 \ |         |
                   3 ------- 2
    */

    // Definicion de la matriz que contiene las conexiones de cada nodo del grafo
    int M[5][4] = { { 1, 3, 4, -99 }, { 2, 3, 5, -99 }, { 3, 4, 1, 2 }, { 4, 3, 1, 5 }, { 5, 4, 2, -99 } };

    // Definiendo las conexiones
    Dynamic_Structures<int>::define_connections(G, M);

    cout << "Impresion del grafo con las conexiones ya establecidas\n";
    Dynamic_Structures<int>::show(G,false);

    cout << "\n";

    Game::mainMenu();

    Dynamic_Structures<int>::destroy(G);
    Dynamic_Structures<int>::destroy(T);
    Dynamic_Structures<int>::destroy(DL);

    delete G;
    delete T;
    delete DL;
    delete matrix;

    return 0;
}
