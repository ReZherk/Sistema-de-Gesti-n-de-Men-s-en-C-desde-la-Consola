#include <iostream> // Utilizamos la librer�a est�ndar de entrada/salida en C++ (Jose Milciades , Hurtado Sifuentes)
#include <stdio.h>  // Utilizamos la librer�a est�ndar de entrada/salida en C++ (Jose Milciades , Hurtado Sifuentes)
#include <stdlib.h> // Utilizamos la librer�a est�ndar de utilidades generales(Jose Milciades , Hurtado Sifuentes)
#include <string.h> // Utilizamos la librer�a para manejar cadenas de caracteres (Jose Milciades , Hurtado Sifuentes)

using namespace std; // Utiliza el espacio de nombres est�ndar de C++ (Jose Milciades , Hurtado Sifuentes)

// Estructura para un producto (Jose Milciades , Hurtado Sifuentes)
typedef struct Producto
{
    char nombre[50];     // Nombre del producto
    float precio;        // Precio del producto
    Producto *siguiente; // Puntero al siguiente producto en la lista
} Producto;
// Estructura para un pedido (Jose Milciades , Hurtado Sifuentes)
typedef struct Pedido
{
    Producto *productos; // Puntero al primer producto en la lista del pedido
    float total;         // Total del pedido
} Pedido;

#define TAM sizeof(Producto) // Tama�o de la estructura Producto (Jose Milciades , Hurtado Sifuentes)
#define MAX_PEDIDOS 100      // N�mero m�ximo de pedidos (Jose Milciades , Hurtado Sifuentes)

// Variables globales (Jose Milciades , Hurtado Sifuentes)
Producto *primero = 0, *ultimo = 0; // Punteros al primer y �ltimo producto de la lista
Pedido historial[MAX_PEDIDOS];      // Arreglo para almacenar el historial de pedidos
int numPedidos = 0;                 // Contador de pedidos

// Prototipo para manejar el men� y la boleta
void menuPrincipal();                                   // Prototipo para llamar al menu principal y el usuario escoga la opcion deseada(Jose Milciades , Hurtado Sifuentes)
void Agregar_Pedido();                                  // Prototipo para agregar un nuevo pedido
void menuSalchipapa();                                  // Prototipo para mostrar el men� de Salchipapas
void menuBebidas();                                     // Prototipo para mostrar el men� de Bebidas
void menuBroasters();                                   // Prototipo para mostrar el men� de Broasters
void menuLomos();                                       // Prototipo para mostrar el men� de Lomos
void menuFiletes();                                     // Prototipo para mostrar el men� de Filetes
void menuAdicionales();                                 // Prototipo para mostrar el men�s Adicionales
void menuSandwiches();                                  // Prototipo para mostrar el men� de S�ndwiches
void menuSalchibroasters();                             // Prototipo para mostrar el men� de Salchibroasters
void agregarProducto(const char *nombre, float precio); // Prototipo para agregar un producto al pedido
void Registrar_Boleta();                                // Prototipo para registrar y generar la boleta
void verHistorial();                                    // Prototipo para ver el historial de pedidos
void eliminarPedido();                                  // Prototipo para eliminar un pedido

// Funci�n principal (Jose Milciades , Hurtado Sifuentes)
int main()
{
    menuPrincipal(); // Llamada a la funci�n del men� principal (Jose Milciades , Hurtado Sifuentes)
    return 0;
}

