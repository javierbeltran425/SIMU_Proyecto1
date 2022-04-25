
class Game{
    private:

        static void showMainMenu(){
            cout << "MENU INICIAL\n"
                    "=============\n"
                    "1. Visualizar información almacenada.\n"
                    "2. Agregar información al sistema.\n"
                    "3. Modificar informacion almacenada.\n"
                    "4. Remover informacion del sistema.\n"
                    "5. Salir.\n";

        }

    public:

        static void mainMenu() {
            int selectedOption;

            do
            {
                if(selectedOption < 0 || selectedOption > 5) cout << "Ingrese una opcion valida";


                showMainMenu();
                
                cout << "Ingrese su eleccion: ";
                cin >> selectedOption;

                
            } while (selectedOption < 1 || selectedOption > 6);

            cout << "WENAAASSSSS";
            
        }

};