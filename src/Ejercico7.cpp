#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Cajero {
private:
    string usuario;
    float saldo;
    string nombreArchivo;

    void cargarDatos() {
        ifstream archivo(nombreArchivo.c_str());
        if (archivo.is_open()) {
            archivo >> usuario >> saldo;
            archivo.close();
        } else {
            // Valores por defecto si no existe el archivo
            usuario = "Estudiante";
            saldo = 0.0;
        }
    }

    void guardarDatos() {
        ofstream archivo(nombreArchivo.c_str());
        archivo << usuario << endl;
        archivo << saldo << endl;
        archivo.close();
    }

public:
    Cajero(string u, string archivo) {
        usuario = u;
        nombreArchivo = archivo;
        cargarDatos();
    }

    void consultarSaldo() {
        cout << "Usuario: " << usuario << " | Saldo actual: $" << saldo << endl;
    }

    void depositar(float monto) {
        if (monto > 0) {
            saldo += monto;
            guardarDatos();
            cout << "Deposito exitoso." << endl;
        } else {
            cout << "Monto invalido." << endl;
        }
    }

    void retirar(float monto) {
        if (monto > 0 && monto <= saldo) {
            saldo -= monto;
            guardarDatos();
            cout << "Retiro exitoso." << endl;
        } else {
            cout << "Fondos insuficientes o monto invalido." << endl;
        }
    }
};

int main() {
    Cajero miCajero("Alexander", "cajero.txt");
    int opcion;
    float monto;

    do {
        cout << "\n--- Cajero Automatico ---" << endl;
        cout << "1. Consultar saldo" << endl;
        cout << "2. Depositar dinero" << endl;
        cout << "3. Retirar dinero" << endl;
        cout << "4. Salir" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                miCajero.consultarSaldo();
                break;
            case 2:
                cout << "Ingrese monto a depositar: ";
                cin >> monto;
                miCajero.depositar(monto);
                break;
            case 3:
                cout << "Ingrese monto a retirar: ";
                cin >> monto;
                miCajero.retirar(monto);
                break;
            case 4:
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Opcion no valida." << endl;
        }
    } while (opcion != 4);

    return 0;
}