// Funci�n para mostrar el men� principal (Jose Milciades , Hurtado Sifuentes)
void menuPrincipal()
{
    int opc; // Variable para la opci�n del men� (Jose Milciades , Hurtado Sifuentes)
    do
    {
        cout << "\nBienvenido al Restaurante huayro" << endl; // Mensaje de bienvenida (Jose Milciades , Hurtado Sifuentes)
        cout << "================================" << endl;   // Linea separadora (Jose Milciades , Hurtado Sifuentes)
        cout << "1) Agregar Pedido" << endl;                  // Opci�n para agregar un pedido (Jose Milciades , Hurtado Sifuentes)
        cout << "2) Ver Historial de Pedidos" << endl;        // Opci�n para ver el historial de pedidos (Jose Milciades , Hurtado Sifuentes)
        cout << "3) Eliminar Pedido" << endl;                 // Opci�n para eliminar un pedido (Jose Milciades , Hurtado Sifuentes)
        cout << "4) Salir" << endl;                           // Opci�n para salir del programa (Jose Milciades , Hurtado Sifuentes)
        cout << "Seleccione una opcion:" << endl;             // Solicita al usuario que seleccione una opci�n (Jose Milciades , Hurtado Sifuentes)
        cin >> opc;                                           // Ingresa el usuario una opci�n (Jose Milciades , Hurtado Sifuentes)
        cout << "==================================" << endl; // Linea separadora (Jose Milciades , Hurtado Sifuentes)
        switch (opc)
        { // Utilizamos la condicional "switch" para utilizar la "opc" seleccionada por el usuario (Jose Milciades , Hurtado Sifuentes)
        case 1:
            Agregar_Pedido(); // Llama a la funci�n para agregar un nuevo pedido (Jose Milciades , Hurtado Sifuentes)
            break;
        case 2:
            verHistorial();  // Llama a la funci�n para ver el historial de pedidos  (Jose Milciades , Hurtado Sifuentes)
            system("pause"); // Detenemos la ejecucion del programa para poder visualizar el historial  (Jose Milciades , Hurtado Sifuentes)
            break;
        case 3:
            eliminarPedido(); // Llama a la funci�n para eliminar un pedido del historial (Jose Milciades , Hurtado Sifuentes)
            system("pause");  // Detenemos la ejecucion del programa para poder visualizar el mensaje de "eliminarPedido()" (Jose Milciades , Hurtado Sifuentes)
            break;
        case 4:
            cout << "Saliendo del programa..." << endl; // Se muestra el mensaje (Jose Milciades , Hurtado Sifuentes)
            system("pause");                            // Detenemos la ejecucion del programa para poder visualizar el mensaje de "Saliendo del programa..."  (Jose Milciades , Hurtado Sifuentes)
            break;
        default:
            cout << "Opcion no valida..." << endl; // Se muestra el mensaje (Jose Milciades , Hurtado Sifuentes)
            system("pause");                       // Detenemos la ejecucion del programa para poder visualizar el mensaje de "Opcion no valida..." (Jose Milciades , Hurtado Sifuentes)
            break;
        }
        system("cls"); // Limpiamos la consola depues de utilizar las funciones (Jose Milciades , Hurtado Sifuentes)
    } while (opc != 4); // Repite hasta que el usuario elija la opcion salir  (Jose Milciades , Hurtado Sifuentes)
}
// Funci�n para mostrar Agregar_pedido (Patrick Alexander, Alcantara Sedano)
void Agregar_Pedido()
{
    int opc;
    do
    {
        cout << "\nSeleccione el tipo de comida" << endl;
        cout << "1) Salchipapa" << endl;                 // Opcion para el menu de salchipapas (Patrick Alexander, Alcantara Sedano)
        cout << "2) Bebidas" << endl;                    // Opcion para el menu de bebidas (Patrick Alexander, Alcantara Sedano)
        cout << "3) Broasters" << endl;                  // Opcion para el menu de broasters (Patrick Alexander, Alcantara Sedano)
        cout << "4) Lomos" << endl;                      // Opcion para el menu de lomos (Patrick Alexander, Alcantara Sedano)
        cout << "5) Filetes" << endl;                    // Opcion para el menu de filetes (Patrick Alexander, Alcantara Sedano)
        cout << "6) Adicionales" << endl;                // Opcion para el menu de adicionales (Patrick Alexander, Alcantara Sedano)
        cout << "7) Sandwiches" << endl;                 // Opcion para el menu de sandwiches (Patrick Alexander, Alcantara Sedano)
        cout << "8) Salchibroasters" << endl;            // Opcion para el menu de salchibroasters (Patrick Alexander, Alcantara Sedano)
        cout << "9) Registrar y Generar Pedido" << endl; // Opcion para el menu de registrar y generar pedido (Patrick Alexander, Alcantara Sedano)
        cout << "10) Volver al menu principal" << endl;  // Opcion para el volver al menu principal (Patrick Alexander, Alcantara Sedano)
        cout << "Seleccione una opcion:" << endl;        // Solicita al usuario que seleccione una opci�n (Patrick Alexander, Alcantara Sedano)
        cin >> opc;                                      // Ingresa el usuario una opci�n (Patrick Alexander, Alcantara Sedano)
        system("cls");                                   // Limpiamos la consola (Patrick Alexander, Alcantara Sedano)
        switch (opc)
        { // Estructura switch para manejar las opciones seleccionadas(Patrick Alexander, Alcantara Sedano)
        case 1:
            menuSalchipapa(); // Llama al men� de Salchipapa (Patrick Alexander, Alcantara Sedano)
            break;
        case 2:
            menuBebidas(); // Llama al men� de Bebidas (Patrick Alexander, Alcantara Sedano)
            break;
        case 3:
            menuBroasters(); // Llama al men� de Broaster (Patrick Alexander, Alcantara Sedano)
            break;
        case 4:
            menuLomos(); // Llama al men� Lomos (Patrick Alexander, Alcantara Sedano)
            break;
        case 5:
            menuFiletes(); // Llama al men� Filetes (Patrick Alexander, Alcantara Sedano)
            break;
        case 6:
            menuAdicionales(); // Llama al men� Adicionales (Patrick Alexander, Alcantara Sedano)
            break;
        case 7:
            menuSandwiches(); // Llama al men� Sandwiches (Patrick Alexander, Alcantara Sedano)
            break;
        case 8:
            menuSalchibroasters(); // Llama al men� Salchibroasters (Patrick Alexander, Alcantara Sedano)
            break;
        case 9:
            Registrar_Boleta(); // Llama a la funci�n para registrar y generar la boleta (Patrick Alexander, Alcantara Sedano)
            return;
        case 10:
            return; // Termina la funci�n y vuelve al men� principal (Patrick Alexander, Alcantara Sedano)
        default:
            cout << "Opcion no valida..." << endl; // Mensaje de error para el usuario (Patrick Alexander, Alcantara Sedano)
            break;
        }
        system("cls"); // Limpia la pantalla antes de mostrar el siguiente men� (Patrick Alexander, Alcantara Sedano)
    } while (opc != 10); // Repite el men� mientras no se seleccione la opci�n de volver al men� principal (Patrick Alexander, Alcantara Sedano)
}

