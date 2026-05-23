import java.io.*;
import java.util.Scanner;
 
// clase Venta
class Venta {
    private String producto;
    private int cantidad;
    private double precio;
    private double total;
 
    // constructor
    public Venta(String producto, int cantidad, double precio) {
        this.producto = producto;
        this.cantidad = cantidad;
        this.precio = precio;
        calcularTotal();
    }
 
    // metodo para calcular total
    private void calcularTotal() {
        this.total = this.cantidad * this.precio;
    }
 
    // metodo generar factura
    public void generarFactura() {
        System.out.println("\n--- FACTURA ---");
        System.out.println("Producto: " + producto);
        System.out.println("Cantidad: " + cantidad);
        System.out.println("Precio un.: $" + precio);
        System.out.println("Total: $" + total);
        System.out.println("---------------");
    }
 
    // metodo guardar en txt
    public void guardarEnArchivo() {
        try (FileWriter fw = new FileWriter("ventas.txt", true);
             PrintWriter pw = new PrintWriter(fw)) {
            pw.println(producto + " | Cant: " + cantidad + " | Precio: $" + precio + " | Total: $" + total);
            System.out.println("Venta guardada exitosamente en ventas.txt");
        } catch (IOException e) {
            System.out.println("Error al guardar en el archivo: " + e.getMessage());
        }
    }
}
 
// clase Principal y de Gestión
public class Ejercicio9 {
    private Scanner scanner;
 
    public Ejercicio9() {
        scanner = new Scanner(System.in);
    }
 
    // metodo para registrar venta validando
    public void registrarVenta() {
        System.out.print("\nIngrese nombre del producto: ");
        String prod = scanner.nextLine();
 
        int cant = 0;
        double prec = 0;
 
        // validacion cantidad
        while (true) {
            System.out.print("Ingrese cantidad (> 0): ");
            try {
                cant = Integer.parseInt(scanner.nextLine());
                if (cant > 0) break;
                System.out.println("Error: La cantidad debe ser positiva.");
            } catch (NumberFormatException e) {
                System.out.println("Error: Ingrese un número entero válido.");
            }
        }
 
        // validacion precio
        while (true) {
            System.out.print("Ingrese precio (> 0): ");
            try {
                prec = Double.parseDouble(scanner.nextLine());
                if (prec > 0) break;
                System.out.println("Error: El precio debe ser positivo.");
            } catch (NumberFormatException e) {
                System.out.println("Error: Ingrese un número decimal válido.");
            }
        }
 
        // crear objeto y ejecutar métodos
        Venta nuevaVenta = new Venta(prod, cant, prec);
        nuevaVenta.generarFactura();
        nuevaVenta.guardarEnArchivo();
    }
 
    // metodo para mostrar historial
    public void mostrarHistorial() {
        System.out.println("\n=== HISTORIAL DE VENTAS ===");
        File archivo = new File("ventas.txt");
        if (archivo.exists()) {
            try (BufferedReader br = new BufferedReader(new FileReader(archivo))) {
                String linea;
                while ((linea = br.readLine()) != null) {
                    System.out.println(linea);
                }
            } catch (IOException e) {
                System.out.println("Error al leer el archivo.");
            }
        } else {
            System.out.println("No hay ventas registradas.");
        }
        System.out.println("===========================");
    }
 
    // Menu
    public void iniciarMenu() {
        int opcion = 0;
        do {
            System.out.println("\n1. Registrar Venta");
            System.out.println("2. Ver Historial");
            System.out.println("3. Salir");
            System.out.print("Elija opción: ");
             
            try {
                opcion = Integer.parseInt(scanner.nextLine());
            } catch (NumberFormatException e) {
                opcion = 0;
            }
 
            switch (opcion) {
                case 1: registrarVenta(); break;
                case 2: mostrarHistorial(); break;
                case 3: System.out.println("Saliendo..."); break;
                default: System.out.println("Opción inválida.");
            }
        } while (opcion != 3);
    }
 
    public static void main(String[] args) {
        Ejercicio9 sistema = new Ejercicio9();
        sistema.iniciarMenu();
    }
}