#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
 
using namespace std;
 
// Clase Entidad
class Usuario {
public:
    string id;
    string nombre;
    int edad;
 
    Usuario(string i, string n, int e) : id(i), nombre(n), edad(e) {}
};
 
// Clase Gestor
class GestorCRUD {
private:
    string nombreArchivo = "usuarios.txt";
 
    // metodo privado para cargar datos a memoria
    vector<Usuario> cargarDatos() {
        vector<Usuario> lista;
        ifstream archivo(nombreArchivo);
        string linea, id, nombre, edadStr;
 
        if (archivo.is_open()) {
            while (getline(archivo, linea)) {
                stringstream ss(linea);
                getline(ss, id, ',');
                getline(ss, nombre, ',');
                getline(ss, edadStr, ',');
                if (!id.empty()) {
                    lista.push_back(Usuario(id, nombre, stoi(edadStr)));
                }
            }
            archivo.close();
        }
        return lista;
    }
 
    // metodo privado para sobrescribir el archivo
    void guardarTodos(vector<Usuario>& lista) {
        ofstream archivo(nombreArchivo, ios::trunc); // trunc borra y reescribe
        for (auto& u : lista) {
            archivo << u.id << "," << u.nombre << "," << u.edad << "
";
        }
        archivo.close();
    }
 
public:
    void crear() {
        string id, nombre;
        int edad;
        cout << "Ingrese ID: "; cin >> id;
        cin.ignore();
        cout << "Ingrese Nombre: "; getline(cin, nombre);
         
        do {
            cout << "Ingrese Edad (>0): "; cin >> edad;
        } while (edad <= 0);
 
        ofstream archivo(nombreArchivo, ios::app);
        archivo << id << "," << nombre << "," << edad << "
";
        archivo.close();
        cout << "Usuario creado.
";
    }
 
    void leer() {
        vector<Usuario> lista = cargarDatos();
        if (lista.empty()) {
            cout << "No hay registros.
";
            return;
        }
        cout << "
--- LISTA DE USUARIOS ---
";
        for (auto& u : lista) {
            cout << "ID: " << u.id << " | Nombre: " << u.nombre << " | Edad: " << u.edad << "
";
        }
    }
 
    void actualizar() {
        string idBuscar;
        cout << "Ingrese ID a actualizar: "; cin >> idBuscar;
         
        vector<Usuario> lista = cargarDatos();
        bool encontrado = false;
 
        for (auto& u : lista) {
            if (u.id == idBuscar) {
                cin.ignore();
                cout << "Nuevo Nombre: "; getline(cin, u.nombre);
                do {
                    cout << "Nueva Edad (>0): "; cin >> u.edad;
                } while (u.edad <= 0);
                encontrado = true;
                break;
            }
        }
 
        if (encontrado) {
            guardarTodos(lista);
            cout << "Usuario actualizado.
";
        } else {
            cout << "ID no encontrado.
";
        }
    }
 
    void eliminar() {
        string idBuscar;
        cout << "Ingrese ID a eliminar: "; cin >> idBuscar;
         
        vector<Usuario> lista = cargarDatos();
        vector<Usuario> nuevaLista;
        bool encontrado = false;
 
        for (auto& u : lista) {
            if (u.id != idBuscar) {
                nuevaLista.push_back(u);
            } else {
                encontrado = true;
            }
        }
 
        if (encontrado) {
            guardarTodos(nuevaLista);
            cout << "Usuario eliminado.
";
        } else {
            cout << "ID no encontrado.
";
        }
    }
};
 
int main() {
    GestorCRUD gestor;
    int opcion;
 
    do {
        cout << "
=== SISTEMA CRUD ===" << endl;
        cout << "Desarrollador: Alejandro" << endl;
        cout << "1. Crear
2. Leer
3. Actualizar
4. Eliminar
5. Salir
Opcion: ";
        cin >> opcion;
 
        switch (opcion) {
            case 1: gestor.crear(); break;
            case 2: gestor.leer(); break;
            case 3: gestor.actualizar(); break;
            case 4: gestor.eliminar(); break;
            case 5: cout << "Saliendo...
"; break;
            default: cout << "Opcion invalida.
";
        }
    } while (opcion != 5);
 
    return 0;
}