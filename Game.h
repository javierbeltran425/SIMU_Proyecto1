
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
            showMainMenu();            
        }

};