void menuSalchipapa()
{            // Funci�n para mostrar el men� de Salchipapas (Patrick Alexander, Alcantara Sedano)
    int opc; // Variable para la opci�n del men� (Patrick Alexander, Alcantara Sedano)
    do
    {
        cout << "\nMenu Salchipapa" << endl;                // T�tulo del men� de Salchipapas (Patrick Alexander, Alcantara Sedano)
        cout << "1) Salchipapa Clasica - 10.00" << endl;    // Opci�n para Salchipapa Cl�sica (Patrick Alexander, Alcantara Sedano)
        cout << "2) Salchipapa a lo pobre - 13.00" << endl; // Opci�n para Salchipapa a lo pobre (Patrick Alexander, Alcantara Sedano)
        cout << "3) Salchipollo - 15.00" << endl;           // Opci�n para Salchipollo (Patrick Alexander, Alcantara Sedano)
        cout << "4) Choripapas - 15.00" << endl;            // Opci�n para Choripapas (Patrick Alexander, Alcantara Sedano)
        cout << "5) Salchipapa Mixta - 14.00" << endl;      // Opci�n para Salchipapa Mixta (Patrick Alexander, Alcantara Sedano)
        cout << "6) Salchinuggets - 19.00" << endl;         // Opci�n para Salchinuggets (Patrick Alexander, Alcantara Sedano)
        cout << "7) Volver al menu anterior" << endl;       // Opci�n para volver al men� anterior (Patrick Alexander, Alcantara Sedano)
        cout << "Seleccione una opcion:" << endl;           // Solicita al usuario que seleccione una opci�n (Patrick Alexander, Alcantara Sedano)
        cin >> opc;                                         // Lee la opci�n ingresada por el usuario (Patrick Alexander, Alcantara Sedano)

        switch (opc)
        { // Estructura switch para manejar las opciones seleccionadas (Patrick Alexander, Alcantara Sedano)
        case 1:
            agregarProducto("Salchipapa Clasica", 10.00); // Agrega Salchipapa Cl�sica al pedido (Patrick Alexander, Alcantara Sedano)
            break;
        case 2:
            agregarProducto("Salchipapa a lo pobre", 13.00); // Agrega Salchipapa a lo pobre al pedido (Patrick Alexander, Alcantara Sedano)
            break;
        case 3:
            agregarProducto("Salchipollo", 15.00); // Agrega Salchipollo al pedido (Patrick Alexander, Alcantara Sedano)
            break;
        case 4:
            agregarProducto("Choripapas", 15.00); // Agrega Choripapas al pedido (Patrick Alexander, Alcantara Sedano)
            break;
        case 5:
            agregarProducto("Salchipapa Mixta", 14.00); // Agrega Salchipapa Mixta al pedido (Patrick Alexander, Alcantara Sedano)
            break;
        case 6:
            agregarProducto("Salchinuggets", 19.00); // Agrega Salchinuggets al pedido (Patrick Alexander, Alcantara Sedano)
            break;
        case 7:
            return; // Termina la funci�n y vuelve al men� anterior (Patrick Alexander, Alcantara Sedano)
        default:
            cout << "Opcion no valida..." << endl; // Mensaje de error para opciones inv�lidas (Patrick Alexander, Alcantara Sedano)
            break;
        }

    } while (opc != 7); // Repite el men� mientras no se seleccione la opci�n de volver al men� anterior (Patrick Alexander, Alcantara Sedano)
}

void menuBebidas()
{            // Funci�n para mostrar el men� de Bebidas (Patrick Alexander, Alcantara Sedano)
    int opc; // Variable para la opci�n del men� (Patrick Alexander, Alcantara Sedano)
    do
    {
        cout << "\nMenu Bebidas" << endl;                 // T�tulo del Men� de bebidas (Patrick Alexander, Alcantara Sedano)
        cout << "1) Fanta - 3.00" << endl;                // Opci�n para Fanta (Patrick Alexander, Alcantara Sedano)
        cout << "2) Fanta Kola Inglesa - 3.00" << endl;   // Opci�n para Fanta Kola Inglesa (Patrick Alexander, Alcantara Sedano)
        cout << "3) Inca kola (vidrio) - 2.50" << endl;   // Opci�n para Inca Kola de vidrio(Patrick Alexander, Alcantara Sedano)
        cout << "4) Inca kola (plastico) - 3.50" << endl; // Opci�n para Inca Kola de pl�stico(Patrick Alexander, Alcantara Sedano)
        cout << "5) Inca Kola Gordita - 4.00" << endl;    // Opci�n para Ica Kola gordita(Patrick Alexander, Alcantara Sedano)
        cout << "6) Coca Cola Jumbo - 4.00" << endl;      // Opci�n para Coca Cola Jumbo(Patrick Alexander, Alcantara Sedano)
        cout << "7) Volver al menu anterior" << endl;     // Opci�n para volver al men�(Patrick Alexander, Alcantara Sedano)
        cout << "Seleccione una opcion:" << endl;         // Solicita al usuario que seleccione una opci�n(Patrick Alexander, Alcantara Sedano)
        cin >> opc;                                       // Lee la opci�n ingresada por el usuario (Patrick Alexander, Alcantara Sedano)

        switch (opc)
        { // Estructura switch para manejar las opciones seleccionadas(Patrick Alexander, Alcantara Sedano)
        case 1:
            agregarProducto("Fanta", 3.00); // Agrega Fanta al pedido(Patrick Alexander, Alcantara Sedano)
            break;
        case 2:
            agregarProducto("Fanta Kola Inglesa", 3.00); // Agrega Fanta Kola Inglesa al pedido(Patrick Alexander, Alcantara Sedano)
            break;
        case 3:
            agregarProducto("Inca kola (vidrio)", 2.50); // Agrega Inca Kola de vidrio al pedido(Patrick Alexander, Alcantara Sedano)
            break;
        case 4:
            agregarProducto("Inca kola (plastico)", 3.50); // Agrega Inca Kola de pl�stico al pedido(Patrick Alexander, Alcantara Sedano)
            break;
        case 5:
            agregarProducto("Inca Kola Gordita", 4.00); // Agrega Inca Kola gordita al pedido (Patrick Alexander, Alcantara Sedano)
            break;
        case 6:
            agregarProducto("Coca Cola Jumbo", 4.00); // Agrega Coca Cola Jumbo al pedido(Patrick Alexander, Alcantara Sedano)
            break;
        case 7:
            return; // Vuelve al men�(Patrick Alexander, Alcantara Sedano)
        default:
            cout << "Opcion no valida..." << endl; // Mensaje de error para opciones inv�lidas(Patrick Alexander, Alcantara Sedano)
            break;
        }

    } while (opc != 7); // Repite hasta que el usuario elija la opcion volver al men� anterior(Patrick Alexander, Alcantara Sedano)
}

