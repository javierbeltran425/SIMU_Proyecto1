template <typename type>
class DSG: public DS<type>{
    private:
        NodeG<type>* G;

        void* createNode() override{
            return malloc(sizeof(NodeG<type>));
        }

    public:
        // Obtener el nodo inicial del grafo
        Node<type>* getRoot(){
            return G;
        }

        // Retornar la categoria de la DS
        category getCategory() override {
            return GRAPH;
        }

        // Inicializa el grafo
        void create() override {
            G = NULL;
        }

        // Tamaño del grafo
        int extension() override {
            int cont = 0;

            NodeG<type>* Gcopy = G;

            while (Gcopy !== null)
            {
                cont ++;

                Gcopy = Gcopy -> next;
            }
            
            return cont;
        }

        /*
        * Función que niega la inserción de datos si esta no viene con los datos
        * adicionales que son requeridos.
        */
        void insert(type values) override {
            cout << "N/A\n";
        }

        /*
        * Función para la inserción de datos en el grafo
        */
       void insert(int id, type value) override {
           NodeG<type> temp = (NodeG<type>*) createNode();

           temp->id = id;

           temp->data = value;

           temp->connections = NULL;

           if(G == NULL){
               temp->entry = true;

               temp->next = NULL;
           }else{
               temp->entry = false;

               temp->next = G;
           }

           G = temp;
       }

       /*
       * Función para extraer un dato del grafo
       */
      type extract(int id) override {
          NodeG<type>* Gcopy = 0;

          while (Gcopy != NULL)
          {
              if(Gcopy->id == id) break;

              Gcopy = Gcopy-> next;
          }
          
          return Gcopy->data;
      }

      /*
       * Función para liberar todo el espacio de memoria que fue reservado por el grafo 
       * para devolversela al sistema
       */
    void destroy() override {
        // Variables auxiliares para el proceso
        NodeG<type>* temp;
        NodeSL<NodeG<type>*>* L;
        NodeSL<NodeG<type>*>* tempL;

        while (G != NULL)
        {
            temp = G;

            L = temp->connections;

            while (L !== NULL)
            {
                tempL = L;

                L = L-> next;

                free(tempL);
            }
            
        }
        
    }

    /*
     * Funci+on para determinar si un valor existe dentro del grafo
     * Retorna un booleano
     */
    bool search(type value) override {
        bool ans = false;

        NodeGztype>* Gcopy = G;

        while (Gcopy != NULL)
        {
            if(Gcopy->data == value) {
                ans = true;
                break;
            }

            Gcopy = Gcopy->next;
        }
        
        return ans;
    }

    /*
     * Funcion para determinar la cantidad de veces que existe un dato dentro del grafo
     */
    int count(type value) override {
        int cont = 0;

        NodeG<type>* Gcopy = G;

        while (Gcopy != NULL)
        {
            if(Gcopy->data == value) cont ++;
            
            Gcopy = Gcopy->next;
        }
        
        return cont;
    }

    /*
     * Para un grafo no es aplicable la inversión de su contenido
     */
    void reverse() override {
        cout << "N/a\n";
    }

    /*
     * Función para mostrar el contenido del grafo
     * <verbose> = true : Para detallar posición por posición y conexión por conexión el contenido del grafo.
     * <verbose> = false : Solamente se muestra el grafo como tal.
     */
    void show(bool verbose) override {
        if(G == NULL) {
            cout << "El grafo está vacio.\n";
            return;
        }

        NodeG<type>* Gcopy = G; //Copia del puntero inicial para no perder la referencia.
        NodeSL<NodeG<type>*>* L; // Variable auxiliar para el proceso.

        if(verbose) {
            while (Gcopy != NULL)
            {
                // Mostramos el ID y el dato del nodo actual
                cout << "Nodo #" << Gcopy->id << ":\n\tDatos: " << Gcopy->data << "\n\tConexiones:\n";

                L = Gcopy->connections;

                int index = 1;

                while (L != NULL)
                {
                    cout << "\tConexion #" << index << " corresponde al nodo #" << L->data->id << "\n";

                    index++;

                    L = L->next;
                }

                Gcopy = Gcopy->next;
            }
            
        } else {
            while (Gcopy != NULL)
            {
                cout << "( " << Gcopy->id << " , " << Gcopy->data << " , [ ";

                L = Gcopy->connections;

                while (L != NULL)
                {
                    cout << L->data->id << "->";

                    L = L->next;
                }

                cout << "NULL ] )" << " -> ";

                Gcopy = Gcopy->next;                
            }
            
            cout << "NULL\n";
        }
    }
};