#include<iostream>
using namespace std;

#include "Game.h"
#include "headers/dynamicDS.h"



int main(void) {

    DS<int>* G;
    Dynamic_Structures<int>::create(&G,GRAPH);
    cout << "OK\n";
    
    for(int i = 0; i < 10; i++)
     Dynamic_Structures<int>::insert(G, i+1, i+1);

    cout << "Mostrando grafo...\n";
    Dynamic_Structures<int>::show(G,false);

 
    Game::mainMenu();
    
    
    Dynamic_Structures<int>::destroy(G);
    delete G;
    return 0;
}

