import java.io.*;
import java.util.Scanner;

class Biblioteca {
    private String archivo = "biblioteca.txt";

    public void registrarLibro(Scanner scanner) {
        System.out.print("Código: ");
        String cod = scanner.nextLine().trim();
        System.out.print("Título: ");
        String tit = scanner.nextLine().trim();
        System.out.print("Autor: ");
        String aut = scanner.nextLine().trim();
        System.out.print("Estado (Disponible/Prestado): ");
        String est = scanner.nextLine().trim();

        if (!est.equalsIgnoreCase("Disponible") && !est.equalsIgnoreCase("Prestado")) {
            System.out.println("Estado inválido. Usa Disponible o Prestado.");
            return;
        }

        est = est.substring(0, 1).toUpperCase() + est.substring(1).toLowerCase();

        try {
            BufferedWriter bw = new BufferedWriter(new FileWriter(archivo, true));
            bw.write(cod + " " + tit + " " + aut + " " + est + "\n");
            bw.close();
            System.out.println("Libro guardado.");
        } catch (IOException e) {
            System.out.println("Error al guardar: " + e.getMessage());
        }
    }

    public void mostrarPorEstado(String estadoBuscado) {
        try {
            BufferedReader br = new BufferedReader(new FileReader(archivo));
            String linea;
            System.out.println("\n--- Libros " + estadoBuscado + "s ---");
            while ((linea = br.readLine()) != null) {
                if (linea.contains(estadoBuscado)) {
                    System.out.println(linea);
                }
            }
            br.close();
        } catch (IOException e) {
            System.out.println("No se pudo leer el archivo (puede que esté vacío).");
        }
    }
}

public class MainBiblioteca {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Biblioteca biblio = new Biblioteca();
        int opcion = 0;

        do {
            System.out.println("\n--- Biblioteca ---");
            System.out.println("1. Registrar 2. Disponibles 3. Prestados 4. Salir");
            System.out.print("Opción: ");
            String entrada = scanner.nextLine().trim();

            try {
                opcion = Integer.parseInt(entrada);
            } catch (NumberFormatException e) {
                System.out.println("Por favor ingresa un número válido.");
                continue;
            }

            switch (opcion) {
                case 1:
                    biblio.registrarLibro(scanner);
                    break;
                case 2:
                    biblio.mostrarPorEstado("Disponible");
                    break;
                case 3:
                    biblio.mostrarPorEstado("Prestado");
                    break;
                case 4:
                    System.out.println("Saliendo...");
                    break;
                default:
                    System.out.println("Opción no válida.");
            }
        } while (opcion != 4);
        scanner.close();
    }
}
