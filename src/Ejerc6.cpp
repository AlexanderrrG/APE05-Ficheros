#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main() {
    int opcion;
    string nombre, fecha, estadoIngresado, estadoFinal, lineaLeida;

    do {
        cout << "=== CONTROL DE ASISTENCIA ===\n";
        cout << "1. Registrar Asistencia\n";
        cout << "2. Mostrar Historial y Contar Faltas\n";
        cout << "3. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cin.ignore(); // Limpiar el buffer de entrada para evitar saltos con getline

        switch (opcion) {
            case 1:
                cout << "Ingrese nombre del estudiante: ";
                getline(cin, nombre);
                cout << "Ingrese fecha (DD/MM/AAAA): ";
                getline(cin, fecha);

                // Validación estricta con ciclo Do-While
                do {
                    cout << "Ingrese estado (A = Asistio, F = Falto): ";
                    getline(cin, estadoIngresado);
                    if (estadoIngresado != "A" && estadoIngresado != "F") {
                        cout << "Error: Por favor ingrese unicamente 'A' o 'F'.\n";
                    }
                } while (estadoIngresado != "A" && estadoIngresado != "F");

                // Asignar palabra completa según la entrada validada
                if (estadoIngresado == "A") {
                    estadoFinal = "Asistio";
                } else {
                    estadoFinal = "Falto";
                }

                // Guardar de forma secuencial en el archivo de texto
                {
                    ofstream archivoEscritura("asistencia.txt", ios::app);
                    if (archivoEscritura.is_open()) {
                        archivoEscritura << nombre << " | " << fecha << " | " << estadoFinal << "\n";
                        archivoEscritura.close();
                        cout << "¡Asistencia registrada con exito!\n";
                    } else {
                        cout << "Error al abrir el archivo para guardar.\n";
                    }
                }
                break;

            case 2: {
                int totalFaltas = 0;
                ifstream archivoLectura("asistencia.txt");
                cout << "=== HISTORIAL DE ASISTENCIA ===\n";

                // Leer el archivo línea por línea
                if (archivoLectura.is_open()) {
                    while (getline(archivoLectura, lineaLeida)) {
                        cout << lineaLeida << endl;
                        // Contar de manera acumulativa si la línea contiene "Falto"
                        if (lineaLeida.find("Falto") != string::npos) {
                            totalFaltas++;
                        }
                    }
                    archivoLectura.close();
                    cout << "Total de faltas acumuladas: " << totalFaltas << endl;
                } else {
                    cout << "No hay registros guardados aun.\n";
                }
                break;
            }

            case 3:
                cout << "Saliendo del sistema...\n";
                break;

            default:
                cout << "Opcion invalida, intente de nuevo.\n";
        }
    } while (opcion != 3);

    return 0;
}
