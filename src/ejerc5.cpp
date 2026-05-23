#include <iostream>
#include <string>
#include <fstream> // Librería para el manejo de archivos

using namespace std;

class Estudiante {
private:
    string nombre;
    double nota1, nota2, nota3;
    double promedio;
    string condicion;

public:
    // Constructor
    Estudiante(string nom, double n1, double n2, double n3) {
        nombre = nom;
        nota1 = n1;
        nota2 = n2;
        nota3 = n3;
        promedio = 0.0;
        condicion = "";
    }

    // Métodos de proceso
    void calcularPromedio() {
        promedio = (nota1 + nota2 + nota3) / 3.0;
    }

    void determinarCondicion() {
        if (promedio >= 7.0) {
            condicion = "Aprobado";
        } else {
            condicion = "Reprobado";
        }
    }

    // Métodos de acceso (Getters)
    string getNombre() { return nombre; }
    double getPromedio() { return promedio; }
    string getCondicion() { return condicion; }
};

int main() {
    string nom;
    double n1, n2, n3;

    cout << "Ingrese el nombre del estudiante: ";
    getline(cin, nom);

    cout << "Ingrese la nota 1: ";
    cin >> n1;
    cout << "Ingrese la nota 2: ";
    cin >> n2;
    cout << "Ingrese la nota 3: ";
    cin >> n3;

    // Crear la instancia del objeto POO
    Estudiante est(nom, n1, n2, n3);
    est.calcularPromedio();
    est.determinarCondicion();

    // Guardar los datos en un archivo (Modo ios::app para no borrar los anteriores)
    ofstream archivo("notas_estudiantes.txt", ios::app);

    if (archivo.is_open()) {
        archivo << "Nombre: " << est.getNombre() << "\n";
        archivo << "Promedio: " << est.getPromedio() << "\n";
        archivo << "Condicion: " << est.getCondicion() << "\n";
        archivo << "----------------------\n";
        archivo.close(); // Cerrar el archivo de forma segura
        cout << "¡Datos guardados con exito en 'notas_estudiantes.txt'!" << endl;
    } else {
        cout << "Error: No se pudo abrir o crear el archivo." << endl;
    }

    return 0;
}