void menuBroasters()
{            // Funci�n para mostrar el men� de Broasters (Patrick Alexander, Alcantara Sedano)
    int opc; // Variable para la opci�n del men� (Patrick Alexander, Alcantara Sedano)
    do
    {
        cout << "\nMenu Broasters" << endl;                // T�tulo del men� de Broasters (Patrick Alexander, Alcantara Sedano)
        cout << "1) Alita Broaster - 12.00" << endl;       // Opci�n 1: Alita Broaster con su precio (Patrick Alexander, Alcantara Sedano)
        cout << "2) Piernas Broaster - 13.50" << endl;     // Opci�n 2: Piernas Broaster con su precio (Patrick Alexander, Alcantara Sedano)
        cout << "3) Entrepierna Broaster - 13.50" << endl; // Opci�n 3: Entrepierna Broaster con su precio (Patrick Alexander, Alcantara Sedano)
        cout << "4) Pecho Broaster - 17.00" << endl;       // Opci�n 4: Pecho Broaster con su precio (Patrick Alexander, Alcantara Sedano)
        cout << "5) Volver al menu anterior" << endl;      // Opci�n 5: Volver al men� anterior (Patrick Alexander, Alcantara Sedano)
        cout << "Seleccione una opcion:" << endl;          // Solicita al usuario seleccionar una opci�n (Patrick Alexander, Alcantara Sedano)
        cin >> opc;                                        // Almacena la opci�n seleccionada por el usuario (Patrick Alexander, Alcantara Sedano)

        switch (opc)
        { // Estructura switch para manejar las opciones seleccionadas (Patrick Alexander, Alcantara Sedano)
        case 1:
            agregarProducto("Alita Broaster", 12.00); // Agrega Alita Broaster al pedido (Patrick Alexander, Alcantara Sedano)
            break;
        case 2:
            agregarProducto("Piernas Broaster", 13.50); // Agrega Piernas Broaster al pedido (Patrick Alexander, Alcantara Sedano)
            break;
        case 3:
            agregarProducto("Entrepierna Broaster", 13.50); // Agrega Entrepierna Broaster al pedido (Patrick Alexander, Alcantara Sedano)
            break;
        case 4:
            agregarProducto("Pecho Broaster", 17.00); // Agrega Pecho Broaster al pedido (Patrick Alexander, Alcantara Sedano)
            break;
        case 5:
            return; // Vuelve al men� anterior (Patrick Alexander, Alcantara Sedano)
        default:
            cout << "Opcion no valida..." << endl; // Mensaje para opci�n no v�lida (Patrick Alexander, Alcantara Sedano)
            break;
        }
    } while (opc != 5); // Repite hasta que el usuario elija la opcion volver al men� anterior (Patrick Alexander, Alcantara Sedano)
}

void menuLomos()
{            // Funci�n para mostrar el men� de Lomos (Patrick Alexander, Alcantara Sedano)
    int opc; // Variable para la opci�n del men� (Patrick Alexander, Alcantara Sedano)
    do
    {
        cout << "\nMenu Lomos" << endl;                        // T�tulo del men� de Lomos (Patrick Alexander, Alcantara Sedano)
        cout << "1) Pollo saltado clasico - 18.00" << endl;    // Opci�n para Pollo saltado cl�sico (Patrick Alexander, Alcantara Sedano)
        cout << "2) Pollo saltado a lo pobre - 21.00" << endl; // Opci�n para Pollo saltado a lo pobre  (Patrick Alexander, Alcantara Sedano)
        cout << "3) Pollo saltado con chaufa - 22.00" << endl; // Opci�n para Pollo saltado con chaufa (Patrick Alexander, Alcantara Sedano)
        cout << "4) Lomo saltado clasico - 19.00" << endl;     // Opci�n para Lomo saltado cl�sico(Patrick Alexander, Alcantara Sedano)
        cout << "5) Lomo saltado a lo pobre - 22.00" << endl;  // Opci�n para Lomo saltado a lo pobre (Patrick Alexander, Alcantara Sedano)
        cout << "6) Lomo saltado con chaufa - 23.00" << endl;  // Opci�n para Lomo saltado con chaufa (Patrick Alexander, Alcantara Sedano)
        cout << "7) Volver al menu anterior" << endl;          // Solicitar al usuario seleccionar una opci�n (Patrick Alexander, Alcantara Sedano)
        cout << "Seleccione una opcion:" << endl;              // Almacena la opci�n seleccionada por el usuario (Patrick Alexander, Alcantara Sedano)
        cin >> opc;                                            // Almacena la opci�n seleccionada por el usuario (Patrick Alexander, Alcantara Sedano)

        switch (opc)
        { // Estructura switch para manejar las opciones seleccionadas (Patrick Alexander, Alcantara Sedano)
        case 1:
            agregarProducto("Pollo saltado clasico", 18.00); // Agregar Pollo saltado cl�sico al pedido  (Patrick Alexander, Alcantara Sedano)
            break;
        case 2:
            agregarProducto("Pollo saltado a lo pobre", 21.00); // Agregar Pollo saltado a lo pobre al pedido  (Patrick Alexander, Alcantara Sedano)
            break;
        case 3:
            agregarProducto("Pollo saltado con chaufa", 22.00); // Agregar Pollo saltado con chaufa al pedido  (Patrick Alexander, Alcantara Sedano)
            break;
        case 4:
            agregarProducto("Lomo saltado clasico", 19.00); // Agregar Lomo saltado cl�sico al pedido  (Patrick Alexander, Alcantara Sedano)
            break;
        case 5:
            agregarProducto("Lomo saltado a lo pobre", 22.00); // Agregar Lomo saltado a lo pobre al pedido (Patrick Alexander, Alcantara Sedano)
            break;
        case 6:
            agregarProducto("Lomo saltado con chaufa", 23.00); // Agregar Lomo saltado con chaufa al pedido  (Patrick Alexander, Alcantara Sedano)
            break;
        case 7:
            return; // vuelva al men� anterior (Patrick Alexander, Alcantara Sedano)
        default:
            cout << "Opcion no valida..." << endl;
            break;
        }
    } while (opc != 7); // Repite hasta que el usuario elija la opcion volver al men� anterior (Patrick Alexander, Alcantara Sedano)
}

