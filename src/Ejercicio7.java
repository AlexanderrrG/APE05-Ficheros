import java.io.*;
import java.util.Scanner;

class Cajero {
    private String usuario;
    private double saldo;
    private String nombreArchivo = "cajeroj.txt";

    public Cajero(String usuario) {
        this.usuario = usuario;
        cargarDatos();
    }

    private void cargarDatos() {
        try {
            File archivo = new File(nombreArchivo);
            if (archivo.exists()) {
                BufferedReader br = new BufferedReader(new FileReader(archivo));
                this.usuario = br.readLine();
                this.saldo = Double.parseDouble(br.readLine());
                br.close();
            } else {
                this.saldo = 0.0;
            }
        } catch (Exception e) {
            System.out.println("Error al cargar datos.");
        }
    }

    private void guardarDatos() {
        try {
            BufferedWriter bw = new BufferedWriter(new FileWriter(nombreArchivo));
            bw.write(this.usuario + "\n");
            bw.write(this.saldo + "\n");
            bw.close();
        } catch (Exception e) {
            System.out.println("Error al guardar datos.");
        }
    }

    public void consultarSaldo() {
        System.out.println("Usuario: " + usuario + " | Saldo: $" + saldo);
    }

    public void depositar(double monto) {
        if (monto > 0) {
            saldo += monto;
            guardarDatos();
            System.out.println("Depósito exitoso.");
        }
    }

    public void retirar(double monto) {
        if (monto > 0 && monto <= saldo) {
            saldo -= monto;
            guardarDatos();
            System.out.println("Retiro exitoso.");
        } else {
            System.out.println("Fondos insuficientes.");
        }
    }
}

public class cajerosim {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Ingrese nombre de usuario: ");
        String nombre = scanner.nextLine();
        Cajero miCajero = new Cajero(nombre);
        int opcion;

        do {
            System.out.println("\n--- Cajero ---");
            System.out.println("1. Consultar 2. Depositar 3. Retirar 4. Salir");
            System.out.print("Opcion: ");
            opcion = scanner.nextInt();

            switch (opcion) {
                case 1: miCajero.consultarSaldo(); break;
                case 2:
                    System.out.print("Monto a depositar: ");
                    miCajero.depositar(scanner.nextDouble());
                    break;
                case 3:
                    System.out.print("Monto a retirar: ");
                    miCajero.retirar(scanner.nextDouble());
                    break;
            }
        } while (opcion != 4);
        scanner.close();
    }
}
