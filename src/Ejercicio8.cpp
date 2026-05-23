#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Biblioteca {
private:
    string nombreArchivo;

public:
    Biblioteca(string archivo) {
        nombreArchivo = archivo;
        // Asegura que el archivo exista creándolo si no está
        ofstream archivoVerificar(nombreArchivo.c_str(), ios::app);
        archivoVerificar.close();
    }

    void registrarLibro() {
        string codigo, titulo, autor, estado;
        
        cout << "\n--- Registrar Nuevo Libro ---" << endl;
        cout << "Ingrese Codigo: "; cin >> codigo;
        cout << "Ingrese Titulo (Use-guiones-sin-espacios): "; cin >> titulo;
        cout << "Ingrese Autor (Use-guiones-sin-espacios): "; cin >> autor;
        cout << "Estado (Disponible/Prestado): "; cin >> estado;

        ofstream archivo(nombreArchivo.c_str(), ios::app);
        if (archivo.is_open()) {
            archivo << codigo << " " << titulo << " " << autor << " " << estado << endl;
            archivo.close();
            cout << "-> Libro registrado exitosamente en el archivo." << endl;
        } else {
            cout << "-> Error al abrir el archivo para escribir." << endl;
        }
    }

    void mostrarPorEstado(string estadoBuscado) {
        ifstream archivo(nombreArchivo.c_str());
        string codigo, titulo, autor, estado;
        bool encontrado = false;

        cout << "\n===================================" << endl;
        cout << "       LIBROS " << estadoBuscado << "S" << endl;
        cout << "===================================" << endl;

        if (archivo.is_open()) {
            // Lee fila por fila mapeando las columnas del archivo txt
            while (archivo >> codigo >> titulo >> autor >> estado) {
                if (estado == estadoBuscado) {
                    cout << "ID: " << codigo << " | " << titulo << " - Autor: " << autor << endl;
                    encontrado = true;
                }
            }
            archivo.close();
            
            if (!encontrado) {
                cout << "No se encontraron libros con el estado: " << estadoBuscado << endl;
            }
        } else {
            cout << "Error al abrir el archivo para lectura." << endl;
        }
        cout << "===================================" << endl;
    }
};

int main() {
    Biblioteca miBiblioteca("biblioteca.txt");
    int opcion;

    do {
        cout << "\n--- MENU BIBLIOTECA VIRTUAL ---" << endl;
        cout << "1. Registrar Libro" << endl;
        cout << "2. Mostrar Libros Disponibles" << endl;
        cout << "3. Mostrar Libros Prestados" << endl;
        cout << "4. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                miBiblioteca.registrarLibro();
                break;
            case 2:
                miBiblioteca.mostrarPorEstado("Disponible");
                break;
            case 3:
                miBiblioteca.mostrarPorEstado("Prestado");
                break;
            case 4:
                cout << "Saliendo del sistema de biblioteca..." << endl;
                break;
            default:
                cout << "Opcion invalida. Intente de nuevo." << endl;
        }
    } while (opcion != 4);

    return 0;
}