void menuFiletes()
{            // Funci�n para mostrar el men� de Filetes (Patrick Alexander, Alcantara Sedano)
    int opc; // Variable para la opci�n del men� (Patrick Alexander, Alcantara Sedano)
    do
    {
        cout << "\nMenu Filetes" << endl;                                      // T�tulo del men� de Filetes (Patrick Alexander, Alcantara Sedano)
        cout << "1) Filete a la plancha - 18.00" << endl;                      // Opci�n 1: Filete a la plancha con su precio (Patrick Alexander, Alcantara Sedano)
        cout << "2) Filete a la plancha a lo pobre - 21.00" << endl;           // Opci�n 2: Filete a la plancha a lo pobre con su precio (Patrick Alexander, Alcantara Sedano)
        cout << "3) Filete a la plancha con chaufa - 22.00" << endl;           // Opci�n 3: Filete a la plancha con chaufa con su precio (Patrick Alexander, Alcantara Sedano)
        cout << "4) Filete a la plancha de pierna deshuesada - 21.00" << endl; // Opci�n 4: Filete a la plancha de pierna deshuesada con su precio (Patrick Alexander, Alcantara Sedano)
        cout << "5) Filete a la plancha con ensalada mixta - 21.00" << endl;   // Opci�n 5: Filete a la plancha con ensalada mixta con su precio (Patrick Alexander, Alcantara Sedano)
        cout << "6) Volver al menu anterior" << endl;                          // Opci�n 6: Volver al men� anterior (Patrick Alexander, Alcantara Sedano)
        cout << "Seleccione una opcion:" << endl;                              // Solicita al usuario seleccionar una opci�n cin >> opc; // Almacena la opci�n seleccionada por el usuario (Patrick Alexander, Alcantara Sedano)
        cin >> opc;                                                            // Almacena la opci�n seleccionada por el usuario (Patrick Alexander, Alcantara Sedano)
        switch (opc)
        { // Estructura switch para manejar las opciones seleccionadas (Patrick Alexander, Alcantara Sedano)
        case 1:
            agregarProducto("Filete a la plancha", 18.00); // Agrega Filete a la plancha al pedido (Patrick Alexander, Alcantara Sedano)
            break;
        case 2:
            agregarProducto("Filete a la plancha a lo pobre", 21.00); // Agrega Filete a la plancha a lo pobre al pedido (Patrick Alexander, Alcantara Sedano)
            break;
        case 3:
            agregarProducto("Filete a la plancha con chaufa", 22.00); // Agrega Filete a la plancha con chaufa al pedido (Patrick Alexander, Alcantara Sedano)
            break;
        case 4:
            agregarProducto("Filete a la plancha de pierna deshuesada", 21.00); // Agrega Filete a la plancha de pierna deshuesada al pedido (Patrick Alexander, Alcantara Sedano)
            break;
        case 5:
            agregarProducto("Filete a la plancha con ensalada mixta", 21.00); // Agrega Filete a la plancha con ensalada mixta al pedido (Patrick Alexander, Alcantara Sedano)
            break;
        case 6:
            return; // Vuelve al men� anterior (Patrick Alexander, Alcantara Sedano)
        default:
            cout << "Opcion no valida..." << endl; // Mensaje para opci�n no v�lida (Patrick Alexander, Alcantara Sedano)
            break;
        }
    } while (opc != 6); // Repite hasta que el usuario elija la opcion volver al men� anterior (Patrick Alexander, Alcantara Sedano)
}

