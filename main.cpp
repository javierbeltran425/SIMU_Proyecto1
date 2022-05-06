#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

#include "Game.h"
#include "headers/staticDS.h"
#include "headers/dynamicDS.h"

template <typename type>
Data Arrays<type>::ref = Data();

char create_letter(int n)
{
    return char(65 + n % 26);
}

int main(void)
{
    /*
     * SECCION PARA EL LOGO
    */
   cout << 
"MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWNX0Okxdoc:;,,'''',,;:cloxk0KNWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n"
"MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMXkdoc:;,''''''''..'.....'''..'';:loxKWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n"
"MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM0:',,'''''',;;;::::c:::::;;;,,'''''..,kWMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n"
"MMMMMMMMMMMMMMMMMMMMMMMMMMMMMWXl''..,;:clooddodoodxdodooddooolcc;....;0NWMMMMMMMMMMMMMMMMMMMMMMMMMMM\n"
"MMMMMMMMMMMMMMMMMMMMMMMMMNkdolc,''.':ooddddddoooololloooddddooool,....,:coxKWMMMMMMMMMMMMMMMMMMMMMMM\n"
"MMMNkdddddddddddddddddddoc,,,'''',,:looolc::;;;,,,,,,,,,;;:cllool:'''......,odddddddddddddddddddddod\n"
"MMMO,.............................''''......'''''''''''''......''''................................,\n"
"MMWo..  ..........    ......   ............ ...............   .....    .........    .....  ....  ..l\n"
"MMK:.  .lxkxdddxxc'.  ,oxxc. ..,oxdddddxd:. 'oxxl.. .cxxo,   .:xxd;. ..:dxdodxd:.. .;dxd:. 'oo'  ..k\n"
"MMk'. .;kK0d,';x0Oo' .cOKO:. ,dO0d;''';od, .:OKOl.  'xK0x:'.';d0Kx, .:xOOo,':k0kl. .o0KOc..:ko. ..;X\n"
"MNl.  .lO0O:..;kK0l. .o00x' .cOKOc.   .... .o00x;  .:O000OkkkO000l. .o00x,..cO0Oc. ,x000kc'lk:  ..oW\n"
"M0;.  'd00d' .cO0k;  ;x0Ol. .oO0d,'',,,'.  ,x0Oo.  .lkxxOOOkxkOOx;  ;xOOl. .oOOd' .:xxdkkl:do.  .'OM\n"
"Wd.. .;xOkc. 'oOko. .ckkd;  ;dkkc';oxkkl. .:xkx;. .,ol':xkx:,okkl. .cxkd;..,dkxc. .lo;;dkxxx:. ..cXM\n"
"Xc.  .cxxo,..;dxd:. .lxxc. .:dxo,..;oxd:. .cxxl. ..:o;.'::;';oxd:. .lddc...:ddo,  'lc',coddl'  ..dWM\n"
"O,.  'cddl;;;coc;.  ,ldo;. .,col;;,,:ll'  ,loo;. .,cc'     .:ooc'  ';coc;;;cl:;. .;c,..'coo:.  .,0MM\n"
"o.. .';;;;;;;;,.   .';;,.   ..,;;;,..''. .';;;.  .',,.     .,;;,.   .';;;;;;'.   .',.  .,;;'  ..lNMM\n"
":................ ........ ...........  ........................     ...........................kMMM\n"
",.............................'',,;;:::;;,,''',,,,,,,,''''',,;;;;;,,''........'''..............:KMMM\n"
"KKKKKKKKKKKKKKKKKKKKKKKK0x:'.....'.'cddddol::;;;;;;;;;;;;:coooddo;''......'lOKKKKKKKKKKKKKK0KKKXWMMM\n"
"MMMMMMMMMMMMMMMMMMMMMMMMMMWXOxo;....;ooddddooddoooooododdodxdoool,....cxk0XWMMMMMMMMMMMMMMMMMMMMMMMM\n"
"MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM0,....',;::cllodoodddodooolllc::;,'...cNMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n"
"MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWOc,........'',,,,,,,,,,,,'''.......'oXMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n"
"MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWN0kdl:;'.................',;:ldk0XWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n"
"MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWX0koc;'........,:lxOKNWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n";
    



    int n = 5, f = 3, c = 4, val;
    int n2, f2, c2, cont;
    int selectedOption = 200;
    /*
        SECCION DE CODIGO PARA EL ARREGLO
    */

    Array<int> *array;
    cout << "TIPO--- " << typeid(array).name() << endl;

    cout << "Probando creación de arreglo de enteros... ";
    Arrays<int>::create(&array, n);

    cout << "Llenando arreglo de enteros con valores... ";
    for (int i = 0; i < n; i++)
        Arrays<int>::insert(array, i, 1);
    cout << "OK\n";

    cout << "Mostrando el arreglo de enteros...\n";
    Arrays<int>::show(array, false);

    /*
        SECCION DE CODIGO PARA LA MATRIZ
    */
    Array<Array<int> *> *matrix;

    cout << "Probando creación de matriz de caracteres... ";
    Arrays<Array<int> *>::create(&matrix, f, c);

    cout << "Llenando matriz de caracteres con valores... ";
    for (int i = 0; i < f * c; i++)
        Arrays<Array<int> *>::insert(matrix, i / c, i % c, array);
    cout << "OK\n";

    cout << "Mostrando la matriz de caracteres...\n";
    Arrays<Array<int> *>::show(matrix, true); // false indica que no se necesita modo VERBOSE

    /*
        SECCION DE CODIGO PARA LA LISTA ENLAZADA DOBLE
    */
    DS<Array<Array<int> *> *> *DL;

    cout << "Probando creación de lista enlazada doble... ";

    Dynamic_Structures<Array<Array<int> *> *>::create(&DL, DOUBLE_LINKED_LIST);
    cout << "OK\n";

    cout << "Probando inserción en lista enlazada doble... ";
    for (int i = 10; i > 0; i--)
        Dynamic_Structures<Array<Array<int> *> *>::insert(DL, matrix);

    cout << "Mostrando lista...\n";
    Dynamic_Structures<Array<Array<int> *> *>::show(DL, true);

    /*
        SECCION DE CODIGO PARA ARBOL BINARIO
    */
   /*
    DS<DS<Array<Array<int> *> *> *> *T;
    cout << "Probando creación de árbol... ";

    Dynamic_Structures<DS<Array<Array<int> *> *> *>::create(&T, BINARY_SEARCH_TREE);
    cout << "OK\n";

    cout << "Probando inserción en árbol... ";

    //int datos[10] = {77, 84, 39, 72, 56, 78, 100, 72, 98, 17};

    for (int i = 0; i < 10; i++)
        Dynamic_Structures<DS<Array<Array<int> *> *> *>::insert(T, DL);

    cout << "Mostrando árbol...\n";
    Dynamic_Structures<DS<Array<Array<int> *> *> *>::show(T, true);

    cout << "\n";
*/
    /*
        SECCION DE CODIGO PARA EL GRAFO
    */
/*
    DS<DS<DS<Array<Array<int> *> *> *> *> *G;
    Dynamic_Structures<DS<DS<Array<Array<int> *> *> *> *>::create(&G, GRAPH);
    cout << "OK\n";

    for (int i = 0; i < 5; i++)
        Dynamic_Structures<DS<DS<Array<Array<int> *> *> *> *>::insert(G, i + 1, T);

    cout << "Mostrando grafo...\n";
    Dynamic_Structures<DS<DS<Array<Array<int> *> *> *> *>::show(G, false);

    cout << "Probando definición de conexiones para los nodos del grafo...\n";
*/
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
    //int M[5][4] = { { 1, 3, 4, -99 }, { 2, 3, 5, -99 }, { 3, 4, 1, 2 }, { 4, 3, 1, 5 }, { 5, 4, 2, -99 } };

    // Definiendo las conexiones
    // Dynamic_Structures<int>::define_connections(G, M);

    // cout << "Impresion del grafo con las conexiones ya establecidas\n";
    // Dynamic_Structures<int>::show(G,false);

/*
    cout << endl
         << endl
         << endl;
*/
    Game::mainMenu();

    do
    {
        if ((selectedOption < 1 || selectedOption > 5) && selectedOption != 200)
            cout << "Ingrese una opcion valida" << endl;

        cout << "Ingrese su eleccion: ";
        cin >> selectedOption;

    } while (selectedOption < 1 || selectedOption > 5 && selectedOption != 200);

    cout << "WENAAASSSSS";

    //Dynamic_Structures<DS<DS<Array<Array<int> *> *> *> *>::destroy(G);
    //Dynamic_Structures<DS<Array<Array<int> *> *> *>::destroy(T);
    Dynamic_Structures<Array<Array<int> *> *>::destroy(DL);

    //delete G;
    //delete T;
    delete DL;
    delete matrix;

    return 0;
}
