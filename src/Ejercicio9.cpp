#include <iostream>
#include <fstream>
#include <string>
#include <limits>
 
using namespace std;
 
// clase Venta
class Venta {
private:
    string producto;
    int cantidad;
    double precio;
    double total;
 
public:
    // constructor
    Venta(string prod, int cant, double prec) {
        producto = prod;
        cantidad = cant;
        precio = prec;
        calcularTotal();
    }
 
    // metodo calcular el total
    void calcularTotal() {
        total = cantidad * precio;
    }
 
    // metodo para generar y mostrar la factura
    void generarFactura() {
        cout << "\n--- FACTURA ---" << endl;
        cout << "Producto: " << producto << endl;
        cout << "Cantidad: " << cantidad << endl;
        cout << "Precio un.: $" << precio << endl;
        cout << "Total: $" << total << endl;
        cout << "---------------" << endl;
    }
 
    // metodo guardar en archivo .txt
    void guardarEnArchivo() {
        ofstream archivo("ventas.txt", ios::app); // Abrir en modo append
        if (archivo.is_open()) {
            archivo << producto << " | Cant: " << cantidad << " | Precio: $" << precio << " | Total: $" << total << "\n";
            archivo.close();
            cout << "Venta guardada exitosamente en ventas.txt\n";
        } else {
            cout << "Error al abrir el archivo.\n";
        }
    }
};
 
// Clase Gestor
class SistemaVentas {
public:
    // registrar y validar datos
    void registrarVenta() {
        string prod;
        int cant;
        double prec;
 
        cout << "\nIngrese nombre del producto: ";
        cin.ignore();
        getline(cin, prod);
 
        // validación de cantidad
        cout << "Ingrese cantidad: ";
        while (!(cin >> cant) || cant <= 0) {
            cout << "Error. Ingrese una cantidad valida (> 0): ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
 
        // validación de precio
        cout << "Ingrese precio: ";
        while (!(cin >> prec) || prec <= 0) {
            cout << "Error. Ingrese un precio valido (> 0): ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
 
        // instanciar objeto
        Venta nuevaVenta(prod, cant, prec);
        nuevaVenta.generarFactura();
        nuevaVenta.guardarEnArchivo();
    }
 
    // mostrar historial leyendo el .txt
    void mostrarHistorial() {
        string linea;
        ifstream archivo("ventas.txt");
 
        cout << "\n=== HISTORIAL DE VENTAS ===" << endl;
        if (archivo.is_open()) {
            while (getline(archivo, linea)) {
                cout << linea << endl;
            }
            archivo.close();
        } else {
            cout << "No hay ventas registradas o no se pudo abrir el archivo." << endl;
        }
        cout << "===========================\n";
    }
 
    // Menu
    void iniciarMenu() {
        int opcion;
        do {
            cout << "\n1. Registrar Venta\n2. Ver Historial\n3. Salir\nElija opcion: ";
            if (!(cin >> opcion)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                opcion = 0;
            }
 
            switch (opcion) {
                case 1: registrarVenta(); break;
                case 2: mostrarHistorial(); break;
                case 3: cout << "Saliendo...\n"; break;
                default: cout << "Opcion invalida.\n";
            }
        } while (opcion != 3);
    }
};
 
int main()
{
    SistemaVentas sistema;
    sistema.iniciarMenu();
    return 0;
}