void menuAdicionales()
{            // Funci�n para mostrar el men� de Adicionales (Patrick Alexander, Alcantara Sedano)
    int opc; // Variable para la opci�n del men� (Patrick Alexander, Alcantara Sedano)
    do
    {
        cout << "\nMenu Adicionales" << endl;                          // T�tulo del men� de Adicionales (Patrick Alexander, Alcantara Sedano)
        cout << "1) Porcion de papas huayro - 8.00" << endl;           // Opci�n 1: Porci�n de papas huayro con su precio (Patrick Alexander, Alcantara Sedano)
        cout << "2) Pollo deshilachado o hamburguesa - 5.00" << endl;  // Opci�n 2: Pollo deshilachado o hamburguesa con su precio (Patrick Alexander, Alcantara Sedano)
        cout << "3) Chorizo - 4.00" << endl;                           // Opci�n 3: Chorizo con su precio (Patrick Alexander, Alcantara Sedano)
        cout << "4) Palta - 3.00" << endl;                             // Opci�n 4: Palta con su precio (Patrick Alexander, Alcantara Sedano)
        cout << "5) Tocino o platano o queso cheddar - 2.00" << endl;  // Opci�n 5: Tocino o pl�tano o queso cheddar con su precio (Patrick Alexander, Alcantara Sedano)
        cout << "6) Hot dog - 3.50" << endl;                           // Opci�n 6: Hot dog con su precio (Patrick Alexander, Alcantara Sedano)
        cout << "7) Jamon o Huevo o Queso Edam - 1.50" << endl;        // Opci�n 7: Jam�n o huevo o queso Edam con su precio (Patrick Alexander, Alcantara Sedano)
        cout << "8) Tequenos jamon y queso(12 unid.) - 15.00" << endl; // Opci�n 8: Teque�os jam�n y queso (12 unidades) con su precio (Patrick Alexander, Alcantara Sedano)
        cout << "9) Tequenos jamon y queso(24 unid.) - 28.00" << endl; // Opci�n 9: Teque�os jam�n y queso (24 unidades) con su precio (Patrick Alexander, Alcantara Sedano)
        cout << "10) Volver al menu anterior" << endl;                 // Opci�n 10: Volver al men� anterior (Patrick Alexander, Alcantara Sedano)
        cout << "Seleccione una opcion:" << endl;                      // Solicita al usuario seleccionar una opci�n (Patrick Alexander, Alcantara Sedano)
        cin >> opc;                                                    // Almacena la opci�n seleccionada por el usuario (Patrick Alexander, Alcantara Sedano)

        switch (opc)
        { // Estructura switch para manejar las opciones seleccionadas (Patrick Alexander, Alcantara Sedano)
        case 1:
            agregarProducto("Porcion de papas huayro", 8.00); // Agrega Porci�n de papas huayro al pedido break; (Patrick Alexander, Alcantara Sedano)
            break;
        case 2:
            agregarProducto("Pollo deshilachado o hamburguesa", 5.00); // Agrega Pollo deshilachado o hamburguesa al pedido (Patrick Alexander, Alcantara Sedano)
            break;
        case 3:
            agregarProducto("Chorizo", 4.00); // Agrega Chorizo al pedido (Patrick Alexander, Alcantara Sedano)
            break;
        case 4:
            agregarProducto("Palta", 3.00); // Agrega Palta al pedido (Patrick Alexander, Alcantara Sedano)
            break;
        case 5:
            agregarProducto("Tocino o platano o queso cheddar", 2.00); // Agrega Tocino o pl�tano o queso cheddar al pedido (Patrick Alexander, Alcantara Sedano)
            break;
        case 6:
            agregarProducto("Hot dog", 3.50); // Agrega Hot dog al pedido (Patrick Alexander, Alcantara Sedano)
            break;
        case 7:
            agregarProducto("Jamon o Huevo o Queso Edam", 1.50); // Agrega Jam�n o huevo o queso Edam al pedido (Patrick Alexander, Alcantara Sedano)
            break;
        case 8:
            agregarProducto("Tequenos jamon y queso(12 unid.)", 15.00); // Agrega Teque�os jam�n y queso (12 unidades) al pedido (Patrick Alexander, Alcantara Sedano)
            break;
        case 9:
            agregarProducto("Tequenos jamon y queso(24 unid.)", 28.00); // Agrega Teque�os jam�n y queso (24 unidades) al pedido (Patrick Alexander, Alcantara Sedano)
            break;
        case 10:
            return; // Vuelve al men� anterior (Patrick Alexander, Alcantara Sedano)
        default:
            cout << "Opcion no valida..." << endl; // Mensaje para opci�n no v�lida (Patrick Alexander, Alcantara Sedano)
            break;
        }
    } while (opc != 10); // Repite hasta que el usuario elija la opcion volver al men� anterior (Patrick Alexander, Alcantara Sedano)
}

void menuSandwiches()
{            // Funci�n para mostrar el men� de S�ndwiches (Enzo Fabian , Alva Huaranga)
    int opc; // Variable para la opci�n del men� (Enzo Fabian , Alva Huaranga)
    do
    {
        cout << "\nMenu Sandwiches" << endl;                      // T�tulo del Men� de Sandwiches (Enzo Fabian , Alva Huaranga)
        cout << "1) Sand. de pollo deshilachado - 10.00" << endl; // Opci�n para Sand. de pollo deshilachado con su precio (Enzo Fabian , Alva Huaranga)
        cout << "2) Sand. de chorizo - 10.00" << endl;            // Opci�n para Sand. de chorizo con su precio (Enzo Fabian , Alva Huaranga)
        cout << "3) Sand. de filete de pollo - 11.00" << endl;    // Opci�n para San.d de filete de pollo con su precio (Enzo Fabian , Alva Huaranga)
        cout << "4) Sand. crispy - 12.00" << endl;                // Opci�n para Sand.crispy con su precio (Enzo Fabian , Alva Huaranga)
        cout << "5) Sand. de pollo royal - 12.00" << endl;        // Opci�n para Sand. de pollo royal  con su precio (Enzo Fabian , Alva Huaranga)
        cout << "6) Volver al menu anterior" << endl;             // Opci�n para Volver al men� anterior (Enzo Fabian , Alva Huaranga)
        cout << "Seleccione una opcion:" << endl;
        ; // Solicita al usuario seleccionar una opci�n (Enzo Fabian , Alva Huaranga)
        cin >> opc;

        switch (opc)
        { // Estructura switch para manejar las opciones seleccionadas (Enzo Fabian , Alva Huaranga)
        case 1:
            agregarProducto("Sand. de pollo deshilachado", 10.00); // Agrega S�ndwich de pollo deshilachado al pedido(Enzo Fabian , Alva Huaranga)
            break;
        case 2:
            agregarProducto("Sand. de chorizo", 10.00); // Agrega S�ndwich de chorizo al pedido (Enzo Fabian , Alva Huaranga)
            break;
        case 3:
            agregarProducto("Sand. de filete de pollo", 11.00); // Agrega S�ndwich de filete de pollo al pedido (Enzo Fabian , Alva Huaranga)
            break;
        case 4:
            agregarProducto("Sand. crispy", 12.00); // Agrega S�ndwich crispy al pedido (Enzo Fabian , Alva Huaranga)
            break;
        case 5:
            agregarProducto("Sand. de pollo royal", 12.00); // Agrega S�ndwich de pollo royal al pedido (Enzo Fabian , Alva Huaranga)
            break;
        case 6:
            return; // Vuelve al men� anterior (Enzo Fabian , Alva Huaranga)
        default:
            cout << "Opcion no valida..." << endl; // Mensaje para opci�n no v�lida (Enzo Fabian , Alva Huaranga)
            break;
        }
    } while (opc != 6); // Repite hasta que el usuario elija la opcion volver al men� anterior (Enzo Fabian , Alva Huaranga)
}

void menuSalchibroasters()
{            // Funci�n para mostrar el men� de Salchibroasters (Mateo Llashag Antonio)
    int opc; // Variable para la opci�n del men� (Mateo Llashag Antonio)
    do
    {
        cout << "\nMenu Salchibroasters" << endl;              // T�tulo del men� de Salchibroasters (Mateo Llashag Antonio)
        cout << "1) Alita + Salchipapa - 17.00" << endl;       // Opci�n 1: Alita + Salchipapa con su precio (Mateo Llashag Antonio)
        cout << "2) Pierna + Salchipapa - 18.00" << endl;      // Opci�n 2: Pierna + Salchipapa con su precio (Mateo Llashag Antonio)
        cout << "3) Entrepierna + Salchipapa - 18.00" << endl; // Opci�n 3: Entrepierna + Salchipapa con su precio (Mateo Llashag Antonio)
        cout << "4) Pecho + Salchipapa - 21.00" << endl;       // Opci�n 4: Pecho + Salchipapa con su precio (Mateo Llashag Antonio)
        cout << "5) Volver al menu anterior" << endl;          // Opci�n 5: Volver al men� anterior (Mateo Llashag Antonio)
        cout << "Seleccione una opcion:" << endl;              // Solicita al usuario seleccionar una opci�n (Mateo Llashag Antonio)
        cin >> opc;                                            // Almacena la opci�n seleccionada por el usuario (Mateo Llashag Antonio)

        switch (opc)
        { // Estructura switch para manejar las opciones seleccionadas(Mateo Llashag Antonio)
        case 1:
            agregarProducto("Alita + Salchipapa", 17.00); // Agrega Alita + Salchipapa al pedido (Mateo Llashag Antonio)
            break;
        case 2:
            agregarProducto("Pierna + Salchipapa", 18.00); // Agrega Pierna + Salchipapa al pedido (Mateo Llashag Antonio)
            break;
        case 3:
            agregarProducto("Entrepierna + Salchipapa", 18.00); // Agrega Entrepierna + Salchipapa al pedido (Mateo Llashag Antonio)
            break;
        case 4:
            agregarProducto("Pecho + Salchipapa", 21.00); // Agrega Pecho + Salchipapa al pedido (Mateo Llashag Antonio)
            break;
        case 5:
            return; // Vuelve al men� anterior (Mateo Llashag Antonio)
        default:
            cout << "Opcion no valida..." << endl; // Mensaje para opci�n no v�lida (Mateo Llashag Antonio)
            break;
        }
    } while (opc != 5); // Repite hasta que el usuario elija la opcion volver al men� anterior (Mateo Llashag Antonio)
}

void agregarProducto(const char *nombre, float precio)
{
    Producto *nuevo = (Producto *)malloc(TAM); // Crear un nuevo nodo de tipo Producto en memoria din�mica (Mateo Llashag Antonio)
    strcpy(nuevo->nombre, nombre);             // Copiar el nombre del producto en el campo nombre del nuevo nodo (Mateo Llashag Antonio)
    nuevo->precio = precio;                    // Asignar el precio al campo precio del nuevo nodo (Mateo Llashag Antonio)
    nuevo->siguiente = 0;                      // Inicializar el puntero siguiente del nuevo nodo a 0 (NULL) (Mateo Llashag Antonio)

    if (primero == 0)
    {                     // Si la lista est� vac�a (primer nodo) (Mateo Llashag Antonio)
        primero = nuevo;  // Asignar el nuevo nodo como el primer nodo de la lista (Mateo Llashag Antonio)
        ultimo = primero; // Asignar el nuevo nodo como el �ltimo nodo de la lista (Mateo Llashag Antonio)
    }
    else
    {
        ultimo->siguiente = nuevo; // Enlazar el nuevo nodo al final de la lista (Mateo Llashag Antonio)
        ultimo = nuevo;            // Actualizar el �ltimo nodo para que apunte al nuevo nodo (Mateo Llashag Antonio)
    }
    cout << nombre << " agregado al pedido." << endl; // Imprimir un mensaje indicando que el producto ha sido agregado (Mateo Llashag Antonio)
}

void Registrar_Boleta()
{
    FILE *boleta = fopen("boleta.txt", "w"); // Abre un archivo para escribir la boleta (Mateo Llashag Antonio)
    Producto *p = primero;                   // Puntero al primer producto de la lista (Mateo Llashag Antonio)
    float total = 0;                         // Variable para llevar el total del precio de los productos (Mateo Llashag Antonio)

    fprintf(boleta, "Boleta de Venta\n");          // Escribe el encabezado de la boleta con el �fprintf� (Mateo Llashag Antonio)
    fprintf(boleta, "========================\n"); // Escribe una linea separadora (Mateo Llashag Antonio)

    while (p != 0)
    {                                                             // Itera sobre la lista de productos hasta que el producto este vacio (Mateo Llashag Antonio)
        fprintf(boleta, "%s - S/. %.2f\n", p->nombre, p->precio); // Escribe el nombre y precio del producto en el archivo (Mateo Llashag Antonio)
        total += p->precio;                                       // Suma el precio del producto al total (Mateo Llashag Antonio)
        p = p->siguiente;                                         // Avanza al siguiente producto en la lista (Mateo Llashag Antonio)
    }
    // Escribe una l�nea separadora y el total a pagar (Mateo Llashag Antonio)
    fprintf(boleta, "========================\n");
    fprintf(boleta, "Total a pagar: S/. %.2f\n", total);
    // Cierra el archivo (Mateo Llashag Antonio)
    fclose(boleta);
    cout << "Boleta generada exitosamente." << endl; // Informa que la boleta se ha generado exitosamente (Mateo Llashag Antonio)

    if (numPedidos < MAX_PEDIDOS)
    { // Verifica si el historial de pedidos no est� lleno (Mateo Llashag Antonio)
        // Guarda la lista de productos y el total en el historial de pedidos (Mateo Llashag Antonio)
        historial[numPedidos].productos = primero;
        historial[numPedidos].total = total;
        numPedidos++; // Incrementa el contador de pedidos (Mateo Llashag Antonio)
    }
    else
    { // Si el �numPedidos� excede a �MAX_PEDIDOS� ,informa que el historial de pedidos est� lleno (Mateo Llashag Antonio)
        cout << "Historial de pedidos lleno.\n";
    }

    primero = ultimo = 0; // Resetear la lista para un nuevo pedido (Mateo Llashag Antonio)
}

void verHistorial()
{ // Funci�n para mostrar el historial de pedidos registrados (Enzo Fabian , Alva Huaranga)
    if (numPedidos == 0)
    { // Si el numPedidos esta vacia osea es igual a 0 , mostrara en la consola que " no hay pedidos en el historial" (Enzo Fabian , Alva Huaranga)
        cout << "No hay pedidos en el historial.\n";
        return; // Sale de la funci�n si no hay pedidos(Enzo Fabian , Alva Huaranga)
    }
    cout << " ==================================" << endl; // Linea separadora (Enzo Fabian , Alva Huaranga)
    cout << "\tHISTORIAL DE PEDIDOS\n";                    // T�tulo del historial de pedidos (Enzo Fabian , Alva Huaranga)
    for (int i = 0; i < numPedidos; ++i)
    {                                           // Condicional para que me muestre todos los pedidos segun la cantidad que haya en "numPedidos" (Enzo Fabian , Alva Huaranga)
        cout << "- PEDIDO " << (i + 1) << "\n"; // Muestra el n�mero del pedido (Enzo Fabian , Alva Huaranga)
        Producto *p = historial[i].productos;   // Inicializa el puntero al producto actual como el primero del pedido  (Enzo Fabian , Alva Huaranga)
        while (p != 0)
        {                                                        // condicional que funcionara hasta que el puntero este vacio (Enzo Fabian , Alva Huaranga)
            cout << p->nombre << " - S/. " << p->precio << "\n"; // Muestra el nombre y precio del producto actual (Enzo Fabian , Alva Huaranga)
            p = p->siguiente;                                    // Avanza al siguiente producto en la lista  (Enzo Fabian , Alva Huaranga)
        }
        cout << "Total: S/. " << historial[i].total << "\n"; // Muestra el total del pedido (Enzo Fabian , Alva Huaranga)
        cout << "==================================\n";      // linea separadora (Enzo Fabian , Alva Huaranga)
    }
}

void eliminarPedido()
{ // Verifica si no hay pedidos para eliminar (Enzo Fabian , Alva Huaranga)
    if (numPedidos == 0)
    { // Si el numPedidos esta vacia osea es igual a 0 , mostrara en la consola que " no hay pedidos para eliminar" (Enzo Fabian , Alva Huaranga)
        cout << "No hay pedidos para eliminar.\n";
        return; // Sale de la funci�n si no hay pedidos(Enzo Fabian , Alva Huaranga)
    }

    int pedidoEliminar; // Solicita al usuario el n�mero del pedido a eliminar (Enzo Fabian , Alva Huaranga)
    cout << "Ingrese el numero de pedido a eliminar (1-" << numPedidos << "): ";
    cin >> pedidoEliminar;

    if (pedidoEliminar < 1 || pedidoEliminar > numPedidos)
    { // Verifica si el n�mero de pedido es v�lido (Enzo Fabian , Alva Huaranga)
        cout << "Numero de pedido invalido.\n";
        return; // Sale de la funci�n si el n�mero es inv�lido (Enzo Fabian , Alva Huaranga)
    }

    // Obtiene el primer producto del pedido a eliminar (Enzo Fabian , Alva Huaranga)
    Producto *p = historial[pedidoEliminar - 1].productos;
    while (p != 0)
    {
        Producto *temp = p; // Almacena el producto actual en una variable temporal (Enzo Fabian , Alva Huaranga)
        p = p->siguiente;   // Avanza al siguiente producto (Enzo Fabian , Alva Huaranga)
        free(temp);         // Libera la memoria del producto actual (Enzo Fabian , Alva Huaranga)
    }

    for (int i = pedidoEliminar - 1; i < numPedidos - 1; ++i)
    { // Mueve los pedidos restantes una posici�n hacia atr�s en el array (Enzo Fabian , Alva Huaranga)
        historial[i] = historial[i + 1];
    }
    numPedidos--; // Disminuye el contador de pedidos (Enzo Fabian , Alva Huaranga)

    cout << "Pedido eliminado exitosamente.\n"; // Informa al usuario que el pedido se ha eliminado con �xito (Enzo Fabian , Alva Huaranga)
}
